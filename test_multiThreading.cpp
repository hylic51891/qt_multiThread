#include "test_multiThreading.h"

test_multiThreading::test_multiThreading(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// �Զ�����̳߳�ʼ�� movetothread����
	m_AutoDetectThread = new AutoDetectThread();
	m_pthread = new QThread();
	m_AutoDetectThread->moveToThread(m_pthread);
	qDebug() << "start,thread id = " << QThread::currentThreadId();
	// ���Ӳۺ���
	connect(m_pthread, &QThread::finished, m_AutoDetectThread, &QObject::deleteLater);
	connect(this, SIGNAL(sig_doAutoDetect()), m_AutoDetectThread, SLOT(slot_doAutoDetect())); // �߳�������
	connect(m_AutoDetectThread, SIGNAL(sig_finish()), this, SLOT(slot_finish()));
	connect(m_AutoDetectThread, SIGNAL(sendMegToMain(QString)), this, SLOT(slot_recMegFromAutoDetectThread(QString)));

	// �����Ӧ�߳� movetothread����
	m_ResultDealThread = new ResultDealThread();
	m_pthread2 = new QThread();
	m_ResultDealThread->moveToThread(m_pthread2);
	qDebug() << "start,thread id = " << QThread::currentThreadId();
	// ���Ӳۺ���
	connect(m_pthread2, &QThread::finished, m_ResultDealThread, &QObject::deleteLater);
	connect(this, SIGNAL(sig_doResultDeal()), m_ResultDealThread, SLOT(slot_doResultDeal()));
	connect(m_ResultDealThread, SIGNAL(sendMegToMain(QString)), this, SLOT(slot_recMegFromResultDealThread(QString)));
	qRegisterMetaType<test_structure>("test_structure");
	connect(m_ResultDealThread, SIGNAL(sendResultToMain(test_structure)), this, SLOT(slot_recResultFromResultDealThread(test_structure)));

	// �����Ӧ�߳�&�Զ�����߳�
	//connect(m_AutoDetectThread, SIGNAL(sig_ResultDealstart()), m_ResultDealThread, SLOT(slot_chipstart()));
	
	ui.textBrowser->append("��ʼ��");
	ui.result_textBrowser->append("�ȴ����");
}

test_multiThreading::~test_multiThreading() {
	m_AutoDetectThread->start = 0;
	m_pthread->quit();
	m_pthread->wait();

	m_ResultDealThread->start = 0;
	m_pthread2->quit();
	m_pthread2->wait();
}

//���Զ��߳��߼�
void test_multiThreading::on_StartAutoDetectButton_clicked()
{
	AutoDetectGlobalVarite::AutoDetectInit();
	AutoDetectGlobalVarite::ChipDetectInit();

	/* �����ť����ʼ�Զ���� */
	AutoDetectGlobalVarite::AutoFlag = 1; // �޸�ȫ�ֱ���

	//! ����Ƿ��������
	//! 
	//!
	 
	//��ʼ��������߳�
	m_pthread2->start();
	emit sig_doResultDeal();

	//��ʼ�Զ�����߳�
	m_pthread->start();
	emit sig_doAutoDetect();

}	

void test_multiThreading::on_StopAutoDetectButton_clicked()
{
	/* �����ť���ر��Զ���� */
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
	qDebug() << "�Զ�����߳��˳�,thread id = " << QThread::currentThreadId();
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
	ui.textBrowser->append("������show_result����"+ QString::number(show_result.sequence_number));
	ui.result_textBrowser->append(QString::number(show_result.sequence_number));
	ui.result_textBrowser->append(QString::number(show_result.content));
}