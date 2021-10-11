#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QWidget>

class Player: public QGraphicsItem,public QObject
{
public:
    Player(float r, float x, float y);
    ~Player();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    float posx, posy,radio;
};

#endif // PLAYER_H
