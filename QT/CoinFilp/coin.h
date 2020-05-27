#ifndef COIN_H
#define COIN_H

#include <QPushButton>
#include <QDebug>

class Coin : public QPushButton {
  Q_OBJECT
public:
  explicit Coin(QString _path, QWidget *parent = nullptr);
};

#endif  // COIN_H
