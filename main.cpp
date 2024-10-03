#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
#include "Circle.h"
#include "Rectangle.h"

sf::Vector2f getRandomPos(){
    const float x = 10 + ( std::rand() % ( 700 - 10 + 1 ) ); 
    const float y = 10 + ( std::rand() % ( 500 - 10 + 1 ) ); 
    return sf::Vector2f(x, y);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Project");
    window.setFramerateLimit(60);
    Menu menu;

    Circle* circle = new Circle(50.0f, sf::Vector2f(300.0f, 300.0f));
    Rectangle* rectangle = new Rectangle(sf::Vector2f(120.0f, 50.0f), sf::Vector2f(500.0f, 300.0f));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (circle == nullptr) circle = new Circle(50.0f, getRandomPos());
                    else {
                        delete circle;
                        circle = nullptr;
                    }
                    
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (rectangle == nullptr) rectangle = new Rectangle(sf::Vector2f(120.0f, 50.0f), getRandomPos());
                    else {
                        delete rectangle;
                        rectangle = nullptr;
                    }
                    
                }
            }
            if(event.type == sf::Event::KeyPressed){
                if (circle != nullptr) if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) circle->setRandomPosition();
                if (rectangle != nullptr) if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) rectangle->setRandomPosition();
            }
            menu.handleEvent(window, event);
        }

        if (circle != nullptr){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) circle->move(sf::Vector2f(-1.0f, 0.0f));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) circle->move(sf::Vector2f(1.0f, 0.0f));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) circle->move(sf::Vector2f(0.0f, -1.0f));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) circle->move(sf::Vector2f(0.0f, 1.0f));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) circle->changeRadius(circle->getRadius() + 1.0f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) circle->changeRadius(circle->getRadius() - 1.0f);

        }

        window.clear(sf::Color::Black);
        if (circle != nullptr) window.draw(*circle);
        if (rectangle != nullptr) window.draw(*rectangle);
        menu.draw(window);
        window.display();
    }

    if (circle != nullptr) {
        delete circle;
        circle = nullptr;
    }
    if (rectangle != nullptr) {
        delete rectangle;
        rectangle = nullptr;
    }

    return 0;
}
