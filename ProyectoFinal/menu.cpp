#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_new_game_clicked()
{
    MainWindow * newGame=new MainWindow();
    newGame->show();
    close();
}

void Menu::on_pushButton_exit_clicked()
{
    close();
}

void Menu::on_pushButton_author_clicked()
{
    QString texto="Autor: Michael Stiven Zapata Giraldo.\n";
    texto+="Curso: Informatica 2.\n";
    texto+="Juego: Wars.\n";
    texto+="Plataforma del desarrollo del juego: Qt Creator Version 5.7.1.\n";
    texto+="Lenguaje de programacion: C++.\n";
    QMessageBox::about(this,"Información autor",texto);
}

void Menu::on_pushButton_information_clicked()
{
    QString texto="-Desplazamiento del jugador:\n";
    texto+="Presione la tecla W para desplazar hacia arriba, S para desplazar hacia abajo,\n";
    texto+="A hacia la izquierda y D hacia la derecha.\n";
    texto+="\n";
    texto+="-Municiones:\n";
    texto+="Tendrá 50 municiones disponibles, si se agotan las 50 municiones perderá inmediatamente \n";
    texto+="el juego. Cuando sale una hoja plateada si el jugador colisiona con ésta aumentará \n";
    texto+="sus municiones en 4 unidades.\n";
    texto+="\n";
    texto+="-Niveles:\n";
    texto+="Son tres niveles para lograr la batalla Wars:\n";
    texto+="Nivel I: consta de 2 naves con movimiento senoidal, tendrá que dispararle 25 veces para seguir al nivel II.\n";
    texto+="Nivel II: tendra que colisionar con estrellas y evitar colisionar con los satelites, pues si colisiona con ellos su nivek de vida ira disminuyendo \n";
    texto+="el nivel de vida disminuirá de a 2 unidades.\n";
    texto+="Nivel III: saldrán 50 platilloa con movimiento parabolico, para destruirlo deberá dispararle exitosamente cos 20 disparos. En caso de que esto \n";
    texto+="se presente, ha ganado los tres niveles y por lo tanto la Batalla Universal.\n";
    texto+="Pero si el platillo volador sobrepasa el nivel de visualización entonces el nivel de vida\n";
    texto+="-Nivel de vida:\n";
    texto+="Contará inicialmente con un nivel de vida igual a 50 (100 en porcentaje), cada vez que un enemigo colisione con el jugador \n";
    texto+="o sobrepasa el nivel de visulizacion del juego, este nivel de vida irá disminuyendo de a 2.\n";
    texto+="Saldrán cinco estrellas  al colisionar con alguna de éstas \n";
    texto+="aumentará su nivel de vida en cinco unidades. Todo esto se registra en el progressbar de la parte inferior  de la pantalla.\n";
    QMessageBox::about(this,"Wars",texto);
}
