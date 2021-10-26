#ifndef ENEMIES2_H
#define ENEMIES2_H
#include "player.h"

class Enemies2:public QGraphicsItem
{
public:
    Enemies2(float r,float x, float y );
    Enemies2(float x, float y, float masa_, float Radio_, float vx_, float vy_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void velocidad();
    void aceleracion(float masa, float Xo, float Yo);
    void posicion();
private:
    float posx=rand()%3, posy=rand()%2, radio=rand()%2, masa=rand()%3, vx=rand()%5, vy=rand()%5,ax=rand()%5,ay=rand()%2;

};

#endif // ENEMIES2_H
