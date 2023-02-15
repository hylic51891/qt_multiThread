#include "ThreadWorks.h"

class AutoDetectGlobalVarite;


DetectThread::~DetectThread()
{
}

void DetectThread::run()
{
	//test
	QTime t;
	t.start();
	
	qDebug() << "DetectThread run 被调用，调用线程ID为：" << QThread::currentThread();
	switch (this->test.sequence_number)
	{
	case 1:
		while (t.elapsed() < 1000) QCoreApplication::processEvents();
		break;
	case 2:
		while (t.elapsed() < 3000) QCoreApplication::processEvents();
		break;
	case 3:
		while (t.elapsed() < 1000) QCoreApplication::processEvents();
		break;
	case 4:
		while (t.elapsed() < 2000) QCoreApplication::processEvents();
		break;
	case 5:
		while (t.elapsed() < 1000) QCoreApplication::processEvents();
		break;
	default:
		while (t.elapsed() < 1000) QCoreApplication::processEvents();
		break;
	}
	qDebug() << "线程2打印数据：" << QString::number(this->test.content) << QThread::currentThread();;
	int result = (this->test.content) * (this->test.content);
	this->test.content = result;

	AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
	AutoDetectGlobalVarite::ResultPriortyQueue.push(this->test); //push到全局变量
	AutoDetectGlobalVarite::ReadWriteLock->unlock();
	//emit sendResultToMain(this->test);
}

void DetectThread::recMegFromMain(QString str)
{
	qDebug() << "子线程接收到" << str;

}

// test
bool DetectThread::init(int sequence_number, int content)
{
	try {
		this->test.sequence_number = sequence_number;
		this->test.content = content;

		return true;
	}
	catch (...) { return false; }
}


// ===================================================================
//
//ResultDealThread::~ResultDealThread() 
//{
//
//}
//
//void ResultDealThread::run()
//{
//	test_structure current_result;
//	bool RightOrderFlag;
//	for (int i = 0; i < AutoDetectGlobalVarite::ChipDetectNum; ++i) {
//		RightOrderFlag = false;
//		while (!RightOrderFlag) {
//			// 判断队列是否为空
//			if (AutoDetectGlobalVarite::ResultPriortyQueue.empty()) {
//				QThread::msleep(50);
//				continue;
//			}
//			// 结果队列非空，判断是否为当前需输出的结果
//			current_result = AutoDetectGlobalVarite::ResultPriortyQueue.top();
//			if (current_result.sequence_number == i) { //为当前需输出结果
//			/*	emit*/
//				AutoDetectGlobalVarite::ResultPriortyQueue.pop();
//			}
//			else {
//				QThread::msleep(50);
//				continue;
//			}
//		}
//		
//
//	}
//}
