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
private slots:
    void update();

};
#endif // MAINWINDOW_H
