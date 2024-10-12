#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "../WindowConsts.h"
#include "Figure.h"
#include "FigureShape.h"

class Circle : public Figure {
public:
    Circle(float radius, const sf::Vector2f& localPosition)
        : position(localPosition) {
        circle.setRadius(radius);
        // setOrigin(radius, radius); // Центрируем круг
        circle.setFillColor(sf::Color::Cyan);
        circle.setPosition(position);
    }

    bool posCheck(sf::Vector2f newPos) {
        if (newPos.x <= 0) return false;
        if (newPos.x + 2 * circle.getRadius() >= windowX) return false;
        if (newPos.y <= 0) return false;
        if (newPos.y + 2 * circle.getRadius() >= windowY) return false;
        return true;
    }

    void move(const sf::Vector2f& offset) override {
        const sf::Vector2f newPos = position + offset;
        if (!posCheck(newPos)) return;
        position += offset;
        circle.setPosition(position);
    }
    
    void setSize(float offset) override {
        const sf::Vector2f newPos = sf::Vector2f(position.x + offset, position.y + offset);
        const float newRadius = circle.getRadius() + offset;
        if (newRadius <= 0) return;
        if (!posCheck(newPos)) return;

        // if (newRadius <= 0) return;
        // if (position.x - (newRadius - circle.getRadius()) >= 0 && 
        //     position.x + 2 * newRadius <= windowX && 
        //     position.y - (newRadius - circle.getRadius()) >= 0 && 
        //     position.y + 2 * newRadius <= windowY){

        //     circle.setRadius(circle.getRadius() + offset);
        // }
        circle.setRadius(circle.getRadius() + offset);
    }
    
    void setPos(const sf::Vector2f& pos) override {
        position = pos;
        circle.setPosition(position);
    }

    Shape getShape() const override { return Shape::CircleFigure;}

    void draw(sf::RenderWindow& window) const override {
        if (getIsActive()) window.draw(circle);
    }


private:
    sf::CircleShape circle;
    sf::Vector2f position;
    
};

#endif // CIRCLE_H
