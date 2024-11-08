#ifndef SQUARECIRCLE_H
#define SQUARECIRCLE_H

#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "FigureShape.h"

class SquareCircle: public Rectangle {
public:
    SquareCircle(const sf::Vector2f& size, const sf::Vector2f& localPosition, sf::Color color):Rectangle(size, localPosition, color) {
        const float innerRadius = size.x / 2;
        innerCircle.setRadius(innerRadius);
        innerCircle.setFillColor(sf::Color::Black);
        innerCircle.setPosition(point.getPos());
    };

    Shape getShape() const override { return Shape::SquareCircleFigure;}

    void draw(sf::RenderWindow& window) override {
        rectangle.setPosition(point.getPos());
        innerCircle.setPosition(point.getPos());
        if (getIsActive()) {
            window.draw(rectangle);
            window.draw(innerCircle);
        }
    }
private:
    sf::CircleShape innerCircle;
};

#endif