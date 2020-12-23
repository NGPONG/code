#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
  std::cout << "MyButton CONSTRUCTOR" << std::endl;
}

MyButton::~MyButton() {
  std::cout << "MyButton DESTRUCTOR" << std::endl;
}
