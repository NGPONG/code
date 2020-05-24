/********************************************************************************
** Form generated from reading UI file 'myprogressbar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPROGRESSBAR_H
#define UI_MYPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_MyProgressBar
{
public:
    QVBoxLayout *verticalLayout;
    MyLabel *label;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *MyProgressBar)
    {
        if (MyProgressBar->objectName().isEmpty())
            MyProgressBar->setObjectName(QString::fromUtf8("MyProgressBar"));
        MyProgressBar->resize(432, 182);
        verticalLayout = new QVBoxLayout(MyProgressBar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new MyLabel(MyProgressBar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(label);

        spinBox = new QSpinBox(MyProgressBar);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(MyProgressBar);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        retranslateUi(MyProgressBar);

        QMetaObject::connectSlotsByName(MyProgressBar);
    } // setupUi

    void retranslateUi(QWidget *MyProgressBar)
    {
        MyProgressBar->setWindowTitle(QCoreApplication::translate("MyProgressBar", "Form", nullptr));
        label->setText(QCoreApplication::translate("MyProgressBar", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyProgressBar: public Ui_MyProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPROGRESSBAR_H
