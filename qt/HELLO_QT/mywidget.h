#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <qpushbutton.h>
#include <iostream>
#include "mybutton.h"
#include <qdialog.h>

class MyWidget : public QWidget
{
  Q_OBJECT

public:
  MyWidget(QWidget *parent = nullptr);
  ~MyWidget();
};
#endif // MYWIDGET_H
