#include "enemies.h"

Enemies::Enemies(float r, float x, float y)
{
    radio=r;
    posx=x;
    posy=y;
}

Enemies::~Enemies()
{
    delete this;
}

QRectF Enemies::boundingRect() const
{
    return QRectF(posx,posy,radio,radio);
}

void Enemies::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/flying_saucer.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Enemies::position()
{
    setPos(x()+120,amplitud*sin(x()+0.000000000001));
    if(x()>1800){
       setPos(-600,500);       
    }
}

void Enemies::position_2()
{
    setPos(x()+120,amplitud*sin(x()+0.000000000001));
    if(x()>1800){
       setPos(-700,600);
       setPos(x()+120,amplitud*sin(x()+0.000000000001));
    }
}


