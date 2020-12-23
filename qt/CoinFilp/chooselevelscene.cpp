#include "chooselevelscene.h"

void init_win(ChooseLevelScene *_win) {
  _win->setFixedSize(320, 588);
  _win->setWindowIcon(QPixmap(":/res/Coin0001.png"));
  _win->setWindowTitle("Choose a level");
}

void init_control(ChooseLevelScene *_win) {
  QMenuBar *bar = _win->menuBar();
  _win->setMenuBar(bar);

  QMenu *startMenu = bar->addMenu("Start");

  QAction *quitAction = startMenu->addAction("Exit");
  _win->connect(quitAction, &QAction::triggered, [=] {
    _win->close();
  });

  Button *btn_return = new Button(_win, ":/res/BackButton.png", ":/res/BackButtonSelected.png");
  btn_return->move(_win->width() - btn_return->width(), _win->height() - btn_return->height());
  _win->connect(btn_return, &QPushButton::clicked, [=] {
    QTimer::singleShot(100, _win, [=] {
      emit _win->closed();
      _win->hide();
    });
  });

  /* level button */
  for (int i = 0; i < 20; i++) {
    Button *menu_btn = new Button(_win, ":/res/LevelIcon.png");
    menu_btn->move(25 + (i % 4) * 70, 130 + (i / 4) * 70);

    QLabel *label = new QLabel; /* Display font text in button */
    label->setParent(_win);
    label->setFont(QFont("Fira Code"));
    label->setFixedSize(menu_btn->width(), menu_btn->height());
    label->setText(QString::number(i + 1));
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); /* set center alignment */
    label->move(25 + (i % 4) * 70, 130 + (i / 4) * 70);
    /**
     * When enabled, this attribute disables the delivery of mouse events to the widget and its children.
     * Mouse events are delivered to other widgets as if the widget and its children were not present in
     * the widget hierarchy; mouse clicks and other events effectively "pass through" them.
     * This attribute is disabled by default.
    */
    label->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    /* Click the button to show the Play-Scene window */
    _win->connect(menu_btn, &QPushButton::clicked, [=] {
      /**
       * In order to avoid troublesome memory management, 
       * it is best not to reuse game scenes, directly remove and create new scenes
      */
      if (_win->play_scene == nullptr) {
        _win->play_scene = new PlayScene(i + 1);
        _win->play_scene->show();
        _win->hide();
        
        qDebug() << "create:" << _win->play_scene;

        _win->connect(_win->play_scene, &PlayScene::closed, [=] (PlayScene *_p) {
          _win->show();
          _p->hide();
          
          /* restore */
          delete _win->play_scene;
          qDebug() << "delete:" << _win->play_scene;
          _win->play_scene = nullptr;
        });
      }
    });
  }
}

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
  : QMainWindow(parent) {
  init_win(this);
  init_control(this);
}

void ChooseLevelScene::paintEvent(QPaintEvent *) {
  QPainter painter(this);

  QPixmap pix;

  pix.load(":/res/OtherSceneBg.png");
  painter.drawPixmap(0, 0, this->width(), this->height(), pix);

  pix.load(":/res/Title.png");
  painter.drawPixmap((this->width() - pix.width()) * 0.5, 30, pix.width(), pix.height(), pix);
}
