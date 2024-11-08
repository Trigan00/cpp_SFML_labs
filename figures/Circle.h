#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "../WindowConsts.h"
#include "Figure.h"
#include "Point.h"
#include "FigureShape.h"

class Circle : public Figure {
public:
    Circle(float radius, float ellipseR, const sf::Vector2f& localPosition, sf::Color color)
        : Figure(localPosition, radius * 2, ellipseR * 2) {
        while(!localPosCheck(localPosition, radius)){
            radius -= 1;
        }
        circle.setRadius(radius);
        circle.setFillColor(color);
        circle.setPosition(point.getPos());
    }

    bool localPosCheck(sf::Vector2f newPos, float r) {
        if (newPos.x <= 0) return false;
        if (newPos.x + 2 * r >= windowX) return false;
        if (newPos.y <= 0) return false;
        if (newPos.y + 2 * r >= windowY) return false;
        return true;
    }

    void setSize(float offset) override {
        // const sf::Vector2f newPos = sf::Vector2f(point.getPos().x + offset, point.getPos().y + offset);
        // const float newRadius = circle.getRadius() + offset;
        // if (newRadius <= 0) return;
        // if (!posCheck(newPos, circle.getRadius())) return;
        // circle.setRadius(circle.getRadius() + offset);
        width += offset;
        height += offset;
        if(posCheck(point.getPos())){
            circle.setRadius(circle.getRadius() + offset);
        }else{
            width -= offset;
            height -= offset;
        }
    }
    
    void setPos(const sf::Vector2f& pos) override {
        point.setPos(pos);
        circle.setPosition(point.getPos());
    }

    Shape getShape() const override { return Shape::CircleFigure;}

    void action() override {};

    void draw(sf::RenderWindow& window) override {
        circle.setPosition(point.getPos());
        if (getIsActive()) window.draw(circle);
    }


protected:
    sf::CircleShape circle;
};

#endif // CIRCLE_H
