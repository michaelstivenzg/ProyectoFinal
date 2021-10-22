#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)    : QMainWindow(parent)    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Wars");//Titulo a la ventana
    this->setWindowFlags(Qt::Window|Qt::MSWindowsFixedSizeDialogHint);//para que no se pueda modificar el tamaño de la ventana, ni siquiera de sus bordes e incluso se desabiliten sus botones de cerrar. Para bloquear minimizar se agraga esto:|Qt::WindowMinimizeButtonHint
    scene=new QGraphicsScene (this);//para implementar la escena
    scene->setSceneRect(0,0,1000,540);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/imagenes/FondoCampo.jpg"));
    ui->progressBar_2->setRange(0,100);//barra que da la informacion de las municiones
    ui->progressBar->setRange(0,100);//barra que da la informacion de la cantida de vida
    lead=new Player(45,0,0);
    scene->addItem(lead);
    for(int i =0;i<2;i++){
        enemies.push_back(new Enemies(100,rand()%1000,10));
        scene->addItem(enemies.at(i));
    }
    for(int i=0;i<50;i++){
        bullets.push_back(new Bullet(18,lead->getPosx(),lead->getPosy()));
        scene->addItem(bullets.at(i));
    }
    for(int i=0;i<5;i++){
        vidaAyuda.push_back(new Vida(10,-25,100+rand()%200));//se agraga el elemento con su tamaño, posicion en x y posicion en y de forma aleatoria  entre los rangos indicados
        scene->addItem(vidaAyuda.at(i));//se agrega el elemento a la escena
    }
    l1=new QGraphicsLineItem(1060,-100,1060,1600);//derecha vertical
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
    for(int i=0;i<bullets.size();i++){
        delete bullets[i];
    }
    for(int i=0;i<enemies.size();i++){
        delete enemies[i];
    }
}

void MainWindow::update()
{

    if(flag==true){
        nivel=1;
        enemies.at(1)->position();
        enemies.at(0)->position_2();
        for (int i=0;i<bullets.size();i++){
            bullets.at(i)->move();
        }
        for(int i=0;i<enemies.size();i++){
            if(enemies[i]->collidesWithItem(l1)){
                niveldevida-=5;
                enemies[i]->setPos(-50,100);
            }
        }

        if(niveldevida==60){
            vidaAyuda.at(0)->CalPosicion();
        }
        else if(niveldevida==50){
            vidaAyuda.at(1)->CalPosicion();
        }
        else if(niveldevida==40){
            vidaAyuda.at(2)->CalPosicion();
        }
        else if(niveldevida==30){
            vidaAyuda.at(3)->CalPosicion();
        }
        else if(niveldevida==20){
            vidaAyuda.at(4)->CalPosicion();
        }
        for(int i=0;i<vidaAyuda.size();i++){
            if(lead->collidesWithItem(vidaAyuda.at(i))){
                vidaAyuda.at(i)->setPos(10000,10000);
                niveldevida+=5;
                if(niveldevida>100){
                    niveldevida=100;
                }
            }
        }
        if(niveldevida<=0){
            niveldevida=0;
            QString texto="Perdiste,regresa al menu para volver a iniciar!!!!! \n";
            QMessageBox::about(this,"Advertencia!!",texto);
            flag2=true;
            timer->stop();
        }
        if(100-2*counter_bullets<=0){
            QString texto="Perdiste, te quedaste sin municiones, regresa al menu para volver a iniciar!!!!! \n";
            QMessageBox::about(this,"Advertencia!!",texto);
            flag2=true;
            timer->stop();
        }
        for(int i=0;i<bullets.size();i++){
            if(bullets[i]->collidesWithItem(enemies[0])){
                enemies[0]->setPos(-100,rand()%600);
                siguiente_nivel++;
            }
            else if(bullets[i]->collidesWithItem(enemies[1])){
                enemies[0]->setPos(-100,rand()%700);
                siguiente_nivel++;
            }
        }
        if(siguiente_nivel >=100){
            QString texto="Felicidades, pasas al nivel 2!!!!! \n";
            QMessageBox::about(this,"Advertencia!!",texto);
            nivel=2;
            flag2=false;
            timer->stop();
            for(int i=0;i<enemies.size();i++){
                enemies[i]->setPos(10000,-10000);
            }
        }
    }

    if (nivel==2){
        flag=false;
        timer->start();
        for(int i =0;i<bullets.size();i++){
            bullets.at(i)->setPos(10000,-10000);
        }
        for(int i=0;i<enemies.size();i++){
            enemies[i]->setPos(10000,-10000);
        }
    }
    ui->progressBar->setValue((100-2*counter_bullets));
    ui->progressBar_2->setValue(niveldevida);
    //qDebug()<<vidaAyuda.at(0)->getPosx()<<vidaAyuda.at(0)->getPosy()<<endl;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_S){
        lead->move_yPositivo();
    }
    else if(event->key()==Qt::Key_W){
        lead->move_yNegativo();;
    }
    else if(event->key()==Qt::Key_A){
        lead-> move_xNegativo();
    }
    else if(event->key()==Qt::Key_D){
        lead->move_xPositivo();
    }
    else if(event->key()==Qt::Key_Space){
        for(int i=0;i<bullets.size();i++){
            if(counter_bullets==i){
                bullets.at(i)->setPosx(lead->getPosx()+13);
                bullets.at(i)->setPosy(lead->getPosy());
                bullets.at(i)->move();
            }
        }
        counter_bullets++;
    }
}

void MainWindow::name(string a)
{
    user=a;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(flag2==false){
        timer->start();
    }
    event->accept();
}

void MainWindow::on_save_level_clicked()
{
    ofstream file;
    file.open(user,ios::trunc);
    if(file.is_open()){
        file<<counter_bullets<<","<<nivel<<","<<niveldevida<<endl;
    }
}

void MainWindow::on_pushButton_clicked()
{
    timer->stop();
}

void MainWindow::on_pushButton_upload_clicked()
{

}


void MainWindow::on_pushButton_pause_clicked()
{
    timer->stop();
}
