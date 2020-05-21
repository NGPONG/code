#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <string>
#include <qpushbutton.h>

#include "my_signal.h"
#include "my_slot.h"

class MyWidget : public QWidget
{
  Q_OBJECT

public:
  MyWidget(QWidget *parent = nullptr);
  ~MyWidget();
};
#endif // MYWIDGET_H
