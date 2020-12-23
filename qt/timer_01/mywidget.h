#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimerEvent>
#include <qtimer.h>
#include <iostream>
#include <qdebug.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
  Q_OBJECT

public:
  MyWidget(QWidget *parent = nullptr);
  ~MyWidget();

public:
  /* global timer */
  void timerEvent(QTimerEvent *event) override;

private:
  Ui::MyWidget *ui;
  int timerid_1 = -1;
};
#endif // MYWIDGET_H
