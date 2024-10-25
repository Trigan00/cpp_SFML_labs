#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "../WindowConsts.h"
#include "Figure.h"
#include "Point.h"
#include "FigureShape.h"

class Circle : public Figure {
public:
    Circle(float radius, const sf::Vector2f& localPosition, sf::Color color)
        : point(localPosition) {
        circle.setRadius(radius);
        // setOrigin(radius, radius); // Центрируем круг
        circle.setFillColor(color);
        circle.setPosition(point.getPos());
    }

    bool posCheck(sf::Vector2f newPos) {
        if (newPos.x <= 0) return false;
        if (newPos.x + 2 * circle.getRadius() >= windowX) return false;
        if (newPos.y <= 0) return false;
        if (newPos.y + 2 * circle.getRadius() >= windowY) return false;
        return true;
    }

    void move(const sf::Vector2f& offset) override {
        const sf::Vector2f newPos = point.getPos() + offset;
        if (!posCheck(newPos)) return;
        point.setPos(newPos);
        circle.setPosition(point.getPos());
    }
    
    void setSize(float offset) override {
        const sf::Vector2f newPos = sf::Vector2f(point.getPos().x + offset, point.getPos().y + offset);
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
        point.setPos(pos);
        circle.setPosition(point.getPos());
    }

    Shape getShape() const override { return Shape::CircleFigure;}

    void action() override {};

    void draw(sf::RenderWindow& window) const override {
        if (getIsActive()) window.draw(circle);
    }


private:
    sf::CircleShape circle;
    Point point;
    
};

#endif // CIRCLE_H
