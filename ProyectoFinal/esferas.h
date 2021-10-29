#ifndef ESFERAS_H
#define ESFERAS_H

#define G 10
#define delta 0.1
#include "math.h"
#include <QGraphicsItem>
#include <QPainter>


class esferas:public QGraphicsItem
{
    float radio,posx,posy,velx,vely=10,vel_ini,masa,friccion,restitucion,magnitud,ax=5,ay=10,angulo;

public:
    esferas(float r,float _x,float _y,float veli,float m,float vx ,float vy ,float f,float res );//x,y,v,r,m,vy,f,res,vx
    void ActualizaPos();
    void CalculaVelocidad();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float getRadio() const;
    void setRadio(float value);
    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);
    float getVelx() const;
    void setVelx(float value);
    float getVely() const;
    void setVely(float value);
    float getVel_ini() const;
    void setVel_ini(float value);
    float getMasa() const;
    void setMasa(float value);
    float getFriccion() const;
    void setFriccion(float value);
    float getRestitucion() const;
    void setRestitucion(float value);
    float getMagnitud() const;
    void setMagnitud(float value);
    float getAx() const;
    void setAx(float value);
    float getAy() const;
    void setAy(float value);
};

#endif // ESFERAS_H

