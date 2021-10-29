#include "esferasespeciales.h"

float esferasEspeciales::getPosx() const
{
    return posx;
}

void esferasEspeciales::setPosx(float value)
{
    posx = value;
}

float esferasEspeciales::getPosy() const
{
    return posy;
}

void esferasEspeciales::setPosy(float value)
{
    posy = value;
}

esferasEspeciales::esferasEspeciales()
{

}

esferasEspeciales::esferasEspeciales(float r, float _x, float _y, float veli, float m, float vx, float vy, float f, float res)
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

void esferasEspeciales::ActualizaPos()
{
    CalculaVelocidad();

    if(posx-radio<=-55)//para la lateral izquierda
        velx=-restitucion*velx;
    if(posx+radio>=530)//para la lateral derecha
        velx=-restitucion*velx;
    if(posy-radio<-40)
        vely=-restitucion*vely;
    if(posy+radio>=280)  //condicion para que desaparezcan los objetos cuando tocan el piso
        posy=600;
    posx=posx+((velx*(delta*delta))+ (ax*(delta*delta)))*0.5;
    posy=posy+((vely*(delta*delta))+ (ay*(delta*delta)))*0.5;
    setPos(posx,posy);
}

void esferasEspeciales::CalculaVelocidad()
{
    angulo=atan2(vely,velx);
    magnitud= pow((velx*velx)+(vely*vely),2);//potencia
    ax = -(((friccion*(magnitud)))*((radio*radio)/masa )*cos(angulo));
    ay = -(((friccion*(magnitud)))*((radio*radio)/masa )*sin(angulo))+G;
    vely=vely+ay*delta;
    velx=velx+ax*delta;
}

QRectF esferasEspeciales::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void esferasEspeciales::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/imagenes/ship_enemie.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
