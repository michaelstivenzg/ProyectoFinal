#include "player.h"

Player::Player(float r, float x, float y)
{
    radio=r;
    posx=x;
    posy=y;
}

Player::~Player()
{
    delete this;
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
