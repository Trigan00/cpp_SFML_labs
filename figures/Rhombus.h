#ifndef RHOMBUS_H
#define RHOMBUS_H 

#include <SFML/Graphics.hpp>
#include "Quadrilateral.h"

class Rhombus : public Quadrilateral {
public:
    Rhombus(const sf::Vector2f& pos, float width, float height, const sf::Color& color = sf::Color::Green) 
    : Quadrilateral(pos, width, height, color) {}

    void draw(sf::RenderWindow& window) override {
        sf::Vector2f point1(point.getPos().x + width * 0.5, point.getPos().y);
        sf::Vector2f point2(point.getPos().x + width, point.getPos().y + height * 0.5);
        sf::Vector2f point3(point.getPos().x + width * 0.5, point.getPos().y + height);
        sf::Vector2f point4(point.getPos().x, point.getPos().y + height * 0.5);
        
        setPoints({point1, point2, point3, point4});
        window.draw(shape);
    }
};

#endif