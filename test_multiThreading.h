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

class AutoDetectGlobalVarite; //自动检测全局变量初始化
class PLCconnect; //PLC通讯变量初始化

// 参考例子：https://blog.csdn.net/qq_37529913/article/details/115536799
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

	QTimer* timer_TCP;//定时器，监听信号
	int timerId_TCP;

private:
	//void timerEvent(QTimerEvent* event) Q_DECL_OVERRIDE;

signals:
	void sengMsgToThread(QString);
	void sig_doAutoDetect();	// 自动检测线程
	void sig_doResultDeal();	// 结果处理线程

public slots:
	void slot_finish();
	void on_StartAutoDetectButton_clicked(); //测试多线程逻辑
	void on_StopAutoDetectButton_clicked(); // 停止自动检测
	void on_PLCstartButton_clicked(); //模拟PLC发开始信号

	// 自动检测线程
	void slot_recMegFromAutoDetectThread(QString str);
	// 结果处理线程
	void slot_recMegFromResultDealThread(QString str);
	void slot_recResultFromResultDealThread(test_structure show_result);

};

#endif // !_TEST_MULTITHREADING_H_