#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <qdebug.h>

class MyLabel : public QLabel
{
  Q_OBJECT
public:
  explicit MyLabel(QWidget *parent = nullptr);

public:
  void mouseMoveEvent(QMouseEvent *ev) override;
};

#endif // MYLABEL_H
