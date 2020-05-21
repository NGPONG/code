#include "my_slot.h"

my_slot::my_slot(QObject *parent) : QObject(parent)
{

}

void my_slot::slot_test(void) {
  qDebug() << "hello,slot";
}

void my_slot::slot_test(std::string _msg) {
  qDebug() << _msg.c_str();
}

void my_slot::slot_foo(void) {
  qDebug() << "slot_foo";
}

void my_slot::slot_foo_01(void) {
  qDebug() << "slot_foo_01";
}

void my_slot::slot_foo_02(void) {
  qDebug() << "slot_foo_02";
}

void my_slot::slot_foo_03(void) {
  qDebug() << "slot_foo_03";
}
