#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#include <QKeyEvent>
#include <QEvent>
#include <iostream>

class my_label : public QLabel
{
    Q_OBJECT

public:
    my_label(QWidget *parent = 0);
    int x,y;
    int relX, relY;

protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
//    void keyPressEvent(QKeyEvent *event);
//    void keyReleaseEvent(QKeyEvent *event);

signals:
    void sendMousePosition(QPoint&);
    void Mouse_Pos();
    void Mouse_Rel();
//    void Key_Press(int);
//    void Key_Release(int);
};

#endif // MY_LABEL_H
