#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include "../WindowConsts.h"
#include "Point.h"
#include "Figure.h"
#include "FigureShape.h"

class Rectangle : public Figure {
public:
    Rectangle(const sf::Vector2f& size, const sf::Vector2f& localPosition, sf::Color color)
        : point(localPosition) {
        rectangle.setSize(size);
        rectangle.setFillColor(color);
        rectangle.setPosition(point.getPos());
    }

    void move(const sf::Vector2f& offset) override {
        point.setPos(point.getPos() + offset);
        rectangle.setPosition(point.getPos());
    }
    
    void setSize(float offset) override {
        sf::Vector2f s = rectangle.getSize();
        const sf::Vector2f newSize(point.getPos().x + s.x + offset, point.getPos().y + s.y + offset);
        if (s.x + offset < 0 || s.y + offset < 0) return;
        if (newSize.x >= windowX) return;
        if (newSize.y >= windowY) return;
        rectangle.setSize(sf::Vector2f(s.x + offset, s.y + offset));
    }
    
    void setPos(const sf::Vector2f& pos) override {
        point.setPos(pos);
        rectangle.setPosition(point.getPos());
    }

    Shape getShape() const override { return Shape::RectangleFigure;}

    void action() override {};


    void draw(sf::RenderWindow& window) const override {
        if (getIsActive()) window.draw(rectangle);
    }

protected:
    sf::RectangleShape rectangle;
    Point point;
    
};

#endif // RECTANGLE_H
