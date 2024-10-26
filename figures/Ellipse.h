#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "FigureShape.h"

class Ellipse: public Circle {
public:
    Ellipse(float radius, const sf::Vector2f& localPosition, sf::Color color):Circle(radius, localPosition, color) {
        circle.setRadius(1.0f);
        circle.setPointCount(100);
        circle.setScale(sf::Vector2f(radius * 2, radius));
    };

    Shape getShape() const override { return Shape::EllipseFigure;}

    void action() override {
        circle.rotate(90.0f);
    }

};

#endif