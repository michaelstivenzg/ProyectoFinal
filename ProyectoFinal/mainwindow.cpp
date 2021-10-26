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
    for(int i =0;i<2;i++){//platillos voladores del nivel uno
        enemies.push_back(new Enemies(20+rand()%100,-50+rand()%(-40),10));//se agrega las caracteristicas del "personaje o elemento"
        scene->addItem(enemies.at(i));//se agrega a la escena el item i
    }
    for(int i=0;i<50;i++){//municiones para el primer nivel
        bullets.push_back(new Bullet(18,600,600));
        scene->addItem(bullets.at(i));
    }
    for(int i=0;i<5;i++){//vector de cinco elementos que aumental el nivel de vida en el momento de la colision
        vidaAyuda.push_back(new Vida(10,-25,100+rand()%200));//se agraga el elemento con su tamaño, posicion en x y posicion en y de forma aleatoria  entre los rangos indicados
        scene->addItem(vidaAyuda.at(i));//se agrega el elemento a la escena
    }
    l1=new QGraphicsLineItem(1060,-100,1060,1600);//derecha vertical para detectar las colisiones de los platillos voladores del primer nivel
    for(int i=0;i<5;i++){//para recarcgar la vida cuando este en nivel 30 40 50 o 60, en el nivel 1
        municion.push_back(new Municion(15,-30,1+rand()%(300)));
        scene->addItem(municion.at(i));
    }
    for (int i=0;i<5 ;i++ ) {//para los enemigos estilo planeta del nivel dos
        enemies2.push_back(new Enemies2(20+rand()%40,-90,0));
    }
    for(int i=0;i<20;i++ ){//son los elementos estilo estrella para hacer contacto con el jugador ppal, en el segundo nivel
        ayuda.push_back(new Ayuda(+rand()%20,-50,-50));
        scene->addItem(ayuda.at(i));
    }

    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this, SLOT(update()));//conexion del timer y la funcion  update
}

MainWindow::~MainWindow()//para eleminar elementos de la memoria al cerrar el programa
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
                vidaAyuda.at(i)->setPos(-500,-500);
                scene->removeItem(vidaAyuda.at(i));
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
                scene->removeItem(bullets.at(i));
                siguiente_nivel+=5;
            }
            else if(bullets[i]->collidesWithItem(enemies[1])){
                enemies[0]->setPos(-100,rand()%700);
                scene->removeItem(bullets.at(i));
                siguiente_nivel+=5;
            }
        }
        if(siguiente_nivel >=100){
            siguiente_nivel=0;
            QString texto="Felicidades, pasas al nivel 2!!!!! \n";
            QMessageBox::about(this,"Felicidades!!",texto);
            nivel=2;
            flag2=false;
            timer->stop();
            for(int i=0;i<enemies.size();i++){
                scene->removeItem(enemies[i]);
            }
        }
    }
/*///////////////////////////////////////////////////Nivel Dos*///////////////////////////////////////////////////////////////////////////////////////
    if (nivel==2){
        flag=false;
        if(flag3==false){
            for(int i=0;i<ayuda.size();i++){
               ayuda.at(i)->setPos(50+rand()%900, rand()%450);
               flag3=true;
            }
        }
        scene->setBackgroundBrush(QPixmap(":/imagenes/FondoMenu.jpg").scaled(1300,750));
        for(int i=0;i<bullets.size();i++){
            bullets.at(i)->move();
        }
        inicialmunicion++;
        if(counter_municion<5 && inicialmunicion==6){
            counter_municion++;
            inicialmunicion=0;
        }
        for(int i=0;i<counter_municion;i++){
            scene->addItem(enemies2.at(i));
            enemies2.at(i)->posicion();
        }
        for(int i=0;i<ayuda.size();i++){
            if(lead->collidesWithItem(ayuda.at(i))){
                scene->removeItem(ayuda.at(i));
                ayuda.at(i)->setPos(2000,1000);
                siguiente_nivel+=5;
                niveldevida+=5;
                qDebug()<<"siguiente nivel es "<<siguiente_nivel<<endl;
                qDebug()<<"el tamaño de el vector ayuda es "<<ayuda.size()<<endl;
                qDebug()<<"el tamaño de el vector bala es "<<bullets.size()<<endl;
                qDebug()<<"el tamaño de el vector Vidaayuda es "<<vidaAyuda.size()<<endl;
            }
        }
        for(int i=0;i<enemies2.size();i++){
            if(lead->collidesWithItem(enemies2.at(i))){
                enemies2.at(i)->setPos(-100,0);
                niveldevida-=1;
            }
        }
        if(niveldevida<=0){
            niveldevida=0;
            QString texto="Perdiste,regresa al menu para volver a iniciar!!!!! \n";
            QMessageBox::about(this,"Advertencia!!",texto);
            flag2=true;
            timer->stop();
        }
        if(siguiente_nivel>=70){
            siguiente_nivel=0;
            QString texto="Felicidades, pasas al nivel 3!!!!! \n";
            QMessageBox::about(this,"En hora buena!!",texto);
            nivel=3;
            timer->stop();
        }
    }
    if(nivel==3){
        for (int i=0;i<bullets.size();i++){
            bullets.at(i)->move();
        }
        if(flag4==false){
             scene->setBackgroundBrush(QPixmap(":/imagenes/fondo_view.jpg").scaled(1000,600));
        }
    }
    ui->progressBar->setValue((100-2*counter_bullets));
    ui->progressBar_2->setValue(niveldevida);
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
    if(flag==true){
        timer->start(70);
    }
    else if(flag==false){
        timer->start(70);
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

void MainWindow::on_pushButton_pause_clicked()
{
    timer->stop();
}

void MainWindow::on_pushButton_upload_level_clicked()
{
    activarCarga=true;//para que entre en la funcion actulizar
    if(auxcont!=0 && auxnivel!=0 && auxniveldevida!=0){//para que al dar click en la pantalla no se pongan en ceros los valores de cont y nivel de vida y se pierda inmediatamenete el juego
        ifstream archivo2;
        archivo2.open(user,ios::in);
        getline(archivo2,valores);
        int pos=valores.find(',');//para encontrar la primera como en el archivo de texto
        int pos2=valores.rfind(',');//para encontrar la segunda coma en el archivo de texto
        stringcont=valores.substr(0,pos);// hace los sub-string partiendo desde cierta pocion del string hasta la longitud que se desea
        auxcont=atoi(stringcont.c_str());//y se hace las conc¿versiones a enteros
        stringnvd=valores.substr(pos2+1,valores.size()-(pos2+1));
        auxniveldevida=atoi(stringnvd.c_str());
        stringnivel=valores.substr(pos+1,1);
        auxnivel=atoi(stringnivel.c_str());
    }
}
