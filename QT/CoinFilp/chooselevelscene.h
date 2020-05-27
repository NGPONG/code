#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QLabel>

#include "button.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

public:
    void paintEvent(QPaintEvent *) override;

signals:
    void closed(void);
};

#endif // CHOOSELEVELSCENE_H
