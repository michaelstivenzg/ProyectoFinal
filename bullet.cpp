#include "bullet.h"

Bullet::Bullet(float r, float x, float y)
{
    radio=r;
    posx=x;
    posy=y;
}

void Bullet::move()
{
    accelY=20;
    speedY=-50;
    posy+=(speedY*dt)-(0.5*accelY*dt*dt);
    setPos(posx,posy);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/bullet.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

float Bullet::getPosx() const
{
    return posx;
}

void Bullet::setPosx(float value)
{
    posx = value;
}

float Bullet::getPosy() const
{
    return posy;
}

void Bullet::setPosy(float value)
{
    posy = value;
}
