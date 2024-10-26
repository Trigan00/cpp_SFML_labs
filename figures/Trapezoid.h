#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <SFML/Graphics.hpp>
#include "Quadrilateral.h"

class Trapezoid : public Quadrilateral {
public:
    Trapezoid(const sf::Vector2f& topLeft, const sf::Vector2f& topRight, 
              const sf::Vector2f& bottomRight, const sf::Vector2f& bottomLeft,
              const sf::Color& color = sf::Color::Yellow)
    : Quadrilateral(sf::Vector2f(0, 0), color) {
        setPoints({topLeft, topRight, bottomRight, bottomLeft});
    }
};

#endif