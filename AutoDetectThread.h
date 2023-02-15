#pragma once
#pragma execute-character-set("utf-8")

#ifndef _AutoDetectThread_H_
#define _AutoDetectThread_H_

#include <QDebug>
#include <QThread>
#include <QString>
#include <QObject>
#include <QTime>
#include <QThreadPool>

#include <qtimer.h>

#include "GlobalVarite.h"
#include "ThreadWorks.h"


// 参考 原文链接：https ://blog.csdn.net/qianbo042311/article/details/126882915
// 用movetothread做PLC监听线程

class AutoDetectThread :public QObject
{
    Q_OBJECT
public:
    explicit AutoDetectThread(QObject* parent = 0);
    ~AutoDetectThread();

    int timerId_PLC;
    int waittime;

    bool start;
private:

    QThreadPool detectPool;
    vector<DetectThread*> detectworks;
    //modbus_t* pmbs_ctx;
    //modbus_t* ctx = nullptr;

signals:
    void sig_ResultDealstart(); // 传给结果处理线程
    void sig_finish();
    void sendMegToMain(QString str);

public slots:
    void slot_doAutoDetect();
    void slot_stop();

private:
    void timerEvent(QTimerEvent* event) Q_DECL_OVERRIDE;
    void waitfor_chipstart();
    void waitfor_chipend();
    void chipdetect(int content);
};
#endif // _AutoDetectThread_H_
