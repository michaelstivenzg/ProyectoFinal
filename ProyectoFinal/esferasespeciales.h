#ifndef ESFERASESPECIALES_H
#define ESFERASESPECIALES_H

#define G 10
#define delta 0.1

#include <QGraphicsItem>
#include <QPainter>
#include "math.h"
class esferasEspeciales:public QGraphicsItem
{
    float radio,posx,posy,velx,vely,vel_ini,masa,friccion,restitucion,magnitud,ax=5,ay=10,angulo;
public:
    esferasEspeciales();
    esferasEspeciales(float r,float _x,float _y,float veli,float m,float vx ,float vy ,float f,float res );//x,y,v,r,m,vy,f,res,vx
    void ActualizaPos();
    void CalculaVelocidad();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);
};

#endif // ESFERASESPECIALES_H
