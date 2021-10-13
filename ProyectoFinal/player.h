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
#include <QKeyEvent>
#include <QVector>
#include <time.h>
#include <math.h>
#include <QtDebug>
#include "enemies.h"
#define PI 3.14159265358979323846264338
#define G 10
#define dt 0.2

class Player: public QGraphicsItem,public QObject
{
public:
    Player(float r, float x, float y);
    ~Player();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void move();
    void SetVel(float x, float y);
    void setPoint(double x, double y);        //metodo para asignar la posicion (en X y en Y)
    void actualizar(double dt_);
    void move_yNegativo();
    void move_yPositivo();
    void move_xNegativo();
    void move_xPositivo();

private:
    float posx=0, posy=0,radio;
    float masa;
    float vx;                       //velocidad en X
    float vy;                       //velocidad en Y
    float ax;                       //aceleracion en X
    float ay;                       //aceleracion en Y
    float E;                        //Coeficiente de restitucion
    float K;
};

#endif // PLAYER_H
