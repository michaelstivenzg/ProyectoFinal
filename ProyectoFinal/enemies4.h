#ifndef ENEMIES4_H
#define ENEMIES4_H
#include "player.h"
#include "vida.h"
class Enemies4:public QGraphicsItem
{
public:
    Enemies4(float r, float x ,float y);
    Enemies4();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void CalVelocidad();
    void CalPosicion();
    void setPosx(float value);

    float getPosy() const;
    void setPosy(float value);

private:
    float radio, posx=-80,posy=0;
    float v_ini=80;
    float v_x=80;
    float v_y=80;
    float angulo=75;

};

#endif // ENEMIES4_H
