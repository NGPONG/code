#include "myprogressbar.h"
#include "ui_myprogressbar.h"

MyProgressBar::MyProgressBar(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MyProgressBar)
{
  ui->setupUi(this);

  void (QSpinBox::*text_changed)(int) = &QSpinBox::valueChanged;
  connect(ui->spinBox,text_changed,[=](int _val){
    ui->horizontalSlider->setValue(_val);
  });

  connect(ui->horizontalSlider,&QSlider::valueChanged,[=] (int _val) {
    ui->spinBox->setValue(_val);
  });

  /* 设置鼠标追踪，即不需要点击按键即可进入 mouseMoveEvent 事件 */
//  setMouseTracking(true);
}

MyProgressBar::~MyProgressBar()
{
  delete ui;
}


void MyProgressBar::mouseMoveEvent(QMouseEvent *event) {
  qDebug() << QString("x=%1, y=%2").arg(event->x()).arg(event->y());
}
