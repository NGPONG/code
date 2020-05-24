/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_test;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyMainWindow)
    {
        if (MyMainWindow->objectName().isEmpty())
            MyMainWindow->setObjectName(QString::fromUtf8("MyMainWindow"));
        MyMainWindow->resize(845, 622);
        centralwidget = new QWidget(MyMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_test = new QPushButton(centralwidget);
        btn_test->setObjectName(QString::fromUtf8("btn_test"));
        btn_test->setGeometry(QRect(110, 60, 84, 24));
        MyMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 845, 25));
        MyMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MyMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MyMainWindow->setStatusBar(statusbar);

        retranslateUi(MyMainWindow);

        QMetaObject::connectSlotsByName(MyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyMainWindow)
    {
        MyMainWindow->setWindowTitle(QCoreApplication::translate("MyMainWindow", "MyMainWindow", nullptr));
        btn_test->setText(QCoreApplication::translate("MyMainWindow", "CLICK_ME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyMainWindow: public Ui_MyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
