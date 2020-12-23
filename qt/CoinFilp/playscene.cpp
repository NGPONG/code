#include "playscene.h"

PlayScene::PlayScene(int _idx, QWidget *parent)
  : QMainWindow(parent), level_idx(_idx) {
  /* global */
  this->setFixedSize(320, 588);
  this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
  this->setWindowTitle("playing");

  /* top menu */
  QMenuBar *bar = this->menuBar();
  this->setMenuBar(bar);
  QMenu *startMenu = bar->addMenu("Start");
  QAction *quitAction = startMenu->addAction("Exit");
  connect(quitAction, &QAction::triggered, [=] {
    this->close();
  });

  /* return button */
  Button *btn_return = new Button(this, ":/res/BackButton.png", ":/res/BackButtonSelected.png");
  btn_return->move(this->width() - btn_return->width(), this->height() - btn_return->height());
  connect(btn_return, &QPushButton::clicked, [=] {
    QTimer::singleShot(100, this, [=] {
      emit this->closed(this);
    });
  });

  /* level label */
  QLabel *level_label = new QLabel(this);
  QFont level_font;
  level_font.setFamily("Fira Code");
  level_font.setPointSize(10);
  level_label->setFont(level_font);
  level_label->setStyleSheet("font-weight: bold; color: blue");
  level_label->setText(QString("Leavel: %1").arg(this->level_idx));
  level_label->setGeometry(QRect(30, this->height() - 50, 120, 50));

  /* create display background for coin */
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      /* background */
      QLabel *coin_label = new QLabel(this);
      coin_label->setGeometry(0, 0, 50, 50);
      coin_label->setPixmap(QPixmap(":/res/BoardNode.png"));
      coin_label->move(57 + i * 50, 200 + j * 50);

      /* coin */
      Coin *coin = new Coin(":/res/Coin0001.png",this);
      coin->move(59 + i * 50, 204 + j * 50);
    }
  }
}

void PlayScene::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  QPixmap pix;
  pix.load(":/res/PlayLevelSceneBg.png");
  painter.drawPixmap(0, 0, this->width(), this->height(), pix);

  pix.load(":/res/Title.png");
  pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
  painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
