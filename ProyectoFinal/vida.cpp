#include "vida.h"

double Vida::getPosx() const
{
    return posx;
}

void Vida::setPosx(double value)
{
    posx = value;
}

double Vida::getPosy() const
{
    return posy;
}

void Vida::setPosy(double value)
{
    posy = value;
}

Vida::Vida()
{
    v_ini=0;
    v_x=0;
    v_y=0;
    angulo=0;
    posx=0;
    posy=0;
}

Vida::Vida(double r, double _x, double _y)
{
    radio=r;
    posx=_x;
    posy=_y;
}

Vida::~Vida()
{
    delete this;
}

void Vida::CalVelocidad()//calcula la velocidad en tiro parabolico
{
    v_x=v_ini*cos(angulo);
    v_y= v_ini*sin(angulo)+g*delta;
    v_ini =(sqrt(pow(v_x,2)+pow(v_y,2)));
}

void Vida::CalPosicion()//calcula la pocion en xey en tiro parabolico
{
    CalVelocidad();
    posx=posx+v_x*delta;
    posy=posy+v_y*delta+(0.5*g*delta*delta);
    angulo=atan2(v_y,v_x);
    setPos(posx,posy);
}

QRectF Vida::boundingRect() const//rodea al item
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void Vida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//carga la imagen del item
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/iconfinder_golden star.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

