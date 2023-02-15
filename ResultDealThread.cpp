#include "ResultDealThread.h"

ResultDealThread::ResultDealThread(QObject* parent) :QObject(parent)
{
    qDebug() << "ResultDealThread()" << QThread::currentThreadId();
	start = 1; // 标志位为1，开始耗时工作
	chipstart = 0; // 标志位为1, 开始PLC工作；标志位为0, 停止PLC工作循环
}
ResultDealThread::~ResultDealThread()
{
    qDebug() << "~ResultDealThread()析构" << QThread::currentThreadId();;
}

// 自动检测线程再开一个
void ResultDealThread::slot_doResultDeal()
{
	test_structure current_result;
	bool RightOrderFlag;
	
	emit sendMegToMain("开始结果处理线程");
	for (;;)
	{
		if (start == 1)//标志位=1，循环执行耗时函数
		{
			AutoDetectGlobalVarite::ReadWriteLock->lockForRead();
			bool ChipStartFlag = AutoDetectGlobalVarite::ChipStartFlag;
			AutoDetectGlobalVarite::ReadWriteLock->unlock();

			if (ChipStartFlag) { //标志位=1，开始执行结果处理函数
				// 处理结果
				for (int i = 0; i < AutoDetectGlobalVarite::ChipDetectNum; ++i)
				{
					if (start == 0) break;
					RightOrderFlag = false;
					while (!RightOrderFlag) {
						// 判断队列是否为空
						//while (AutoDetectGlobalVarite::ResultPriortyQueue.empty()) {
						//	QTime t;
						//	t.start();
						//	while (t.elapsed() < 50) {
						//		QCoreApplication::processEvents();
						//	}
						//	//QThread::msleep(50); //每间隔50ms检测一次
						//}
						
						// 判断队列是否为空
						AutoDetectGlobalVarite::ReadWriteLock->lockForRead();
						bool emptyFlag = AutoDetectGlobalVarite::ResultPriortyQueue.empty();
						AutoDetectGlobalVarite::ReadWriteLock->unlock();
						if (emptyFlag) {
							QThread::msleep(50);
							continue;
						}

						// 结果队列非空，判断是否为当前需输出的结果
						AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
						current_result = AutoDetectGlobalVarite::ResultPriortyQueue.top();
						AutoDetectGlobalVarite::ReadWriteLock->unlock();
						if (!(current_result.sequence_number == i)) {   //不是当前需输出结果
							QThread::msleep(50);
							continue;
						}
						// !是当前需输出结果,跳出等待循环
						RightOrderFlag = true;
					}

					// 是当前所需处理的结果
					AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
					AutoDetectGlobalVarite::ResultPriortyQueue.pop(); // 从队列中pop
					AutoDetectGlobalVarite::ReadWriteLock->unlock();

					/* @！判断是否有缺陷*/
					if (judgeResult(current_result)) {
						emit sendResultToMain(current_result); // 没缺陷
					}
					else { // 有缺陷
						emit sendResultToMain(current_result); //发送回UI响应的主线程
						AutoDetectGlobalVarite::ChipDefectFlag = 1; // 有缺陷的全局标识
						break;	// 跳出检测循环
					}
				}
				// 停止结果分析检测循环
				chipstop();
				emit sendMegToMain("当前芯片检测完成");
				/* 当前芯片检测完成
				*  1、检测完所有区域正常退出for循环
				*  2、顺序检测到有缺陷的区域，直接跳出循环
				*/
				AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
				AutoDetectGlobalVarite::ChipEndFlag = 1;	// 写ChipEndFlag
				AutoDetectGlobalVarite::ReadWriteLock->unlock();
				
			}
		}

		else//标志位=0，跳出循环，线程执行结束
		{
			break;
		}
	}

	emit sig_finish();
}

bool ResultDealThread::judgeResult(test_structure& waitforjudge) {
	if (waitforjudge.content == 400) { // 模拟有缺陷
		return false;
	}
	else {
		return true;
	}
}

// 开始单个芯片结果处理的槽函数，和主线程联动
void ResultDealThread::slot_chipstart() {
	chipstart = 1;
}

// 单个芯片结果处理结束，并发回主线程
void ResultDealThread::chipstop() {
	chipstart = 0; // 停止芯片结果处理循环
}