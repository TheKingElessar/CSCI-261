#include "Bubble.h"

void Bubble::updatePosition()
{
    this->getCircleShape();
    this->circleShape.setPosition(
            Vector2f(this->circleShape.getPosition().x + this->xDir, this->circleShape.getPosition().y + this->yDir));
}

const CircleShape &Bubble::getCircleShape() const
{
    return circleShape;
}

void Bubble::setCircleShape(const CircleShape &circleShape)
{
    Bubble::circleShape = circleShape;
}

double Bubble::getXDir() const
{
    return xDir;
}

void Bubble::setXDir(double xDir)
{
    Bubble::xDir = xDir;
}

double Bubble::getYDir() const
{
    return yDir;
}

void Bubble::setYDir(double yDir)
{
    Bubble::yDir = yDir;
}

Bubble::Bubble()
{
    this->setXDir(0);
    this->setYDir(0);
    this->circleShape = CircleShape();
    this->circleShape.setFillColor(Color::White);
    this->circleShape.setRadius(20);
}

Bubble::Bubble(float xDir, float yDir)
{
    this->setXDir(xDir);
    this->setYDir(yDir);
    this->circleShape = CircleShape();
    this->circleShape.setFillColor(Color::White);
    this->circleShape.setRadius(20);
}

void Bubble::checkBounds(const int WIDTH, const int HEIGHT)
{
    if (this->getXPos() + this->circleShape.getRadius() * 2 >= WIDTH || this->getXPos() <= 0.f)
    {
        this->setXDir(this->getXDir() * -1);
    }
    if (this->getYPos() + this->circleShape.getRadius() * 2 >= HEIGHT || this->getYPos() <= 0.f)
    {
        this->setYDir(this->getYDir() * -1);
    }
}

float Bubble::getRadius()
{
    return this->radius;
}

void Bubble::setRadius(float radius)
{
    this->radius = radius;
}

float Bubble::getXPos()
{
    return this->circleShape.getPosition().x;
}

float Bubble::getYPos()
{
    return this->circleShape.getPosition().y;
}
