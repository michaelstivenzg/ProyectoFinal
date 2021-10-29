#ifndef ENEMIE3_H
#define ENEMIE3_H
#include "player.h"
class Enemie3:public QGraphicsItem
{

public:
    Enemie3(float r,float x, float y);
    void posicion();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPosy(float value);

private:
    float posx;
    float posy;
    float radio;
};

#endif // ENEMIE3_H
