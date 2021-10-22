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
    void name(string a);//funcion que  recibe un string para ayudar a recibir el archivo txt donde se almacena los datos del jugador
    void mousePressEvent(QMouseEvent *event) override;
private:
    Ui::MainWindow *ui;
    Player *lead;
    QTimer* timer;//timer de la escena
    QVector<Enemies*> enemies;
    QVector<Bullet*> bullets;
    QVector<Vida*> vidaAyuda;
    QGraphicsLineItem* l1;//rectas para identificar las colisiones de los enemigos y de las balas
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    QGraphicsLineItem* l5;
    QGraphicsLineItem* l6;
    int counter_bullets=0,niveldevida=100,siguiente_nivel=0,nivel=0;
    string user,valores;
    bool flag =true,flag2=false;
private slots:
    void update();
    void on_save_level_clicked();
    void on_pushButton_clicked();
    void on_pushButton_upload_clicked();
    void on_pushButton_pause_clicked();
};
#endif // MAINWINDOW_H
