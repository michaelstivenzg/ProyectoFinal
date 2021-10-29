#include "multiplayer.h"
#include "ui_multiplayer.h"

QPainter *paint;

Multiplayer::Multiplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Multiplayer)
{
    ui->setupUi(this);
    setWindowTitle("Simulacion lanetaria - Multiplayer");//Titulo a la ventana
    escena=new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);
    timer =new QTimer;
    escena->setBackgroundBrush(QPixmap(":/imagenes/planeta.jpg").scaled(1000,600));
    srand(time(NULL));//para inicializar los números aleatorios incluir esto
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
}

void Multiplayer::keyPressEvent(QKeyEvent *event)
{
    timer->start(50);
    objx=5+rand()%900;
    objy=5+rand()%600;
    ancho=19+rand()%50;
    alto=19+rand()%50;
    if(bolas.size()%1==0){//Condicional para que aparezcan obstaculos aleatoriamente cada 7 bolas
        obstaculosA.push_back(new ObstaculoA(objx,objy,ancho,alto));//es el azul
        escena->addItem(obstaculosA.back());
    }
}

Multiplayer::~Multiplayer()
{
    delete ui;
}

void Multiplayer::on_pushButton_clicked()
{
    timer->start(50);
    double r = 5+rand()%(31-5);
    double x = 20+rand()%(600-20);
    double y = 2+rand()%(2-1);
    double v = 0+rand()%300;
    double m= 50+rand()%(600);
    double vx= -200+rand()%400;
    double vy= -300+rand()%600;
    double f= rand()%10/1000;
    double res=0.5;
    res+=rand()%5/10;
    bolas.push_back(new esferas(r,x,y,v,m,vx,vy,f,res));  // se adiciona un nuevo objeto a la lista y se pone al final de la lista
    bolas.back()->ActualizaPos();
    escena->addItem(bolas.back());

    objx=5+rand()%900;
    objy=5+rand()%600;
    ancho=19+rand()%50;
    alto=19+rand()%50;
    if(bolas.size()%7==0){//Condicional para que aparezcan obstaculos aleatoriamente cada 7 bolas
        obstaculosA.push_back(new ObstaculoA(objx,objy,ancho,alto));//es el azul
        escena->addItem(obstaculosA.back());
    }
    if(bolas.size()%9==0){//Condicional para que aparezcan obstaculos aleatoriamente cada 9 bolas
        obstaculosB.push_back(new ObstaculoB(objx,objy,ancho,alto));//es el amarillo
        escena->addItem(obstaculosB.back());
    }

    double r2 = 5+rand()%(31-5);
    double x2 = 20+rand()%(600-20);
    double y2 = 2+rand()%(2-1);
    double v2= 0+rand()%300;
    double m2= 50+rand()%(600);
    double vx2= -200+rand()%400;
    double vy2= -300+rand()%600;
    double f2= rand()%10/1000;
    double res2=0.5;
    res2+=rand()%5/10;

    if(bolas.size()%11==0){//Condicional para que aparezcan bolas especiales aleatoriamente cada 11 bolas
        bolasEspeciales.push_back((new esferasEspeciales(r2,x2,y2,v2,m2,vx2,vy2,f2,res2)));//la bola roja
        bolasEspeciales.back()->ActualizaPos();
        escena->addItem(bolasEspeciales.back());
    }
    timer->start(10);
}

void Multiplayer::actualizar()
{
    for(QList <esferas *> :: iterator it= bolas.begin();it!=bolas.end();++it){
        (*it)->ActualizaPos();
    }
    for(QList <esferasEspeciales *> :: iterator it= bolasEspeciales.begin();it!=bolasEspeciales.end();++it){
        (*it)->ActualizaPos();
    }
    //bola especial con rectangulo azul
    for(QVector<ObstaculoA*>:: iterator iteradorRect=obstaculosA.begin();iteradorRect!=obstaculosA.end();++iteradorRect){
        for(QList <esferasEspeciales *> :: iterator it= bolasEspeciales.begin();it!=bolasEspeciales.end();++it){
            if((*it)->collidesWithItem((*iteradorRect))){
                (*iteradorRect)->setPos(2000,y());
                (*it)->setPosx(2000);
            }

        }
    }
    //bola especial con rectangulo amarillo
    for(QVector<ObstaculoB*>:: iterator iteradorRect1=obstaculosB.begin();iteradorRect1!=obstaculosB.end();++iteradorRect1){
        for(QList <esferasEspeciales *> :: iterator it= bolasEspeciales.begin();it!=bolasEspeciales.end();++it){
            if((*it)->collidesWithItem((*iteradorRect1))){
                (*iteradorRect1)->setPos(20000,y());
                (*it)->ActualizaPos();
                (*it)->setPosx(20000);
            }
        }
    }
    //colision de las esferas normales con el obtaculo azul, para que aceleren las esferas
    for(QList <esferas *> :: iterator it= bolas.begin();it!=bolas.end();++it){
        for(QVector<ObstaculoA*>:: iterator iteradorRect=obstaculosA.begin();iteradorRect!=obstaculosA.end();++iteradorRect){
            if((*it)->collidesWithItem((*iteradorRect))){
                (*it)->setAx(100);
                (*it)->setAy(100);
                (*it)->setVelx(300);
                (*it)->setVely(300);
            }
        }
    }
    //colision de las esferas normales con el obstaculo amarillo para que desaceleran las esferas
    for(QList <esferas *> :: iterator it= bolas.begin();it!=bolas.end();++it){
        for(QVector<ObstaculoB*>:: iterator iteradorRect=obstaculosB.begin();iteradorRect!=obstaculosB.end();++iteradorRect){
            if((*it)->collidesWithItem((*iteradorRect))){
                (*it)->setAx(-100);
                (*it)->setAy(-100);
                (*it)->setVelx(5);
                (*it)->setVely(5);
            }
        }
    }
}
