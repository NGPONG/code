#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
  QWidget::setMouseTracking(true);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
  qDebug() << QString("x=%1,x=%2").arg(ev->x()).arg(ev->y());
}
