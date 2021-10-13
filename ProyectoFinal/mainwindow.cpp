#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    this->setWindowFlags(Qt::Window|Qt::MSWindowsFixedSizeDialogHint);//para que no se pueda modificar el tamaño de la ventana, ni siquiera de sus bordes e incluso se desabiliten sus botones de cerrar. Para bloquear minimizar se agraga esto:|Qt::WindowMinimizeButtonHint
    scene=new QGraphicsScene (this);//para implementar la escena
    scene->setSceneRect(0,0,1000,540);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/imagenes/FondoCampo.jpg"));
    ui->progressBar_2->setRange(0,100);//barra que da la informacion de las municiones
    ui->progressBar->setRange(0,100);//barra que da la informacion de la cantida de vida
    lead=new Player(45,0,270);
    scene->addItem(lead);
    for(int i =0;i<2;i++){
        enemies.push_back(new Enemies(100,rand()%1000,10));
        scene->addItem(enemies.at(i));
    }
    timer=new QTimer;
    timer->start(50);
    connect(timer,SIGNAL(timeout()),this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
    delete lead;
}

void MainWindow::update()
{
    enemies.at(1)->position();
    enemies.at(0)->position_2();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W){
        lead->move_yPositivo();
    }
    else if(event->key()==Qt::Key_S){
        lead->move_yNegativo();;
    }
    else if(event->key()==Qt::Key_A){
        lead-> move_xNegativo();
    }
    else if(event->key()==Qt::Key_D){
        lead->move_xPositivo();
    }
    event->accept();
}

