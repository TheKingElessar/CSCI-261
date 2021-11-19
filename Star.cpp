#include "Star.h"

Star::Star(float x, float y, float brightness)
{
    this->x = x;
    this->y = y;
    this->brightness = brightness;
}

Star::Star()
{
    this->x = 0;
    this->y = 0;
    this->brightness = 0;
}

float Star::getX() const
{
    return x;
}

void Star::setX(float x)
{
    Star::x = x;
}

float Star::getY() const
{
    return y;
}

void Star::setY(float y)
{
    Star::y = y;
}

float Star::getBrightness() const
{
    return brightness;
}

void Star::setBrightness(float brightness)
{
    Star::brightness = brightness;
}

float Star::getTransformedX(int WIDTH) const
{
    return (this->x + 1) * WIDTH / 2;
}

float Star::getTransformedY(int HEIGHT) const
{
    return (-this->y + 1) * HEIGHT / 2;
}

sf::Color Star::getGrayscaleColor(const float BRIGHTEST_STAR)
{
    int shadeOfGray = (int) ((255.0 * (BRIGHTEST_STAR - brightness)) / BRIGHTEST_STAR);
    return sf::Color(shadeOfGray, shadeOfGray, shadeOfGray);
}
