#include "ayuda.h"

Ayuda::Ayuda(float r, float x, float y)
{
    radio=r;
    posx=x;
    posy=y;
}

QRectF Ayuda::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void Ayuda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/iconfinder_golden star.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

