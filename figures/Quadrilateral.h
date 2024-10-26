#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H 

#include <SFML/Graphics.hpp>
#include <cmath>
#include <array>
#include "Figure.h"
#include "FigureShape.h"

class Quadrilateral: public Figure {
public:

    Quadrilateral(const sf::Vector2f& localPosition, const sf::Color& color = sf::Color::White): Figure(localPosition) {
        shape.setFillColor(color);
    }

    void setColor(const sf::Color& color) {
        shape.setFillColor(color);
    }

    void setSize(float offset) {}
    void setPos(const sf::Vector2f& pos) {}
    Shape getShape() const {return Shape::QuadrilateralFigure;}
    void action() {}

    void move(const sf::Vector2f& offset) {
        point.setPos(point.getPos() + offset);
        shape.setPosition(point.getPos());
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

protected:
    sf::ConvexShape shape;

    void setPoints(const std::array<sf::Vector2f, 4>& points) {
        shape.setPointCount(4);
        for (size_t i = 0; i < 4; ++i) {
            shape.setPoint(i, points[i]);
        }
    }
};

#endif
