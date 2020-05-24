#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <qmessagebox.h>
#include <qdialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MyMainWindow; }
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MyMainWindow(QWidget *parent = nullptr);
  ~MyMainWindow();

private:
  Ui::MyMainWindow *ui;
};
#endif // MYMAINWINDOW_H
