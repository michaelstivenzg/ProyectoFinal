#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();    
    QGraphicsScene *scene;//para crear la escena
    void keyPressEvent(QKeyEvent *event);// es la funcion de detencion del teclado

private:
    Ui::MainWindow *ui;
    Player *lead;
    QTimer* timer;//timer de la escena
    QVector<Enemies*> enemies;
    QGraphicsLineItem* l1;//rectas para identificar las colisiones de los enemigos y de las balas
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    QGraphicsLineItem* l5;
    QGraphicsLineItem* l6;
private slots:
    void update();    
};
#endif // MAINWINDOW_H
