#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QWidget>
#include <qdebug.h>
#include <QMouseEvent>

namespace Ui {
  class MyProgressBar;
}

class MyProgressBar : public QWidget
{
  Q_OBJECT

public:
  explicit MyProgressBar(QWidget *parent = nullptr);
  ~MyProgressBar();

public:
  void mouseMoveEvent(QMouseEvent *event) override;

private:
  Ui::MyProgressBar *ui;
};

#endif // MYPROGRESSBAR_H
