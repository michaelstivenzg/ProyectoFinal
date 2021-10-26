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
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include "ayuda.h"
#include "enemies2.h"
#include "municion.h"
#include "vida.h"
#include "enemies.h"
#include "bullet.h"
#include "login.h"
#include "string"
#define PI 3.14159265358979323846264338
#define G 10
#define dt 0.1
#define Ti 2

using namespace std;

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

    float getPosx() const;
    void setPosx(float value);

    float getPosy() const;
    void setPosy(float value);

private:
    float posx=450, posy=370,radio;
    float masa;
    float vx;                       //velocidad en X
    float vy;                       //velocidad en Y
    float ax;                       //aceleracion en X
    float ay;                       //aceleracion en Y
    float E;                        //Coeficiente de restitucion
    float K;
};

#endif // PLAYER_H

