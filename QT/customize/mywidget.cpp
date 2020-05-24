#include "mywidget.h"
#include "ui_mywidget.h"
#include <qlabel.h>

MyWidget::MyWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::MyWidget)
{
  ui->setupUi(this);
}

MyWidget::~MyWidget()
{
  delete ui;
}

