#include "enemie3.h"

Enemie3::Enemie3(float r, float x, float y)
{
    posx=x;
    posy=y;
    radio=r;
}

void Enemie3::posicion()
{
    setPos(x()+30,y());
    if(x()>1000){
        setPos(-50+rand()%10,30+rand()%300);
    }
}

QRectF Enemie3::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void Enemie3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/iconfinder_Silver_Fern_71214.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Enemie3::setPosy(float value)
{
    posy = value;
}
