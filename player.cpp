#include "player.h"

Player::Player(float r, float x, float y)//:posx(x),posy(y),radio(r)
{
//   srand((unsigned)time(nullptr));
//   double ro = 0.01;                     //maximo coeficientede friccion  desde 0 hasta 0.01
//   double Cf = (sin(rand())+1)*0.005;
//   vx =(sin((rand())+1)*150.0);
//   vy =(sin(rand())+1)*150.0;
//   masa = 50+(rand()%601-50);
//   E = ((sin(rand())-1)*0.2)-0.5;
//   K = ro*Cf*PI/2.0;
    radio=r;
    posx=x;
    posy=y;
}

Player::~Player()
{
    //delete this;
}

QRectF Player::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagenes/spaceship.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Player::SetVel(float x, float y)
{
//    vx=x;
//    vy=y;
}

void Player::setPoint(double x, double y)
{
//    posx=x;
//    posy=y;
}

void Player::actualizar(double dt_)
{
//    double v = sqrt(pow((vx),2)+pow((vy),2));
//    double theta = atan2(vy,vx);
//    ax = -1*(K*(v*v)*(radio*radio)*cos(theta))/masa;
//    ay = (-1*(K*(v*v)*(radio*radio)*sin(theta))/masa) - G;
//    posx += vx*dt_ + (ax/2)*pow(dt_,2);
//    posy += vy*dt_ + (ay/2)*pow(dt_,2);
//    vx += ax*dt_;
//    vy += ay*dt_;
}

void Player::move_yNegativo()
{
    posy=posy-5;
    //    posy=posy-(vy*dt)-(0.5*ay*dt*dt);
    if(posy<0){
        posy=0;
    }
    setPos(posx,posy);
    qDebug()<<posx<<'\t'<<posy<<endl;
}

void Player::move_yPositivo()
{
    posy+=5;

    //    posy=posy+(vy*dt)+(0.5*ay*dt*dt);
    if(posy>235){
        posy=235;
    }
    //    setPos(posx,posy);
    //    setPos(x(),posy);
    setPos(posx,posy);
    qDebug()<<posx<<'\t'<<posy<<endl;
}

void Player::move_xNegativo()
{
    posx=posx-5;
    //    setPos(posx,posy);
    //    posx=posx+(vx*dt)+(0.5*ax*dt*dt);
    if(posx<0.5){
        posx=0.5;
    }
    setPos(posx,posy);
    qDebug()<<posx<<'\t'<<posy<<endl;
}


void Player::move_xPositivo()
{
    posx+=5;

    //    posx=posx-(vx*dt)-(0.5*ax*dt*dt);
    if(posx>458){
        posx=458;
    }
    setPos(posx,posy);
    qDebug()<<"x="<<posx<<'\t'<<posy<<"posy"<<endl;
}

float Player::getPosx() const
{
    return posx;
}

void Player::setPosx(float value)
{
    posx = value;
}

float Player::getPosy() const
{
    return posy;
}

void Player::setPosy(float value)
{
    posy = value;
}


