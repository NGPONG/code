#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <qpushbutton.h>
#include <qdebug.h>
#include <iostream>

class MyButton : public QPushButton
{
  Q_OBJECT
public:
  explicit MyButton(QWidget *parent = nullptr);
  ~MyButton();
signals:

};

#endif // MYBUTTON_H
