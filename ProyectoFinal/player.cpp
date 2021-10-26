#include "player.h"

Player::Player(float r, float x, float y)
{
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

void Player::move_yNegativo()
{
    posy=posy-5;    
    if(posy<0){
        posy=0;
    }
    setPos(posx,posy);    
}

void Player::move_yPositivo()
{
    posy+=5;
    if(posy>235){
        posy=235;
    }
    setPos(posx,posy);    
}

void Player::move_xNegativo()
{
    posx=posx-5;   
    if(posx<0.5){
        posx=0.5;
    }
    setPos(posx,posy);    
}


void Player::move_xPositivo()
{
    posx+=5;    
    if(posx>458){
        posx=458;
    }
    setPos(posx,posy);    
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
