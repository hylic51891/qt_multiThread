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

//test 多线程逻辑测试
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


// 全局变量定义参考： https://blog.csdn.net/u011555996/article/details/108110996
class AutoDetectGlobalVarite
{
public:
	// 读写锁
	static QReadWriteLock* ReadWriteLock;
	// 自动检测
	static int AutoDetectAccumulateNum;
	static bool AutoFlag;
	
	// 总体设置
	static int ChipDetectNum;

	// 单个芯片检测
	static bool ChipDefectFlag;
	static bool ChipStartFlag;
	static bool ChipEndFlag;
	static priority_queue<test_structure, vector<test_structure>, cmp> ResultPriortyQueue;//小顶堆
	
	//static vector<Template> Templates;
	//static priority_queue<detector, vector<detector>, cmp> ResultPriortyQueue;//小顶堆
	//test 
	

public:
	static void clear(priority_queue<test_structure, vector<test_structure>, cmp>& q); // 清空优先队列
	static void AutoDetectInit();	//自动检测结束完初始化
	static void ChipDetectInit();	//单个芯片检测完初始化
};

class PLCconnect
{
public:
	// 读写锁
	static QReadWriteLock* ReadWriteLock;
	static uint16_t tab_reg[64]; //定义存放数据的数组
	static uint16_t send_tab_reg[64]; //定义发送数据的数组
	static int port;
	static const char* ip;

};


#endif

