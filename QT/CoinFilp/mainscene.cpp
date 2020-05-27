#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainScene)
{
  ui->setupUi(this);

  this->init_win();
}

MainScene::~MainScene()
{
  delete ui;
}

void MainScene::init_win(void) {
  /* theme */
  this->setFixedSize(320,588);
  this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
  this->setWindowTitle("game");

  /* control */
  Button *btn_start = new Button(this, ":/res/MenuSceneStartButton.png");
  btn_start->move(this->width() * 0.5 - btn_start->width() * 0.5,this->height() * 0.7);

  /* form */
  this->choose_scene = new ChooseLevelScene();

  /* event */
  connect(ui->actionExit,&QAction::triggered,[=] {
    QWidget::close();
  });
  connect(btn_start,&QPushButton::clicked,[=] {
    btn_start->zoom_down();

    /* deley 0.7s and enter the choose level form */
    QTimer::singleShot(500,this,[=] {
        this->hide();
        this->choose_scene->show();
    });
  });
  connect(choose_scene,&ChooseLevelScene::closed,[=] {
      choose_scene->hide();
      this->show();
  });
}

void MainScene::paintEvent(QPaintEvent *event) {
  /* Create a painter and set the current window as the canvas */
  QPainter painter(this);

  QPixmap pix;

  /* background */
  pix.load(":/res/PlayLevelSceneBg.png");
  painter.drawPixmap(0,0,this->width(),this->height(),pix);

  /* title */
  pix.load(":/res/Title.png");
  pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
  painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}

