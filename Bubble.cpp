#include <iostream>
#include "Bubble.h"

using namespace std;

void Bubble::updatePosition()
{
    /*
     * Setting pos to explicit numbers works
     * Setting pos to variables + explicit doesn't work
     */
    cout << "Old: " << this->getXPos() << endl;
    cout << "New: " << this->getXPos() + this->getXDir() << endl;
    this->setXPos(this->getXPos() + this->getXDir());
    this->setYPos(this->getYPos() + this->getYDir());
    float radius = rand() % (50 - 40) + 10;
    this->circleShape.setRadius(radius);
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
    this->circleShape.setRadius(this->radius);
}

float Bubble::getXPos()
{
    return this->circleShape.getPosition().x;
}

float Bubble::getYPos()
{
    return this->circleShape.getPosition().y;
}

void Bubble::setXPos(float x)
{
    this->circleShape.setPosition(x, this->circleShape.getPosition().y);
}

void Bubble::setYPos(float y)
{
    this->circleShape.setPosition(this->circleShape.getPosition().x, y);
}

void Bubble::setColor(Color &color)
{
    this->circleShape.setFillColor(color);
}