#include "coin.h"

Coin::Coin(QString _path, QWidget *parent)
  : QPushButton(parent) {
  QPixmap pixmap;
  bool ret = pixmap.load(_path);
  if (!ret) {
    qDebug() << _path << "invaild path";
  }

  this->setFixedSize(pixmap.width(), pixmap.height());
  this->setStyleSheet("QPushButton{border:0px;}");
  this->setIcon(pixmap);
  this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}
