#ifndef MY_SLOT_H
#define MY_SLOT_H

#include <QObject>
#include <qdebug.h>
#include <string>

class my_slot : public QObject
{
  Q_OBJECT
public:
  explicit my_slot(QObject *parent = nullptr);

public slots:
  void slot_test(void);
  void slot_test(std::string _msg);
  void slot_foo(void);
  void slot_foo_01(void);
  void slot_foo_02(void);
  void slot_foo_03(void);
};

#endif // MY_SLOT_H
