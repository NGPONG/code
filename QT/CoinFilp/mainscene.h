#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QTimer>
#include <qpainter.h>

#include "button.h"
#include "chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
  Q_OBJECT

public:
  MainScene(QWidget *parent = nullptr);
  ~MainScene();

public:
  void init_win(void);

public:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::MainScene *ui;
  ChooseLevelScene *choose_scene;
};
#endif // MAINSCENE_H
