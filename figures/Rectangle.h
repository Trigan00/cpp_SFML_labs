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
        : Figure(localPosition, size.x, size.y) {
        rectangle.setSize(size);
        rectangle.setFillColor(color);
        rectangle.setPosition(point.getPos());
    }

    
    void setSize(float offset) override {
        sf::Vector2f s = rectangle.getSize();
        width += offset;
        height += offset;
        if(posCheck(point.getPos()) && width > 0 && height > 0){
            rectangle.setSize(sf::Vector2f(s.x + offset, s.y + offset));
        }else{
            width -= offset;
            height -= offset;
        }
    }
    
    void setPos(const sf::Vector2f& pos) override {
        point.setPos(pos);
        rectangle.setPosition(point.getPos());
    }

    Shape getShape() const override { return Shape::RectangleFigure;}

    void action() override {};


    void draw(sf::RenderWindow& window) override {
        rectangle.setPosition(point.getPos());
        if (getIsActive()) window.draw(rectangle);
    }

protected:
    sf::RectangleShape rectangle;
};

#endif // RECTANGLE_H
