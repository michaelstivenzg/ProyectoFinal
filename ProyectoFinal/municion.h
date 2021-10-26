#ifndef MUNICION_H
#define MUNICION_H

#include <math.h>
#include <QPainter>
#include <QGraphicsItem>
#include <QTimer>
#include "player.h"

class Municion:public QGraphicsItem,public QObject//hereda de QGraphicsItem para el metodo de las colisiones
{
    double amplitud=50;
    double posx=160;
    double posy=0;
    double radio;
public:
    Municion();
    Municion(double r, double _x, double _y);//solo estos datos para hacer la implmetacion de la grafica con estos valores
    ~Municion();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void posicionmunicion();
    double getPosy() const;
    void setPosy(double value);
    double getPosx() const;
    void setPosx(double value);
    void ActualizarPos();
};

#endif // MUNICION_H
