#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include "../WindowConsts.h"
#include "Figure.h"
#include "FigureShape.h"

class Rectangle : public Figure {
public:
    Rectangle(const sf::Vector2f& size, const sf::Vector2f& localPosition)
        : position(localPosition) {
        rectangle.setSize(size);
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(position);
    }

    void move(const sf::Vector2f& offset) override {
        position += offset;
        rectangle.setPosition(position);
    }
    
    void setSize(float offset) override {
        sf::Vector2f s = rectangle.getSize();
        const sf::Vector2f newSize(position.x + s.x + offset, position.y + s.y + offset);
        if (s.x + offset < 0 || s.y + offset < 0) return;
        if (newSize.x >= windowX) return;
        if (newSize.y >= windowY) return;
        rectangle.setSize(sf::Vector2f(s.x + offset, s.y + offset));
    }
    
    void setPos(const sf::Vector2f& pos) override {
        position = pos;
        rectangle.setPosition(position);
    }

    Shape getShape() const override { return Shape::RectangleFigure;}


    void draw(sf::RenderWindow& window) const override {
        if (getIsActive()) window.draw(rectangle);
    }

private:
    sf::RectangleShape rectangle;
    sf::Vector2f position;
    
};

#endif // RECTANGLE_H
