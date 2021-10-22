#include "login.h"
#include "ui_login.h"

#include "mainwindow.h"//dejar aqui este sarrapastroso

Login::Login(QWidget *parent) :    QDialog(parent),    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("L O G I N");//Titulo a la ventana
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_enter_clicked()
{
    bool aux=false;
    ifstream archivo;
    QString nameq=ui->lineEdit_user->text();//lineEditUsuarioIniciarSesion es el lineEdit donde se ingresa el usuario ya creado
    QString passq=ui->lineEdit_password->text();//lineEditContrasenaIniciarSesion es el lineEdit donde se ingresa la contraseña del usuario ya creado
    string name=nameq.toLocal8Bit().constData();
    string pass=passq.toLocal8Bit().constData();
    string linea=name+","+pass+".txt";//asi se gaurda en el block de notas: nombre , contraseña .
    archivo.open(linea);
    if(archivo.is_open())
    {
        aux=true;
    }
    else{
        aux=false;
    }
    if(aux==true)
    {
        MainWindow * puerta;
        puerta=new MainWindow;
        puerta->name(linea);
        puerta->show();
        close();
    }

    else if(archivo.fail())
    {
        QString texto="Puede ser que:\n";
        texto+="\n";
        texto+="-El usuario no exista\n";
        texto+="-La clave este mal digitada\n";
        texto+="-El usuario este mal digitado\n";
        texto+="-El usuario y la clave esten ambos mal digitados \n";
        texto+="\n";
        texto+="Vuelva a ingresar los datos\n";
        QMessageBox::about(this,"Cuidado!",texto);
    }
    archivo.close();
}

void Login::on_pushButton_enter_2_clicked()
{
    QString nameqs=ui->lineEdit_user_2->text();//lineEditUsuarioRegistro es el lineEdit para colocar en nombre del usuario al momento de registrarse
    QString passqs=ui->lineEdit_password_register->text();// lineEditContrasenaRegistro es el lineEdit que relaciona la contraseña del usuario
    QString valpass=ui->lineEdit_verification_password->text();//lineEditVerificarContrasena es el lineEdit para retificar la contraseña del usuario al momento de registrarse

    string namen=nameqs.toLocal8Bit().constData();
    string passn=passqs.toLocal8Bit().constData();
    string escribir=namen+","+passn+".txt";
    ofstream archivo;//para añadir mas texto al archivo
    if(passqs==valpass)
    {
        archivo.open(escribir,ios::app);//ios::app agrega mas texto al archivo, ios::out es para escribir, ios::in es para leer
        archivo.close();
        MainWindow * puerta;
        puerta=new MainWindow;
        puerta->show();
        puerta->name(escribir);
        close();
    }
    else
    {
        QMessageBox::about(this,"Error!","Retifique su contraseña");
    }
}

void Login::on_pushButton_exit_clicked()
{
    close();
}

