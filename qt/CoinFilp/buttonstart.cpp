#include "buttonstart.h"

ButtonStart::ButtonStart(QWidget *_par, QString _normal, QString _press)
  : QPushButton(_par), normal_img_path(_normal), pressed_Img_path(_press) {
  QPixmap pixmap;
  bool ret = pixmap.load(normal_img_path);
  if (!ret) {
    qDebug() << normal_img_path << "加载图片失败!";
  }

  this->setFixedSize(pixmap.width(), pixmap.height());
  this->setStyleSheet("QPushButton{border:0px;}");
  this->setIcon(pixmap);
  this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

void ButtonStart::zoom_down(void) {
  /* Create a new animation instance */
  QPropertyAnimation *ani = new QPropertyAnimation(this, "geometry");
  ani->setDuration(200);
  ani->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
  ani->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
  /* Set the transition curve, QEasingCurve::OutBounce is the bounce effect */
  ani->setEasingCurve(QEasingCurve::OutBounce);
  /* start */
  ani->start(QAbstractAnimation::DeleteWhenStopped);
}
