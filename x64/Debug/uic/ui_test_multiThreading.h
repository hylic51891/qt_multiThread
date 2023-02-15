/********************************************************************************
** Form generated from reading UI file 'test_multiThreading.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_MULTITHREADING_H
#define UI_TEST_MULTITHREADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_multiThreadingClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *StartAutoDetectButton;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *StopAutoDetectButton;
    QTextBrowser *result_textBrowser;
    QLabel *label_2;
    QPushButton *PLCstartButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test_multiThreadingClass)
    {
        if (test_multiThreadingClass->objectName().isEmpty())
            test_multiThreadingClass->setObjectName(QStringLiteral("test_multiThreadingClass"));
        test_multiThreadingClass->resize(496, 400);
        centralWidget = new QWidget(test_multiThreadingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        StartAutoDetectButton = new QPushButton(centralWidget);
        StartAutoDetectButton->setObjectName(QStringLiteral("StartAutoDetectButton"));

        gridLayout->addWidget(StartAutoDetectButton, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 1, 1, 1);

        StopAutoDetectButton = new QPushButton(centralWidget);
        StopAutoDetectButton->setObjectName(QStringLiteral("StopAutoDetectButton"));

        gridLayout->addWidget(StopAutoDetectButton, 4, 1, 1, 1);

        result_textBrowser = new QTextBrowser(centralWidget);
        result_textBrowser->setObjectName(QStringLiteral("result_textBrowser"));

        gridLayout->addWidget(result_textBrowser, 1, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        PLCstartButton = new QPushButton(centralWidget);
        PLCstartButton->setObjectName(QStringLiteral("PLCstartButton"));

        gridLayout->addWidget(PLCstartButton, 2, 2, 1, 1);

        test_multiThreadingClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(test_multiThreadingClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 496, 26));
        test_multiThreadingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test_multiThreadingClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        test_multiThreadingClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(test_multiThreadingClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        test_multiThreadingClass->setStatusBar(statusBar);

        retranslateUi(test_multiThreadingClass);

        QMetaObject::connectSlotsByName(test_multiThreadingClass);
    } // setupUi

    void retranslateUi(QMainWindow *test_multiThreadingClass)
    {
        test_multiThreadingClass->setWindowTitle(QApplication::translate("test_multiThreadingClass", "test_multiThreading", Q_NULLPTR));
        StartAutoDetectButton->setText(QApplication::translate("test_multiThreadingClass", "\346\250\241\346\213\237\345\274\200\345\247\213\350\207\252\345\212\250\346\243\200\346\265\213", Q_NULLPTR));
        label->setText(QApplication::translate("test_multiThreadingClass", "\347\272\277\347\250\213\346\266\210\346\201\257\346\241\206", Q_NULLPTR));
        StopAutoDetectButton->setText(QApplication::translate("test_multiThreadingClass", "\346\232\202\345\201\234\350\207\252\345\212\250\346\243\200\346\265\213", Q_NULLPTR));
        label_2->setText(QApplication::translate("test_multiThreadingClass", "\347\273\223\346\236\234\346\266\210\346\201\257\346\241\206", Q_NULLPTR));
        PLCstartButton->setText(QApplication::translate("test_multiThreadingClass", "\346\250\241\346\213\237PLC\345\217\221\345\274\200\345\247\213\344\277\241\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class test_multiThreadingClass: public Ui_test_multiThreadingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_MULTITHREADING_H
