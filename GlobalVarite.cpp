#include "GlobalVarite.h"

/* AutoDetectGlobalVarite �Զ���������ʼ��
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
priority_queue<test_structure, vector<test_structure>, cmp> AutoDetectGlobalVarite:: ResultPriortyQueue = priority_queue<test_structure, vector<test_structure>, cmp>();//С����

/* PLCconnect ������ʼ��
*
*
*/
QReadWriteLock* PLCconnect::ReadWriteLock = new QReadWriteLock();
uint16_t PLCconnect::tab_reg[64] = { 0 }; //���������ݵ�����
uint16_t PLCconnect::send_tab_reg[64] = { 0 }; //���������ݵ�����
int PLCconnect::port = 502;
const char* PLCconnect::ip = "192.168.0.5";


//�Զ����������ʼ��
void AutoDetectGlobalVarite::AutoDetectInit()
{
	AutoDetectGlobalVarite::AutoFlag = 0;
	AutoDetectGlobalVarite::AutoDetectAccumulateNum = 0;
}

//����оƬ������ʼ��
void AutoDetectGlobalVarite::ChipDetectInit()
{
	AutoDetectGlobalVarite::ChipDefectFlag = 0;
	AutoDetectGlobalVarite::ChipStartFlag = 0;
	AutoDetectGlobalVarite::ChipEndFlag = 0;
	AutoDetectGlobalVarite::clear(ResultPriortyQueue); // ��ն���
}

// ��ն���
void AutoDetectGlobalVarite::clear(priority_queue<test_structure, vector<test_structure>, cmp>& q) {
	priority_queue<test_structure, vector<test_structure>, cmp> empty;
	swap(empty, q);
}
