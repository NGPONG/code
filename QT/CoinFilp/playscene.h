#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QTimer>
#include <QMenuBar>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>

#include "button.h"
#include "coin.h"

class PlayScene : public QMainWindow {
  Q_OBJECT
public:
  explicit PlayScene(int _idx, QWidget *parent = nullptr);
  
public:
  void paintEvent(QPaintEvent *) override;
  
private:
  int level_idx;

signals:
  void closed(PlayScene *_p);
};

#endif  // PLAYSCENE_H
