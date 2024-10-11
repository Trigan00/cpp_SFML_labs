#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "Menu.h"
#include "figures/Figure.h"
#include "figures/Circle.h"
#include "figures/Rectangle.h"
#include "figures/FigureShape.h"
#include "MenuButton.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Project");
    window.setFramerateLimit(60);

    Circle* circle = new Circle(50.0f, sf::Vector2f(300.0f, 300.0f));
    Rectangle* rectangle = new Rectangle(sf::Vector2f(120.0f, 50.0f), sf::Vector2f(500.0f, 300.0f));

    std::vector<Figure*> figuresVector {circle, rectangle};

    MenuButton circleBut1("Show/Hide", figuresVector, ActionType::CHANGE_VISIBILITY, Shape::CircleFigure);
    MenuButton rectangleBut1("Show/Hide", figuresVector, ActionType::CHANGE_VISIBILITY, Shape::RectangleFigure);
    MenuButton circleBut2("Increase size", figuresVector, ActionType::INCREASE_SIZE, Shape::CircleFigure);
    MenuButton rectangleBut2("Increase size", figuresVector, ActionType::INCREASE_SIZE, Shape::RectangleFigure);
    MenuButton circleBut3("Decrease size", figuresVector, ActionType::DECREASE_SIZE, Shape::CircleFigure);
    MenuButton rectangleBut3("Decrease size", figuresVector, ActionType::DECREASE_SIZE, Shape::RectangleFigure);
    MenuButton circleBut4("Set random position", figuresVector, ActionType::RANDOM_POS, Shape::CircleFigure);
    MenuButton rectangleBut4("Set random position", figuresVector, ActionType::RANDOM_POS, Shape::RectangleFigure);

    MenuButton* butArr[8] {&circleBut1, &rectangleBut1, &circleBut2, &rectangleBut2, &circleBut3, &rectangleBut3, &circleBut4, &rectangleBut4};

    Menu menu(butArr, 8);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            menu.handleEvent(window, event);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) circle->move(sf::Vector2f(-1.0f, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) circle->move(sf::Vector2f(1.0f, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) circle->move(sf::Vector2f(0.0f, -1.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) circle->move(sf::Vector2f(0.0f, 1.0f));

        window.clear(sf::Color::Black);
        for (size_t i = 0; i < figuresVector.size(); i++) figuresVector[i]->draw(window);
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
