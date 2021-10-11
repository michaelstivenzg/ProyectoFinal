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
    lead=new Player(45,500,270);
    scene->addItem(lead);
}

MainWindow::~MainWindow()
{
    delete ui;
}

