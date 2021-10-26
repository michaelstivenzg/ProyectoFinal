#ifndef BULLET_H
#define BULLET_H
#include "player.h"

class Bullet: public QObject,public QGraphicsItem
{
public:
    Bullet(float r, float x, float y);
    void move();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float getPosx() const;
    void setPosx(float value);

    float getPosy() const;
    void setPosy(float value);

private:
    float radio;
    float posx=0;
    float posy=0;
    float speedY;
    float accelY;
};

#endif // BULLET_H

