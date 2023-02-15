#include "GlobalVarite.h"

/* AutoDetectGlobalVarite 自动检测参数初始化
* 
* 
*/
QReadWriteLock* AutoDetectGlobalVarite::ReadWriteLock = new QReadWriteLock();

bool AutoDetectGlobalVarite::AutoFlag = 0;
int  AutoDetectGlobalVarite::AutoDetectAccumulateNum = 0;

bool AutoDetectGlobalVarite::ChipDefectFlag = 0;
bool AutoDetectGlobalVarite::ChipStartFlag = 0;
bool AutoDetectGlobalVarite::ChipEndFlag = 0;

int  AutoDetectGlobalVarite::ChipDetectNum = 0;
priority_queue<test_structure, vector<test_structure>, cmp> AutoDetectGlobalVarite:: ResultPriortyQueue = priority_queue<test_structure, vector<test_structure>, cmp>();//小顶堆

/* PLCconnect 参数初始化
*
*
*/
QReadWriteLock* PLCconnect::ReadWriteLock = new QReadWriteLock();
uint16_t PLCconnect::tab_reg[64] = { 0 }; //定义存放数据的数组
uint16_t PLCconnect::send_tab_reg[64] = { 0 }; //定义存放数据的数组
int PLCconnect::port = 502;
const char* PLCconnect::ip = "192.168.0.5";


//自动检测结束完初始化
void AutoDetectGlobalVarite::AutoDetectInit()
{
	AutoDetectGlobalVarite::AutoFlag = 0;
	AutoDetectGlobalVarite::AutoDetectAccumulateNum = 0;
}

//单个芯片检测完初始化
void AutoDetectGlobalVarite::ChipDetectInit()
{
	AutoDetectGlobalVarite::ChipDefectFlag = 0;
	AutoDetectGlobalVarite::ChipStartFlag = 0;
	AutoDetectGlobalVarite::ChipEndFlag = 0;
	AutoDetectGlobalVarite::clear(ResultPriortyQueue); // 清空队列
}

// 清空队列
void AutoDetectGlobalVarite::clear(priority_queue<test_structure, vector<test_structure>, cmp>& q) {
	priority_queue<test_structure, vector<test_structure>, cmp> empty;
	swap(empty, q);
}
