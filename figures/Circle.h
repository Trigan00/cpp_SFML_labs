#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
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

    void move(const sf::Vector2f& offset) override {
        position += offset;
        circle.setPosition(position);
    }
    
    void setRandomPosition() override {
        position += getRandomPos();
        circle.setPosition(position);
    }

    Shape getShape() const override { return Shape::CircleFigure;}

    void changeRadius(float radius) {
        circle.setRadius(radius);
    }

    float getRadius() const {
        return circle.getRadius();
    }

    void draw(sf::RenderWindow& window) {
        if (getIsActive()) window.draw(circle);
    }


private:
    sf::CircleShape circle;
    sf::Vector2f position;
    
};

#endif // CIRCLE_H
