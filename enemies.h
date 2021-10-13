#ifndef ENEMIES_H
#define ENEMIES_H
#include "player.h"


class Enemies:public QGraphicsItem//permite usar setPos
{
public:
    Enemies(float r ,float x ,float y);
    ~Enemies();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void position();
    void position_2();

private:
    float amplitud=100;
    float posx=160;
    float posy=150;
    float radio;
};

#endif // ENEMIES_H
