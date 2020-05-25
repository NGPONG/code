#ifndef MYLABEL_H
#define MYLABEL_H

#include <qlabel.h>
#include <QMouseEvent>
#include <qdebug.h>
#include <qevent.h>

class MyLabel : public QLabel
{
  Q_OBJECT
public:
  explicit MyLabel(QWidget *parent = nullptr);

public:
  void mouseMoveEvent(QMouseEvent *ev) override;

public:
  bool event(QEvent *e) override;
};

#endif // MYLABEL_H
