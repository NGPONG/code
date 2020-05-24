#include "my_widget.h"

my_widget::my_widget(QWidget *parent)
  : QWidget(parent)
{
  QPushButton *btn = new QPushButton();
  btn->setParent(this);

  int _val = 0x400;
  connect(btn,&QPushButton::clicked,[&](void) {
    qDebug() << _val;
  });

  QPushButton *btn2 = new QPushButton();
  btn2->setParent(this);
  btn2->move(100,100);
  connect(btn2,&QPushButton::clicked,[=](void) {
    qDebug() << _val;
  });
}

my_widget::~my_widget()
{
}

