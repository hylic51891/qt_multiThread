#include "AutoDetectThread.h"

AutoDetectThread::AutoDetectThread(QObject* parent) :QObject(parent)
{
    qDebug() << "AutoDetectThread()";

    start = 1;
    //设置最大线程数为4的一个线程池
    detectPool.setMaxThreadCount(4);

    // 开autodetectflag的timeevent
    timerId_PLC = startTimer(1000/20);
    waittime = 0;

    
    ////初始化modbus PLC连接
    //pmbs_ctx = modbus_new_tcp(PLCconnect::ip, PLCconnect::port);
    //TCPconnect(&pmbs_ctx); //连接下位机

    //初始化相机连接

    //模拟
    AutoDetectGlobalVarite::ChipDetectNum = 8;

}
AutoDetectThread::~AutoDetectThread()
{
    qDebug() << "~AutoDetectThread()";
}

//等待 AutoDetectGlobalVarite::AutoFlag 变0发信号停止自动检测
void AutoDetectThread::slot_stop() {
    start = 0;
}

void AutoDetectThread::slot_doAutoDetect()
{

    emit sendMegToMain("开始自动检测线程");
    //QThread::msleep(2000); // 模拟等待PLC发出信号

    int contentadd = 10;
    for (;;)
    {
        if (start == 1)//标志位=1，循环执行耗时函数
        {
            AutoDetectGlobalVarite::ChipDetectInit(); //每次循环重置Chip的参数
            detectworks.clear(); // 清空任务线程

            // 循环 等芯片检测标志位 = 1
            waitfor_chipstart();    
            if (start == 0) break; // 标志位为0 随时break;
            //开结果显示线程
            emit sig_ResultDealstart(); 
            // 循环 相机取图模拟
            chipdetect(contentadd);
            // 等结果显示线程指示做完
            waitfor_chipend();  
            if (start == 0) break; // 标志位为0 随时break;
            // 模拟向PLC发结束信号
            
            // 当前芯片检测结束，模拟标志位写为0
            PLCconnect::ReadWriteLock->lockForWrite();
            PLCconnect::tab_reg[0] = 0;
            PLCconnect::ReadWriteLock->unlock();
            // debug

            contentadd += AutoDetectGlobalVarite::ChipDetectNum;
        }

        else//标志位=0，跳出循环，线程执行结束
        {
            break;
        }
    }

    qDebug() << "doAutoDetectstop,thread id = " << QThread::currentThreadId();

    //int i = 0;
    //while (i++ < 10)
    //{
    //    qDebug() << "this is time for:" << i;
    //    QThread::msleep(20);
    //}
    emit sig_finish();
}

void AutoDetectThread::waitfor_chipstart()
{
    while (1) {
        if (start == 0 ) break; // 标志位为0 随时break;
        AutoDetectGlobalVarite::ReadWriteLock->lockForRead();
        bool ChipStartFlag = AutoDetectGlobalVarite::ChipStartFlag;
        AutoDetectGlobalVarite::ReadWriteLock->unlock();
        if (ChipStartFlag) break;
        // 刷新
        QTime t;
        t.start();
        while (t.elapsed() < 50) {
            QCoreApplication::processEvents();
        }
        //QThread::msleep(50); //每间隔50ms检测一次
    }

    emit sendMegToMain("收到PLC开始信号,开始当前芯片检测");
}

void AutoDetectThread::waitfor_chipend()
{
    while (1) {
        if (start == 0) break; // 标志位为0 随时break;
        AutoDetectGlobalVarite::ReadWriteLock->lockForRead();
        bool ChipEndFlag = AutoDetectGlobalVarite::ChipEndFlag;
        AutoDetectGlobalVarite::ReadWriteLock->unlock();
        if (ChipEndFlag) break;
        // 刷新
        QTime t;
        t.start();
        while (t.elapsed() < 50) {
            QCoreApplication::processEvents();
        }
        //QThread::msleep(50); //每间隔50ms检测一次
    }

    emit sendMegToMain("结束当前芯片检测");
}

void AutoDetectThread::chipdetect(int content)
{
    for (int i = 0; i < AutoDetectGlobalVarite::ChipDetectNum; ++i) {
        //相机取一张图,第i张图片
        QString meg = "模拟相机取图第" + QString::number(i) + "张，内容为" + QString::number(i + content);
        emit sendMegToMain(meg);

        detectworks.push_back(new DetectThread());
        //DetectThread* detectwork = new DetectThread();
        if (detectworks[i]->init(i, i + content)) {
            detectPool.start(detectworks[i]);
        }
        emit sendMegToMain(QString::number(detectPool.activeThreadCount()));
    }
}

// timerEvent的重写，需要设置启动时机
void AutoDetectThread::timerEvent(QTimerEvent* ev)
{
    if (ev->timerId() == timerId_PLC) {
        PLCconnect::ReadWriteLock->lockForWrite();
        //TCPread(pmbs_ctx, 700, 10, tab_reg); // 读信号
        AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
        if (PLCconnect::tab_reg[0] == 1 && AutoDetectGlobalVarite::ChipStartFlag == 0) {
            AutoDetectGlobalVarite::ChipStartFlag = 1;
        }
        AutoDetectGlobalVarite::ReadWriteLock->unlock();
        PLCconnect::ReadWriteLock->unlock();
       
        //if ( PLCconnect::tab_reg[0] == 1 )
        //{
        //
        //    killTimer(timerId_PLC); //停止刷新PLC
        //    AutoDetectGlobalVarite::ChipStartFlag = 1;
        //}

        // debug
        // 等2秒钟，模拟接收到开始信号
        //waittime++;
        //emit sendMegToMain("等待PLC发开始信号," + QString::number(waittime));
        //if (waittime == 40) {

        //    AutoDetectGlobalVarite::ChipStartFlag = 1;
        //    killTimer(timerId_PLC); //停止刷新PLC
        //}

    }
}