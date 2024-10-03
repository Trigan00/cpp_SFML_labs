#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <random>
#include "Figure.h"

class Rectangle : public Figure, public sf::RectangleShape {
public:
    Rectangle(const sf::Vector2f& size, const sf::Vector2f& localPosition)
        : sf::RectangleShape(size), m_localPosition(localPosition) {
        setFillColor(sf::Color::Red);
        updatePosition();
    }

    void move(const sf::Vector2f& offset) override {
        m_localPosition += offset / 10.f;
        updatePosition();
    }

    sf::Vector2f getLocalPosition() const {
        return m_localPosition;
    }

    void setRandomPosition() override {
        const float offsetX = -50 + ( std::rand() % ( 50 - -50 + 1 ) ); 
        const float offsetY = -50 + ( std::rand() % ( 50 - -50 + 1 ) ); 
        m_localPosition += sf::Vector2f(offsetX, offsetY);
        updatePosition();
    }

private:
    void updatePosition() override {
        setPosition(m_localPosition);
    }

    sf::Vector2f m_localPosition;
};

#endif // RECTANGLE_H
