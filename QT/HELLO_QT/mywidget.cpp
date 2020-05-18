#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
  : QWidget(parent)
{
  //  QPushButton *button = new QPushButton("Hello",this);
  //  QPushButton *button = new QPushButton();
  //  button->setParent(this);

  QPushButton button;
  button.setParent(this);
  button.show();
}

MyWidget::~MyWidget()
{
  std::cout << "MyWidget DESUTRCOR" << std::endl;
}
