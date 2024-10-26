#ifndef RHOMBUS_H
#define RHOMBUS_H 

#include <SFML/Graphics.hpp>
#include "Quadrilateral.h"

class Rhombus : public Quadrilateral {
public:
    // Конструктор для ромба с длиной диагоналей
    Rhombus(float d1, float d2, const sf::Vector2f& center, const sf::Color& color = sf::Color::Green) 
    : Quadrilateral(center, color) {
        sf::Vector2f point1(center.x, center.y - d1 / 2);
        sf::Vector2f point2(center.x + d2 / 2, center.y);
        sf::Vector2f point3(center.x, center.y + d1 / 2);
        sf::Vector2f point4(center.x - d2 / 2, center.y);
        
        setPoints({point1, point2, point3, point4});
    }
};

#endif