#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include <random>
#include "Figure.h"

class Circle : public Figure, public sf::CircleShape {
public:
    Circle(float radius, const sf::Vector2f& localPosition)
        : sf::CircleShape(radius), m_localPosition(localPosition) {
        setRadius(radius);
        // setOrigin(radius, radius); // Центрируем круг
        setFillColor(sf::Color::Cyan);
        updatePosition();
    }

    void move(const sf::Vector2f& offset) override {
        m_localPosition += offset;
        updatePosition();
    }

    sf::Vector2f getLocalPosition() const {
        return m_localPosition;
    }

    void changeRadius(float radius) {
        setRadius(radius);
        // setOrigin(radius, radius); // Центрируем круг при изменении радиуса
        updatePosition();
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

#endif // CIRCLE_H
