#ifndef RING_H
#define RING_H

#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "FigureShape.h"

class Ring: public Circle {
public:
    Ring(float radius, const sf::Vector2f& localPosition, sf::Color color):Circle(radius, localPosition, color) {
        const float innerRadius = radius * 0.9;
        innerCircle.setRadius(innerRadius);
        innerCircle.setFillColor(sf::Color::Black);
        innerCircle.setPosition(
            point.getPos().x + (radius - innerRadius), 
            point.getPos().y + (radius - innerRadius)
        );
    };

    Shape getShape() const override { return Shape::RingFigure;}

    void draw(sf::RenderWindow& window) const override {
        if (getIsActive()) {
            window.draw(circle);
            window.draw(innerCircle);
        }
    }
private:
    sf::CircleShape innerCircle;
};

#endif