#include "mywidget.h"

void foo_test_07(void) {
  qDebug() << "button click!";
}
void foo_test_06(QWidget *_this) {
  QPushButton *button = new QPushButton();
  button->setParent(_this);
  button->setText("CLICK_ME");

  _this->connect(button,&QPushButton::clicked,&foo_test_07);
}

void foo_test_05(QWidget *_this) {
  my_signal *signal = new my_signal(_this);
  my_slot *slot = new my_slot(_this);

  _this->connect(signal,&my_signal::signal_foo,slot,&my_slot::slot_foo_01);
  _this->connect(signal,&my_signal::signal_foo,slot,&my_slot::slot_foo_02);
  _this->connect(signal,&my_signal::signal_foo,slot,&my_slot::slot_foo_03);

  emit signal->signal_foo();

  delete slot;

  emit signal->signal_foo();
}

void foo_test_04(void) {
  qDebug() << "HELLO,WORLD!";
  qDebug() << "HELLO,NGPONG!";
}
void foo_test_03(QWidget *_this) {
  my_signal *signal = new my_signal(_this);
//  my_slot *slot = new my_slot(_this);

  _this->connect(signal,&my_signal::signal_foo,&foo_test_04);

  emit signal->signal_foo();
}

void foo_test_02(QWidget *_this) {
  my_signal *signal = new my_signal(_this);
  my_slot *slot = new my_slot(_this);

  void (my_signal::*ivk_signal)() = &my_signal::signal_test;
  void (my_slot::*ivk_slot)() = &my_slot::slot_test;

  _this->connect(signal,ivk_signal,slot,ivk_slot);

  QPushButton *btn = new QPushButton();
  btn->setParent(_this);
  btn->setText("CLICK");

  _this->connect(btn,&QPushButton::clicked,signal,ivk_signal);
}

void foo_test_01(QWidget *_this) {
  my_signal *signal = new my_signal(_this);
  my_slot *slot = new my_slot(_this);

  void (my_signal::*ivk_signal)(std::string) = &my_signal::signal_test;
  void (my_slot::*ivk_slot)(std::string) = &my_slot::slot_test;

  _this->connect(signal,ivk_signal,slot,ivk_slot);

  emit signal->signal_test("Hello,World");
}

MyWidget::MyWidget(QWidget *parent)
  : QWidget(parent)
{
//  foo_test_01(this);
//  foo_test_02(this);
//  foo_test_03(this);
//  foo_test_05(this);

  connect()

  foo_test_06(this);
}

MyWidget::~MyWidget()
{
}

