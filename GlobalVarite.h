#pragma once
#pragma execution_character_set("utf-8")

#ifndef _GLOBALVARITE_H_
#define _GLOBALVARITE_H_

#include <QReadWriteLock>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using std::vector;

//test ���߳��߼�����
class test_structure
{
public:
	test_structure() = default;
	test_structure(int sequence_num, int content): sequence_number(sequence_num), content(content){}
	int sequence_number;
	int content;
};

class cmp {
	//bool operator()(detector& a, detector& b) {
	//	return a.AutoDetectSequenceNumber > b.AutoDetectSequenceNumber;
	//}

	//test 
public:
	bool operator()(test_structure& a, test_structure& b) {
		return a.sequence_number > b.sequence_number;
	}
};


// ȫ�ֱ�������ο��� https://blog.csdn.net/u011555996/article/details/108110996
class AutoDetectGlobalVarite
{
public:
	// ��д��
	static QReadWriteLock* ReadWriteLock;
	// �Զ����
	static int AutoDetectAccumulateNum;
	static bool AutoFlag;
	
	// ��������
	static int ChipDetectNum;

	// ����оƬ���
	static bool ChipDefectFlag;
	static bool ChipStartFlag;
	static bool ChipEndFlag;
	static priority_queue<test_structure, vector<test_structure>, cmp> ResultPriortyQueue;//С����
	
	//static vector<Template> Templates;
	//static priority_queue<detector, vector<detector>, cmp> ResultPriortyQueue;//С����
	//test 
	

public:
	static void clear(priority_queue<test_structure, vector<test_structure>, cmp>& q); // ������ȶ���
	static void AutoDetectInit();	//�Զ����������ʼ��
	static void ChipDetectInit();	//����оƬ������ʼ��
};

class PLCconnect
{
public:
	// ��д��
	static QReadWriteLock* ReadWriteLock;
	static uint16_t tab_reg[64]; //���������ݵ�����
	static uint16_t send_tab_reg[64]; //���巢�����ݵ�����
	static int port;
	static const char* ip;

};


#endif

