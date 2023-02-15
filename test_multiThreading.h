#pragma once
#pragma execution_character_set("utf-8")

#ifndef _TEST_MULTITHREADING_H_
#define _TEST_MULTITHREADING_H_

#include <QtWidgets/QMainWindow>
#include <QThreadPool>
#include <QTime>
#include "ui_test_multiThreading.h"

#include"GlobalVarite.h"
#include"ThreadWorks.h"

#include "AutoDetectThread.h"
#include "ResultDealThread.h"

class AutoDetectGlobalVarite; //�Զ����ȫ�ֱ�����ʼ��
class PLCconnect; //PLCͨѶ������ʼ��

// �ο����ӣ�https://blog.csdn.net/qq_37529913/article/details/115536799
class test_multiThreading : public QMainWindow
{
	Q_OBJECT

public:
	test_multiThreading(QWidget *parent = Q_NULLPTR);
	~test_multiThreading();



private:
	Ui::test_multiThreadingClass ui;

	AutoDetectThread* m_AutoDetectThread;
	QThread* m_pthread;
	ResultDealThread* m_ResultDealThread;
	QThread* m_pthread2;

	QTimer* timer_TCP;//��ʱ���������ź�
	int timerId_TCP;

private:
	//void timerEvent(QTimerEvent* event) Q_DECL_OVERRIDE;

signals:
	void sengMsgToThread(QString);
	void sig_doAutoDetect();	// �Զ�����߳�
	void sig_doResultDeal();	// ��������߳�

public slots:
	void slot_finish();
	void on_StartAutoDetectButton_clicked(); //���Զ��߳��߼�
	void on_StopAutoDetectButton_clicked(); // ֹͣ�Զ����
	void on_PLCstartButton_clicked(); //ģ��PLC����ʼ�ź�

	// �Զ�����߳�
	void slot_recMegFromAutoDetectThread(QString str);
	// ��������߳�
	void slot_recMegFromResultDealThread(QString str);
	void slot_recResultFromResultDealThread(test_structure show_result);

};

#endif // !_TEST_MULTITHREADING_H_