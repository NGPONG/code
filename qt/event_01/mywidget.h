#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

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
  /* QObject::timerEvent */
  void timerEvent(QTimerEvent *event) override;

public:
  bool eventFilter(QObject *watched, QEvent *event) override;

private:
  Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
