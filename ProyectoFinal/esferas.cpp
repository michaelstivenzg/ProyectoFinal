#include "esferas.h"

float esferas::getRadio() const
{
    return radio;
}

void esferas::setRadio(float value)
{
    radio = value;
}

float esferas::getPosx() const
{
    return posx;
}

void esferas::setPosx(float value)
{
    posx = value;
}

float esferas::getPosy() const
{
    return posy;
}

void esferas::setPosy(float value)
{
    posy = value;
}

float esferas::getVelx() const
{
    return velx;
}

void esferas::setVelx(float value)
{
    velx = value;
}

float esferas::getVely() const
{
    return vely;
}

void esferas::setVely(float value)
{
    vely = value;
}

float esferas::getVel_ini() const
{
    return vel_ini;
}

void esferas::setVel_ini(float value)
{
    vel_ini = value;
}

float esferas::getMasa() const
{
    return masa;
}

void esferas::setMasa(float value)
{
    masa = value;
}

float esferas::getFriccion() const
{
    return friccion;
}

void esferas::setFriccion(float value)
{
    friccion = value;
}

float esferas::getRestitucion() const
{
    return restitucion;
}

void esferas::setRestitucion(float value)
{
    restitucion = value;
}

float esferas::getMagnitud() const
{
    return magnitud;
}

void esferas::setMagnitud(float value)
{
    magnitud = value;
}

float esferas::getAx() const
{
    return ax;
}

void esferas::setAx(float value)
{
    ax = value;
}

float esferas::getAy() const
{
    return ay;
}

void esferas::setAy(float value)
{
    ay = value;
}

esferas::esferas(float r, float _x, float _y, float veli, float m, float vx, float vy, float f, float res)
{
    radio=r;
    posx=_x;
    posy=_y;
    vel_ini=veli;
    masa=m;
    velx=vx;
    vely=vy;
    friccion=f;
    restitucion=res;
}

void esferas::ActualizaPos()
{
    CalculaVelocidad();

    if(posx-radio<=-55)//para la lateral izquierda
        velx=-restitucion*velx;
    if(posx+radio>=530)//para la lateral derecha
        velx=-restitucion*velx;
    if(posy-radio<-40)
        vely=-restitucion*vely;
    //if(posy+radio>=280)  //condicion para que desaparezcan los objetos cuando tocan el piso
    //posy=600;
    posx=posx+((velx*(delta*delta))+ (ax*(delta*delta)))*0.5;
    posy=posy+((vely*(delta*delta))+ (ay*(delta*delta)))*0.5;
    setPos(posx,posy);
}

void esferas::CalculaVelocidad()
{
    angulo=atan2(vely,velx);
    magnitud= pow((velx*velx)+(vely*vely),2);//potencia
    ax = -(((friccion*(magnitud)))*((radio*radio)/masa )*cos(angulo));
    ay = -(((friccion*(magnitud)))*((radio*radio)/masa )*sin(angulo))+G;
    vely=vely+ay*delta;
    velx=velx+ax*delta;
}

QRectF esferas::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void esferas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::green);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/imagenes/MOON.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

