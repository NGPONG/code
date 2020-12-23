#ifndef MY_SIGNAL_H
#define MY_SIGNAL_H

#include <QObject>
#include <string>

class my_signal : public QObject
{
  Q_OBJECT
public:
  explicit my_signal(QObject *parent = nullptr);

signals:
  void signal_test(void);
  void signal_test(std::string _msg);
  void signal_foo(void);
};

#endif // MY_SIGNAL_H
