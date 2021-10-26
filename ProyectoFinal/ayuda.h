#ifndef AYUDA_H
#define AYUDA_H
#include "player.h"

class Ayuda:public QGraphicsItem
{
public:
    Ayuda(float r, float x, float y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    float radio;
    float posx;
    float posy;
};

#endif // AYUDA_H
