#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QLabel>
#include <QTimer>

#include "button.h"
#include <playscene.h>

class ChooseLevelScene : public QMainWindow {
  Q_OBJECT
public:
  explicit ChooseLevelScene(QWidget *parent = nullptr);

public:
  void paintEvent(QPaintEvent *) override;

public:
  PlayScene *play_scene = nullptr;
  
signals:
  void closed(void);
};

#endif  // CHOOSELEVELSCENE_H
