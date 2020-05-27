#include "chooselevelscene.h"

void init_win(ChooseLevelScene *_win) {
    _win->setFixedSize(320,588);
    _win->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    _win->setWindowTitle("Choose a level");
}

void init_control(ChooseLevelScene *_win) {
    /* menubar */
    QMenuBar *bar = _win->menuBar();
    _win->setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("Start");
    QAction *quitAction = startMenu->addAction("Exit");

    /* return button */
    Button *btn_return = new Button(_win,":/res/BackButton.png",":/res/BackButtonSelected.png");
    btn_return->move(_win->width()-btn_return->width(),_win->height()-btn_return->height());

    /* level button */
    for(int i = 0 ; i < 20;i++) {
        Button *menuBtn = new Button(_win,":/res/LevelIcon.png");
        menuBtn->move(25 + (i%4)*70 , 130+ (i/4)*70);

        QLabel *label = new QLabel; /* Display font text in button */
        label->setParent(_win);
        label->setFont(QFont("Fira Code"));
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);   /* set center alignment */
        label->move(25 + (i%4)*70 , 130+ (i/4)*70);
        /**
         * When enabled, this attribute disables the delivery of mouse events to the widget and its children.
         * Mouse events are delivered to other widgets as if the widget and its children were not present in
         * the widget hierarchy; mouse clicks and other events effectively "pass through" them.
         * This attribute is disabled by default.
        */
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    }

    /* event */
    _win->connect(quitAction,&QAction::triggered,[=] {
        _win->close();
    });
    _win->connect(btn_return,&QPushButton::clicked,[=] {
        emit _win->closed();
        _win->hide();
    });
}

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent) {
    init_win(this);
    init_control(this);
}

void ChooseLevelScene::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    QPixmap pix;

    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
