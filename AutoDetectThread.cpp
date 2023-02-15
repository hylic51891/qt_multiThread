#include "AutoDetectThread.h"

AutoDetectThread::AutoDetectThread(QObject* parent) :QObject(parent)
{
    qDebug() << "AutoDetectThread()";

    start = 1;
    //��������߳���Ϊ4��һ���̳߳�
    detectPool.setMaxThreadCount(4);

    // ��autodetectflag��timeevent
    timerId_PLC = startTimer(1000/20);
    waittime = 0;

    
    ////��ʼ��modbus PLC����
    //pmbs_ctx = modbus_new_tcp(PLCconnect::ip, PLCconnect::port);
    //TCPconnect(&pmbs_ctx); //������λ��

    //��ʼ���������

    //ģ��
    AutoDetectGlobalVarite::ChipDetectNum = 8;

}
AutoDetectThread::~AutoDetectThread()
{
    qDebug() << "~AutoDetectThread()";
}

//�ȴ� AutoDetectGlobalVarite::AutoFlag ��0���ź�ֹͣ�Զ����
void AutoDetectThread::slot_stop() {
    start = 0;
}

void AutoDetectThread::slot_doAutoDetect()
{

    emit sendMegToMain("��ʼ�Զ�����߳�");
    //QThread::msleep(2000); // ģ��ȴ�PLC�����ź�

    int contentadd = 10;
    for (;;)
    {
        if (start == 1)//��־λ=1��ѭ��ִ�к�ʱ����
        {
            AutoDetectGlobalVarite::ChipDetectInit(); //ÿ��ѭ������Chip�Ĳ���
            detectworks.clear(); // ��������߳�

            // ѭ�� ��оƬ����־λ = 1
            waitfor_chipstart();    
            if (start == 0) break; // ��־λΪ0 ��ʱbreak;
            //�������ʾ�߳�
            emit sig_ResultDealstart(); 
            // ѭ�� ���ȡͼģ��
            chipdetect(contentadd);
            // �Ƚ����ʾ�߳�ָʾ����
            waitfor_chipend();  
            if (start == 0) break; // ��־λΪ0 ��ʱbreak;
            // ģ����PLC�������ź�
            
            // ��ǰоƬ��������ģ���־λдΪ0
            PLCconnect::ReadWriteLock->lockForWrite();
            PLCconnect::tab_reg[0] = 0;
            PLCconnect::ReadWriteLock->unlock();
            // debug

            contentadd += AutoDetectGlobalVarite::ChipDetectNum;
        }

        else//��־λ=0������ѭ�����߳�ִ�н���
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
        if (start == 0 ) break; // ��־λΪ0 ��ʱbreak;
        AutoDetectGlobalVarite::ReadWriteLock->lockForRead();
        bool ChipStartFlag = AutoDetectGlobalVarite::ChipStartFlag;
        AutoDetectGlobalVarite::ReadWriteLock->unlock();
        if (ChipStartFlag) break;
        // ˢ��
        QTime t;
        t.start();
        while (t.elapsed() < 50) {
            QCoreApplication::processEvents();
        }
        //QThread::msleep(50); //ÿ���50ms���һ��
    }

    emit sendMegToMain("�յ�PLC��ʼ�ź�,��ʼ��ǰоƬ���");
}

void AutoDetectThread::waitfor_chipend()
{
    while (1) {
        if (start == 0) break; // ��־λΪ0 ��ʱbreak;
        AutoDetectGlobalVarite::ReadWriteLock->lockForRead();
        bool ChipEndFlag = AutoDetectGlobalVarite::ChipEndFlag;
        AutoDetectGlobalVarite::ReadWriteLock->unlock();
        if (ChipEndFlag) break;
        // ˢ��
        QTime t;
        t.start();
        while (t.elapsed() < 50) {
            QCoreApplication::processEvents();
        }
        //QThread::msleep(50); //ÿ���50ms���һ��
    }

    emit sendMegToMain("������ǰоƬ���");
}

void AutoDetectThread::chipdetect(int content)
{
    for (int i = 0; i < AutoDetectGlobalVarite::ChipDetectNum; ++i) {
        //���ȡһ��ͼ,��i��ͼƬ
        QString meg = "ģ�����ȡͼ��" + QString::number(i) + "�ţ�����Ϊ" + QString::number(i + content);
        emit sendMegToMain(meg);

        detectworks.push_back(new DetectThread());
        //DetectThread* detectwork = new DetectThread();
        if (detectworks[i]->init(i, i + content)) {
            detectPool.start(detectworks[i]);
        }
        emit sendMegToMain(QString::number(detectPool.activeThreadCount()));
    }
}

// timerEvent����д����Ҫ��������ʱ��
void AutoDetectThread::timerEvent(QTimerEvent* ev)
{
    if (ev->timerId() == timerId_PLC) {
        PLCconnect::ReadWriteLock->lockForWrite();
        //TCPread(pmbs_ctx, 700, 10, tab_reg); // ���ź�
        AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
        if (PLCconnect::tab_reg[0] == 1 && AutoDetectGlobalVarite::ChipStartFlag == 0) {
            AutoDetectGlobalVarite::ChipStartFlag = 1;
        }
        AutoDetectGlobalVarite::ReadWriteLock->unlock();
        PLCconnect::ReadWriteLock->unlock();
       
        //if ( PLCconnect::tab_reg[0] == 1 )
        //{
        //
        //    killTimer(timerId_PLC); //ֹͣˢ��PLC
        //    AutoDetectGlobalVarite::ChipStartFlag = 1;
        //}

        // debug
        // ��2���ӣ�ģ����յ���ʼ�ź�
        //waittime++;
        //emit sendMegToMain("�ȴ�PLC����ʼ�ź�," + QString::number(waittime));
        //if (waittime == 40) {

        //    AutoDetectGlobalVarite::ChipStartFlag = 1;
        //    killTimer(timerId_PLC); //ֹͣˢ��PLC
        //}

    }
}