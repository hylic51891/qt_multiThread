#pragma once
#pragma execution_character_set("utf-8")
#ifndef _THREADWORKS_H_
#define _THREADWORKS_H_


#include <QCoreApplication>
#include <QThreadPool>
#include <QDebug>
#include <QReadWriteLock>
#include <QTime>

#include <qtimer.h>
#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>

#include "GlobalVarite.h"

using namespace std;
using namespace cv;



class DetectThread : public QObject, public QRunnable
{
	Q_OBJECT

public:
	explicit DetectThread(QObject* parent = nullptr)
	{
		setAutoDelete(true);
	}

	~DetectThread();

	void run() override;
	bool init(int sequence_number, int content);

public:
	test_structure test;

signals:
	void isDone(int); // 1 done
	void sendResultToMain(test_structure);

public slots:
	void recMegFromMain(QString str);

};

//
//class ResultDealThread : public QObject, public QRunnable
//{
//	Q_OBJECT
//
//public:
//	explicit ResultDealThread(QObject* parent = nullptr)
//	{
//		setAutoDelete(true);
//	}
//
//	~ResultDealThread();
//
//	void run() override;
//
//public:
//	test_structure test;
//
//signals:
//	void isDone(int); // 1 done
//	void sendResultToMain(test_structure);
//
//public slots:
//	void recMegFromMain(QString str);
//
//};
#endif

