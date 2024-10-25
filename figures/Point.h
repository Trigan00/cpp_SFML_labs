#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>

class Point
{
public:
    Point(const sf::Vector2f& localPosition): position(localPosition) {};

    sf::Vector2f getPos() const {return position;}
    void setPos(const sf::Vector2f& newPos) {position = newPos;}
private:
    sf::Vector2f position;

};

#endif