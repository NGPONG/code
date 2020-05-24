#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::MyWidget)
{
  ui->setupUi(this);

  /* start timer */
  this->timerid_1 = QObject::startTimer(100);

  QTimer *timer = new QTimer();
  connect(timer,&QTimer::timeout,[=] {
    static int _i = 100;
    ui->label_2->setText(QString::number(++_i));
  });
  timer->start(500);


  /* set stop timer event */
  connect(ui->pushButton,&QPushButton::clicked,[=] {
    killTimer(this->timerid_1);
    this->timerid_1 = -1;
  });

  connect(ui->pushButton_2,&QPushButton::clicked,[=] () mutable {
    if(timer == nullptr) {
      qDebug() << "OK!";
      return;
    }

    timer->stop();
    timer = nullptr;
    delete timer;
  });
}

void MyWidget::timerEvent(QTimerEvent *event) {
  static int _i = 0;
  if(this->timerid_1 == event->timerId()) {
    ui->label->setText(QString::number(++_i));
  }
}

MyWidget::~MyWidget()
{
  delete ui;
}

