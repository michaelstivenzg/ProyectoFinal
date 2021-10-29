#include "enemies4.h"

Enemies4::Enemies4(float r, float x, float y)
{
    radio=r;
    posx=x;
    posy=y;
}

Enemies4::Enemies4()
{
    v_ini=0;
    v_x=0;
    v_y=0;
    angulo=0;
    posx=0;
    posy=0;
}

QRectF Enemies4::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void Enemies4::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/ship_enemie.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Enemies4::CalVelocidad()
{
    v_x=v_ini*cos(angulo);
    v_y= v_ini*sin(angulo)+g*delta;
    v_ini =(sqrt(pow(v_x,2)+pow(v_y,2)));
}

void Enemies4::CalPosicion()
{
    CalVelocidad();
    posx=posx+v_x*delta;
    posy=posy+v_y*delta+(0.5*g*delta*delta);
    angulo=atan2(v_y,v_x);
    setPos(posx,posy);
}

void Enemies4::setPosx(float value)
{
    posx = value;
}

float Enemies4::getPosy() const
{
    return posy;
}

void Enemies4::setPosy(float value)
{
    posy = value;
}
