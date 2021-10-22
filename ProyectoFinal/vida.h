#ifndef VIDA_H
#define VIDA_H

#include <math.h>
#include <QPainter>
#include <QGraphicsItem>
#include "player.h"
#define g 9.8
#define delta 0.2


class Vida:public QGraphicsItem,public QObject
{
    double v_ini=80;
    double v_x=80;
    double v_y=80;
    double angulo=75;
    double posx=-80;
    double posy=0;
    double radio;

public:
    Vida();
    Vida(double r, double _x, double _y);
    ~Vida();
    void CalVelocidad();
    void CalPosicion();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double getPosx() const;
    void setPosx(double value);
    double getPosy() const;
    void setPosy(double value);
};

#endif // VIDA_H
