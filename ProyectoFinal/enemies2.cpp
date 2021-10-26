#include "enemies2.h"

Enemies2::Enemies2(float r, float x, float y)
{
    radio=r;
    posx=x;
    posy=y;
}

Enemies2::Enemies2(float x, float y, float masa_, float Radio_, float vx_, float vy_)
{
    posx=x;
    posy=y;
    masa=masa_;
    radio=Radio_;
    vx=vx_;
    vy=vy_;
}

QRectF Enemies2::boundingRect() const
{
    return QRectF(posx,posy,radio,radio);
}

void Enemies2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/MOON.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Enemies2::velocidad()
{
    vx=vx+(ax*Ti);
    vy=vy+(ay*Ti);
}

void Enemies2::aceleracion(float masa, float Xo, float Yo)
{
    int Gravedad=1;
    float px=Xo-posx;
    float py=Yo-posy;
    float Ang=atan2(px,py);
    float Radio=((px*px)+(py*py));
    ax=(Gravedad*masa*cos(Ang))/Radio;
    ay=(Gravedad*masa*sin(Ang))/Radio;
}

void Enemies2::posicion()
{
    posx=posx+(vx*Ti)+((ax*(Ti*Ti))/2);
    posy=posy+(vy*Ti)+((ay*(Ti*Ti))/2);
    if(posx>400){
        posx/=10;
    }
    if(posy>250){
        posy/=10;
    }
    setPos(posx,posy);   
}
