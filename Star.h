#ifndef SFML_TEMPLATE_STAR_H
#define SFML_TEMPLATE_STAR_H

#include <SFML/Graphics.hpp>

class Star
{
private:
    float x;
    float y;
    float brightness;
public:
    Star();

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getBrightness() const;

    void setBrightness(float brightness);

    float getTransformedX(int WIDTH) const;

    float getTransformedY(int HEIGHT) const;

    sf::Color getGrayscaleColor(float BRIGHTEST_STAR);

    Star(float x, float y, float brightness);
};


#endif