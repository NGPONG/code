#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::MyWidget)
{
  ui->setupUi(this);
  ui->label->installEventFilter(this);

  startTimer(500);
}

MyWidget::~MyWidget()
{
  delete ui;
}

void MyWidget::timerEvent(QTimerEvent *event) {
  static int _index = 0;
  ui->label->setText(QString::number(++_index));
}

bool MyWidget::eventFilter(QObject *watched, QEvent *event) {
  if(watched == ui->label) {
    if(event->type() == QEvent::MouseMove) {
      QMouseEvent *ev = static_cast<QMouseEvent *>(event);
      qDebug() << QString("enter event filter：x=%1, y=%2").arg(ev->x()).arg(ev->y());
      return true;
    }
  }

  return QWidget::eventFilter(watched, event);
}
