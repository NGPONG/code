#include "button.h"

Button::Button(QWidget *_par, QString _normal, QString _press)
    : QPushButton(_par), normal_img_path(_normal), pressed_Img_path(_press) {
    QPixmap pixmap;
    bool ret = pixmap.load(normal_img_path);
    if (!ret) {
        qDebug() << normal_img_path << "invalid path";
    }

    this->setFixedSize( pixmap.width(), pixmap.height() );
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

void Button::zoom_down(void) {
    /* Create a new animation instance */
    QPropertyAnimation *ani = new QPropertyAnimation(this,"geometry");
    ani->setDuration(200);
    ani->setStartValue(QRect(this->x(),this->y() + 10,this->width(),this->height()));
    ani->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    /* Set the transition curve, QEasingCurve::OutBounce is the bounce effect */
    ani->setEasingCurve(QEasingCurve::OutBounce);
    /* start */
    ani->start(QAbstractAnimation::DeleteWhenStopped);
}

void Button::mousePressEvent(QMouseEvent *e) {
    if(pressed_Img_path != "") {
        QPixmap pixmap;
        bool ret = pixmap.load(pressed_Img_path);
        if(!ret) {
            qDebug() << pressed_Img_path << "invaild path";
        }

        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }

    return QPushButton::mousePressEvent(e);
}

void Button::mouseReleaseEvent(QMouseEvent *e) {
    if(normal_img_path != "") {
        QPixmap pixmap;
        bool ret = pixmap.load(normal_img_path);
        if(!ret) {
            qDebug() << normal_img_path << "invaild path";
        }

        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }

    return QPushButton::mouseReleaseEvent(e);
}
