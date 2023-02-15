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

// 参考 原文链接：https ://blog.csdn.net/qianbo042311/article/details/126882915
// 用movetothread做结果监听线程

class ResultDealThread :public QObject
{
    Q_OBJECT
public:
    explicit ResultDealThread(QObject* parent = 0);
    ~ResultDealThread();
    int timerId_TCP;

    // 线程安全结构参考：https://blog.csdn.net/weixin_48424192/article/details/110367584
    bool start;
    // 等chip开始检测信号
    bool chipstart;

private:
    void chipstop();
    //modbus_t* pmbs_ctx;
    //modbus_t* ctx = nullptr;

signals:
    void sig_finish();  // 线程结束信号
    void chip_finish(); // 单个芯片检测结束信号

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