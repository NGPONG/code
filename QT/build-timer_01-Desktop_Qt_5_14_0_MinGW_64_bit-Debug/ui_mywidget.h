/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(800, 600);
        label = new QLabel(MyWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 80, 191, 51));
        label->setFrameShape(QFrame::Box);
        label_2 = new QLabel(MyWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 210, 191, 51));
        label_2->setFrameShape(QFrame::WinPanel);
        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 90, 111, 24));
        pushButton_2 = new QPushButton(MyWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 220, 111, 24));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        label->setText(QCoreApplication::translate("MyWidget", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MyWidget", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MyWidget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MyWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
