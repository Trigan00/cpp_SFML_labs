#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "FigureShape.h"


class Line: public Rectangle {
public:
    Line(float width, float height, const sf::Vector2f& localPosition, sf::Color color):Rectangle(width, height, localPosition, color){};

    Shape getShape() const override { return Shape::LineFigure;}

    void action() override {
        if (rectangle.getFillColor() != sf::Color::Yellow) rectangle.setFillColor(sf::Color::Yellow);
        else rectangle.setFillColor(sf::Color::Green);
    }
};

#endif