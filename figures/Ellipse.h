#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "FigureShape.h"

class Ellipse: public Circle {
public:
    Ellipse(float width, float height, const sf::Vector2f& localPosition, sf::Color color):Circle(width, height, localPosition) {
        circle.setRadius(1.0f);
        circle.setPointCount(100);
        circle.setScale(sf::Vector2f(width / 2, height / 2));
        circle.setFillColor(color);
    };

    Shape getShape() const override { return Shape::EllipseFigure;}

    void action() override {
        circle.rotate(90.0f);
    }

};

#endif