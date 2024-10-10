#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
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
    
    void setRandomPosition() override {
        position += getRandomPos();
        rectangle.setPosition(position);
    }

    Shape getShape() const override { return Shape::RectangleFigure;}


    void draw(sf::RenderWindow& window) const {
        if (getIsActive()) window.draw(rectangle);
    }

private:
    sf::RectangleShape rectangle;
    sf::Vector2f position;
    
};

#endif // RECTANGLE_H
