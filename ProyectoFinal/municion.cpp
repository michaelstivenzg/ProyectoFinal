#include "municion.h"

double Municion::getPosy() const
{
    return posy;
}

void Municion::setPosy(double value)
{
    posy = value;
}

double Municion::getPosx() const
{
    return posx;
}

void Municion::setPosx(double value)
{
    posx = value;
}

Municion::Municion()
{

}

Municion::Municion(double r, double _x, double _y)
{
    radio=r;
    posx=_x;
    posy=_y;
}

Municion::~Municion()
{
    delete this;
}

QRectF Municion::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void Municion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/iconfinder_Silver_Fern_71214.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Municion::posicionmunicion()//MOVIMIENTO SEÑOIDAL
{
    setPos(x()+49,amplitud*sin(x()+0.0000001));
}

