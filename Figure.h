#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics.hpp>
#include <random>

class Figure {
public:

    virtual void move(const sf::Vector2f& offset) = 0;
    virtual void setRandomPosition() = 0;

private:
    virtual void updatePosition() = 0;
       
};

#endif // FIGURE_H
