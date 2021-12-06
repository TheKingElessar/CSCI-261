#include <iostream>
#include "Bubble.h"

using namespace std;

/*********************************
 *          CONSTRUCTORS         *
 *********************************/

/*
 * Default constructor used in Lab 8-A
 */
Bubble::Bubble()
{
    this->setXDir(0);
    this->setYDir(0);
    this->_circleShape = CircleShape();
    this->_circleShape.setFillColor(Color::White);
    this->_circleShape.setRadius(20);
}

/*
 * Constructor used in Lab 8-A
 */
Bubble::Bubble(float xDir, float yDir)
{
    this->setXDir(xDir);
    this->setYDir(yDir);
    this->_circleShape = CircleShape();
    this->_circleShape.setFillColor(Color::White);
    this->_circleShape.setRadius(20);
}

/*
 * This constructor just randomizes everything. I didn't want to mess with the
 * constructors from the lab where we originally made the Bubble class, so I'm
 * just using this.
 */
Bubble::Bubble(bool)
{
    float xDir = (static_cast<float>(rand()) / RAND_MAX) * 2.5;
    float yDir = (static_cast<float>(rand()) / RAND_MAX) * 2.5;
    float radius = rand() % (50 - 40) + 10;
    float startX = rand() % (400 - 100) + 100;
    float startY = rand() % (400 - 100) + 100;

    this->setXDir(xDir);
    this->setYDir(yDir);
    this->_circleShape = CircleShape();
    this->_circleShape.setFillColor(Color::White);
    this->_circleShape.setRadius(radius);
    this->setXPos(startX);
    this->setYPos(startY);

    Color color(rand() % 255, rand() % 255, rand() % 255);
    this->setColor(color);
}

/*********************************
 *            MOVEMENT           *
 *********************************/

/*
 * Check if shape is on the window border, reverse its direction
 * in the relevant direction.
 */
void Bubble::checkBounds(const int WIDTH, const int HEIGHT)
{
    if (this->getXPos() + this->_circleShape.getRadius() * 2 >= WIDTH || this->getXPos() <= 0.f)
    {
        this->setXDir(this->getXDir() * -1);
    }
    if (this->getYPos() + this->_circleShape.getRadius() * 2 >= HEIGHT || this->getYPos() <= 0.f)
    {
        this->setYDir(this->getYDir() * -1);
    }
}

/*
 * Move shape by the set amount
 */
void Bubble::updatePosition()
{
    this->setXPos(this->getXPos() + this->getXDir());
    this->setYPos(this->getYPos() + this->getYDir());
}

/*********************************
 *            SETTERS            *
 *********************************/

void Bubble::setCircleShape(const CircleShape &circleShape)
{
    Bubble::_circleShape = circleShape;
}

void Bubble::setXDir(double xDir)
{
    Bubble::_xDir = xDir;
}

void Bubble::setYDir(double yDir)
{
    Bubble::_yDir = yDir;
}

void Bubble::setRadius(float radius)
{
    this->_radius = radius;
    this->_circleShape.setRadius(this->_radius);
}

void Bubble::setXPos(float x)
{
    this->_circleShape.setPosition(x, this->_circleShape.getPosition().y);
}

void Bubble::setYPos(float y)
{
    this->_circleShape.setPosition(this->_circleShape.getPosition().x, y);
}

void Bubble::setColor(Color &color)
{
    this->_circleShape.setFillColor(color);
}

/*********************************
 *            GETTERS            *
 *********************************/

const CircleShape &Bubble::getCircleShape() const
{
    return _circleShape;
}

double Bubble::getXDir() const
{
    return _xDir;
}

double Bubble::getYDir() const
{
    return _yDir;
}

float Bubble::getRadius()
{
    return this->_radius;
}

float Bubble::getXPos()
{
    return this->_circleShape.getPosition().x;
}

float Bubble::getYPos()
{
    return this->_circleShape.getPosition().y;
}
