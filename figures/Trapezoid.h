#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <SFML/Graphics.hpp>
#include "Quadrilateral.h"

class Trapezoid : public Quadrilateral {
public:
    Trapezoid(const sf::Vector2f& pos, float width, float height, const sf::Color& color = sf::Color::Yellow)
    : Quadrilateral(pos, width, height, color) {}

    void draw(sf::RenderWindow& window) override {
        setPoints({sf::Vector2f(point.getPos().x + width * 0.2, point.getPos().y), sf::Vector2f(point.getPos().x + width * 0.8, point.getPos().y), sf::Vector2f(point.getPos().x + width, point.getPos().y + height), sf::Vector2f(point.getPos().x, point.getPos().y + height)});
        window.draw(shape);
    }
};

#endif