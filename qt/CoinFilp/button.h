#ifndef BUTTONSTART_H
#define BUTTONSTART_H

#include <QDebug>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QPushButton>

class Button : public QPushButton {
  Q_OBJECT
public:
  explicit Button(QWidget *_par, QString _normal, QString _press = "");
  
private:
  QString normal_img_path;  /* Display picture path by default */
  QString pressed_Img_path; /* Press to display the picture path */

public:
  void mousePressEvent(QMouseEvent *_e) override;
  void mouseReleaseEvent(QMouseEvent *_e) override;

public:
  void zoom_down(void);
};

#endif  // BUTTONSTART_H
