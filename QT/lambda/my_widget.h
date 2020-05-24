#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <qpushbutton.h>
#include <qdebug.h>

class my_widget : public QWidget
{
  Q_OBJECT

public:
  my_widget(QWidget *parent = nullptr);
  ~my_widget();
};
#endif // MY_WIDGET_H
