#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <qevent.h>
#include "esferas.h"
#include "obstaculoa.h"
#include "obstaculob.h"
#include "esferasespeciales.h"
#include "player.h"
namespace Ui {
class Multiplayer;
}

class Multiplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = nullptr);
    ~Multiplayer();
    Multiplayer(float r, float x, float y);
    void move_yNegativo();
    void move_yPositivo();
    void move_xNegativo();
    void move_xPositivo();
    void keyPressEvent(QKeyEvent *event);
private slots:
    void on_pushButton_clicked();
    void actualizar();

private:
    int objx=0, objy=0, ancho=0, alto=0;
    float posx, posy, radio;
    Ui::Multiplayer *ui;
    Multiplayer *lead1;
    QGraphicsScene *escena;
    QTimer *timer;
    QList <esferas *> bolas;
    QList <esferasEspeciales *> bolasEspeciales;
    QVector <ObstaculoA*> obstaculosA; // crea otra lista de objetos  para los obstaculos tipo A
    QVector <ObstaculoB*> obstaculosB; // crea otra lista de objetos  para los obstaculos tipo B
    //Vida *vida1;

};

#endif // MULTIPLAYER_H
