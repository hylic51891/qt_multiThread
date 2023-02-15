#include "test_multiThreading.h"

test_multiThreading::test_multiThreading(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// 自动检测线程初始化 movetothread方法
	m_AutoDetectThread = new AutoDetectThread();
	m_pthread = new QThread();
	m_AutoDetectThread->moveToThread(m_pthread);
	qDebug() << "start,thread id = " << QThread::currentThreadId();
	// 连接槽函数
	connect(m_pthread, &QThread::finished, m_AutoDetectThread, &QObject::deleteLater);
	connect(this, SIGNAL(sig_doAutoDetect()), m_AutoDetectThread, SLOT(slot_doAutoDetect())); // 线程主函数
	connect(m_AutoDetectThread, SIGNAL(sig_finish()), this, SLOT(slot_finish()));
	connect(m_AutoDetectThread, SIGNAL(sendMegToMain(QString)), this, SLOT(slot_recMegFromAutoDetectThread(QString)));

	// 结果响应线程 movetothread方法
	m_ResultDealThread = new ResultDealThread();
	m_pthread2 = new QThread();
	m_ResultDealThread->moveToThread(m_pthread2);
	qDebug() << "start,thread id = " << QThread::currentThreadId();
	// 连接槽函数
	connect(m_pthread2, &QThread::finished, m_ResultDealThread, &QObject::deleteLater);
	connect(this, SIGNAL(sig_doResultDeal()), m_ResultDealThread, SLOT(slot_doResultDeal()));
	connect(m_ResultDealThread, SIGNAL(sendMegToMain(QString)), this, SLOT(slot_recMegFromResultDealThread(QString)));
	qRegisterMetaType<test_structure>("test_structure");
	connect(m_ResultDealThread, SIGNAL(sendResultToMain(test_structure)), this, SLOT(slot_recResultFromResultDealThread(test_structure)));

	// 结果响应线程&自动检测线程
	//connect(m_AutoDetectThread, SIGNAL(sig_ResultDealstart()), m_ResultDealThread, SLOT(slot_chipstart()));
	
	ui.textBrowser->append("初始化");
	ui.result_textBrowser->append("等待结果");
}

test_multiThreading::~test_multiThreading() {
	m_AutoDetectThread->start = 0;
	m_pthread->quit();
	m_pthread->wait();

	m_ResultDealThread->start = 0;
	m_pthread2->quit();
	m_pthread2->wait();
}

//测试多线程逻辑
void test_multiThreading::on_StartAutoDetectButton_clicked()
{
	AutoDetectGlobalVarite::AutoDetectInit();
	AutoDetectGlobalVarite::ChipDetectInit();

	/* 点击按钮，开始自动检测 */
	AutoDetectGlobalVarite::AutoFlag = 1; // 修改全局变量

	//! 检测是否符合条件
	//! 
	//!
	 
	//开始结果处理线程
	m_pthread2->start();
	emit sig_doResultDeal();

	//开始自动检测线程
	m_pthread->start();
	emit sig_doAutoDetect();

}	

void test_multiThreading::on_StopAutoDetectButton_clicked()
{
	/* 点击按钮，关闭自动检测 */
	AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
	AutoDetectGlobalVarite::AutoFlag = 0;
	AutoDetectGlobalVarite::ReadWriteLock->unlock();
}

void test_multiThreading::on_PLCstartButton_clicked()
{
	PLCconnect::ReadWriteLock->lockForWrite();
	PLCconnect::tab_reg[0] = 1;
	PLCconnect::ReadWriteLock->unlock();
}

void test_multiThreading::slot_finish()
{
	qDebug() << "自动检测线程退出,thread id = " << QThread::currentThreadId();
}

void test_multiThreading::slot_recMegFromAutoDetectThread(QString str)
{
	ui.textBrowser->append(str);
}

void test_multiThreading::slot_recMegFromResultDealThread(QString str)
{
	ui.result_textBrowser->append(str);
}

void test_multiThreading::slot_recResultFromResultDealThread(test_structure show_result)
{
	ui.textBrowser->append("调用了show_result函数"+ QString::number(show_result.sequence_number));
	ui.result_textBrowser->append(QString::number(show_result.sequence_number));
	ui.result_textBrowser->append(QString::number(show_result.content));
}