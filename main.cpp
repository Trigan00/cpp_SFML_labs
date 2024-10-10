#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Menu.h"
#include "figures/Circle.h"
#include "figures/Rectangle.h"
#include "figures/FigureShape.h"
#include "MenuButton.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Project");
    window.setFramerateLimit(60);

    Circle* circle = new Circle(50.0f, sf::Vector2f(300.0f, 300.0f));
    Rectangle* rectangle = new Rectangle(sf::Vector2f(120.0f, 50.0f), sf::Vector2f(500.0f, 300.0f));

    MenuButton circleBut1("Show/Hide", circle, ActionType::CHANGE_VISIBILITY);
    MenuButton rectangleBut1("Show/Hide", rectangle, ActionType::CHANGE_VISIBILITY);
    MenuButton circleBut2("Increase size", circle, ActionType::INCREASE_SIZE);
    MenuButton rectangleBut2("Increase size", rectangle, ActionType::INCREASE_SIZE);
    MenuButton circleBut3("Decrease size", circle, ActionType::DECREASE_SIZE);
    MenuButton rectangleBut3("Decrease size", rectangle, ActionType::DECREASE_SIZE);
    MenuButton circleBut4("Set random position", circle, ActionType::RANDOM_POS);
    MenuButton rectangleBut4("Set random position", rectangle, ActionType::RANDOM_POS);
    MenuButton* butArr[8] {&circleBut1, &rectangleBut1, &circleBut2, &rectangleBut2, &circleBut3, &rectangleBut3, &circleBut4, &rectangleBut4};

    Menu menu(butArr, 8);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            menu.handleEvent(window, event);
        }

        if (circle != nullptr){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) circle->move(sf::Vector2f(-1.0f, 0.0f));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) circle->move(sf::Vector2f(1.0f, 0.0f));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) circle->move(sf::Vector2f(0.0f, -1.0f));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) circle->move(sf::Vector2f(0.0f, 1.0f));
        }

        window.clear(sf::Color::Black);
        if (circle != nullptr) circle->draw(window);
        if (rectangle != nullptr) rectangle->draw(window);
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
