#include "my_label.h"

my_label::my_label(QWidget *parent):QLabel(parent)
{
    this->setMouseTracking(true);
}

void my_label::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint mouse_pos=ev->pos();
    if(mouse_pos.x()<=this->size().width() && mouse_pos.y()<=this->size().height()){
        if(mouse_pos.x()>0 && mouse_pos.y()>0){
            emit sendMousePosition(mouse_pos);
        }
    }
}

void my_label::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton){
        this->x=ev->x();
        this->y=ev->y();
        emit Mouse_Pos();
    }
}

void my_label::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton){
        this->relX=ev->x();
        this->relY=ev->y();
        emit Mouse_Rel();
    }
}

//void my_label::keyPressEvent(QKeyEvent *event)
//{
//    std::cout << "Root Key Pressed ..." << std::endl;
//    emit Key_Press(event->key());  // eg :- Qt::Key_Q
//}

//void my_label::keyReleaseEvent(QKeyEvent *event)
//{
//    emit Key_Release(event->key());
//}
