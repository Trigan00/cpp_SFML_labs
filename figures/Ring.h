#ifndef RING_H
#define RING_H

#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "FigureShape.h"

class Ring: public Circle {
public:
    Ring(float radius, const sf::Vector2f& localPosition, sf::Color color):Circle(radius, localPosition, color), r(radius), Ir(radius * 0.9) {
        innerCircle.setRadius(Ir);
        innerCircle.setFillColor(sf::Color::Black);
        innerCircle.setPosition(
            point.getPos().x + (radius - Ir), 
            point.getPos().y + (radius - Ir)
        );
    };

    Shape getShape() const override { return Shape::RingFigure;}

    void draw(sf::RenderWindow& window) override {
        circle.setPosition(point.getPos());
        innerCircle.setPosition(
            point.getPos().x + (r - Ir), 
            point.getPos().y + (r - Ir)
        );
        if (getIsActive()) {
            window.draw(circle);
            window.draw(innerCircle);
        }
    }
private:
    sf::CircleShape innerCircle;
    float r;
    float Ir;
};

#endif