#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H 

#include <SFML/Graphics.hpp>
#include <cmath>
#include <array>
#include "Figure.h"
#include "FigureShape.h"

class Quadrilateral: public Figure {
public:

    Quadrilateral(const sf::Vector2f& localPosition, float w, float h, const sf::Color& color = sf::Color::White): Figure(localPosition, w, h) {
        shape.setFillColor(color);
    }

    void setColor(const sf::Color& color) {
        shape.setFillColor(color);
    }

    void setSize(float offset) override {}
    void setPos(const sf::Vector2f& pos) override {}
    Shape getShape() const override {return Shape::QuadrilateralFigure;}
    void action() {}


    virtual void draw(sf::RenderWindow& window) = 0;

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
