#pragma once
#pragma execute-character-set("utf-8")

#ifndef _ResultDealThread_H_
#define _ResultDealThread_H_

#include <QDebug>
#include <QThread>
#include <QString>
#include <QObject>
#include <QTime>
#include <QThreadPool>

#include <qtimer.h>

#include "GlobalVarite.h"

// �ο� ԭ�����ӣ�https ://blog.csdn.net/qianbo042311/article/details/126882915
// ��movetothread����������߳�

class ResultDealThread :public QObject
{
    Q_OBJECT
public:
    explicit ResultDealThread(QObject* parent = 0);
    ~ResultDealThread();
    int timerId_TCP;

    // �̰߳�ȫ�ṹ�ο���https://blog.csdn.net/weixin_48424192/article/details/110367584
    bool start;
    // ��chip��ʼ����ź�
    bool chipstart;

private:
    void chipstop();
    //modbus_t* pmbs_ctx;
    //modbus_t* ctx = nullptr;

signals:
    void sig_finish();  // �߳̽����ź�
    void chip_finish(); // ����оƬ�������ź�

    void sendResultToMain(test_structure);
    void sendMegToMain(QString);

public slots:
    void slot_chipstart();
    void slot_doResultDeal();

private:
    //void timerEvent(QTimerEvent* event) Q_DECL_OVERRIDE;
    bool judgeResult(test_structure& waitforjudge);
};
#endif