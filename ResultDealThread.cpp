#include "ResultDealThread.h"

ResultDealThread::ResultDealThread(QObject* parent) :QObject(parent)
{
    qDebug() << "ResultDealThread()" << QThread::currentThreadId();
	start = 1; // ��־λΪ1����ʼ��ʱ����
	chipstart = 0; // ��־λΪ1, ��ʼPLC��������־λΪ0, ֹͣPLC����ѭ��
}
ResultDealThread::~ResultDealThread()
{
    qDebug() << "~ResultDealThread()����" << QThread::currentThreadId();;
}

// �Զ�����߳��ٿ�һ��
void ResultDealThread::slot_doResultDeal()
{
	test_structure current_result;
	bool RightOrderFlag;
	
	emit sendMegToMain("��ʼ��������߳�");
	for (;;)
	{
		if (start == 1)//��־λ=1��ѭ��ִ�к�ʱ����
		{
			AutoDetectGlobalVarite::ReadWriteLock->lockForRead();
			bool ChipStartFlag = AutoDetectGlobalVarite::ChipStartFlag;
			AutoDetectGlobalVarite::ReadWriteLock->unlock();

			if (ChipStartFlag) { //��־λ=1����ʼִ�н��������
				// ������
				for (int i = 0; i < AutoDetectGlobalVarite::ChipDetectNum; ++i)
				{
					if (start == 0) break;
					RightOrderFlag = false;
					while (!RightOrderFlag) {
						// �ж϶����Ƿ�Ϊ��
						//while (AutoDetectGlobalVarite::ResultPriortyQueue.empty()) {
						//	QTime t;
						//	t.start();
						//	while (t.elapsed() < 50) {
						//		QCoreApplication::processEvents();
						//	}
						//	//QThread::msleep(50); //ÿ���50ms���һ��
						//}
						
						// �ж϶����Ƿ�Ϊ��
						AutoDetectGlobalVarite::ReadWriteLock->lockForRead();
						bool emptyFlag = AutoDetectGlobalVarite::ResultPriortyQueue.empty();
						AutoDetectGlobalVarite::ReadWriteLock->unlock();
						if (emptyFlag) {
							QThread::msleep(50);
							continue;
						}

						// ������зǿգ��ж��Ƿ�Ϊ��ǰ������Ľ��
						AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
						current_result = AutoDetectGlobalVarite::ResultPriortyQueue.top();
						AutoDetectGlobalVarite::ReadWriteLock->unlock();
						if (!(current_result.sequence_number == i)) {   //���ǵ�ǰ��������
							QThread::msleep(50);
							continue;
						}
						// !�ǵ�ǰ��������,�����ȴ�ѭ��
						RightOrderFlag = true;
					}

					// �ǵ�ǰ���账��Ľ��
					AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
					AutoDetectGlobalVarite::ResultPriortyQueue.pop(); // �Ӷ�����pop
					AutoDetectGlobalVarite::ReadWriteLock->unlock();

					/* @���ж��Ƿ���ȱ��*/
					if (judgeResult(current_result)) {
						emit sendResultToMain(current_result); // ûȱ��
					}
					else { // ��ȱ��
						emit sendResultToMain(current_result); //���ͻ�UI��Ӧ�����߳�
						AutoDetectGlobalVarite::ChipDefectFlag = 1; // ��ȱ�ݵ�ȫ�ֱ�ʶ
						break;	// �������ѭ��
					}
				}
				// ֹͣ����������ѭ��
				chipstop();
				emit sendMegToMain("��ǰоƬ������");
				/* ��ǰоƬ������
				*  1��������������������˳�forѭ��
				*  2��˳���⵽��ȱ�ݵ�����ֱ������ѭ��
				*/
				AutoDetectGlobalVarite::ReadWriteLock->lockForWrite();
				AutoDetectGlobalVarite::ChipEndFlag = 1;	// дChipEndFlag
				AutoDetectGlobalVarite::ReadWriteLock->unlock();
				
			}
		}

		else//��־λ=0������ѭ�����߳�ִ�н���
		{
			break;
		}
	}

	emit sig_finish();
}

bool ResultDealThread::judgeResult(test_structure& waitforjudge) {
	if (waitforjudge.content == 400) { // ģ����ȱ��
		return false;
	}
	else {
		return true;
	}
}

// ��ʼ����оƬ�������Ĳۺ����������߳�����
void ResultDealThread::slot_chipstart() {
	chipstart = 1;
}

// ����оƬ���������������������߳�
void ResultDealThread::chipstop() {
	chipstart = 0; // ֹͣоƬ�������ѭ��
}