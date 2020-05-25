#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
  QWidget::setMouseTracking(true);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
  qDebug() << QString("default event handler:x=%1, y=%2").arg(ev->x()).arg(ev->y());
}


bool MyLabel::event(QEvent *e) {
  if(e->type() == QEvent::MouseMove) {
    QMouseEvent *ev = static_cast<QMouseEvent *>(e);
    qDebug() << QString("enter event dispatcher：x=%1, y=%2").arg(ev->x()).arg(ev->y());
    return true;
  }

  return QLabel::event(e);
}
