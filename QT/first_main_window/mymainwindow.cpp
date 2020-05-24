#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MyMainWindow)
{
  ui->setupUi(this);

  connect(ui->btn_test,&QPushButton::clicked,[this]{
//    QMessageBox::question(this,"msg","hello,NGPONG!");
    QDialog *dlg = new QDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->show();
  });


}

MyMainWindow::~MyMainWindow()
{
  delete ui;
}

