#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "WindowConsts.h"
#include "Menu.h"
#include "figures/Figure.h"
#include "figures/Circle.h"
#include "figures/Ring.h"
#include "figures/Rectangle.h"
#include "figures/Line.h"
#include "figures/SquareCircle.h"
#include "figures/FigureShape.h"
#include "MenuButton.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "SFML Project");
    window.setFramerateLimit(60);

    Circle* circle = new Circle(50.0f, sf::Vector2f(300.0f, 200.0f),sf::Color::Cyan);
    Rectangle* rectangle = new Rectangle(sf::Vector2f(120.0f, 50.0f), sf::Vector2f(500.0f, 200.0f), sf::Color::Magenta);
    Rectangle* line = new Line(sf::Vector2f(150.0f, 5.0f), sf::Vector2f(100.0f, 30.0f), sf::Color::Yellow);
    Circle* ring = new Ring(50.0f, sf::Vector2f(200.0f, 400.0f),sf::Color::Red);
    Rectangle* squareCircle = new SquareCircle(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(400.0f, 400.0f), sf::Color::Red);

    std::vector<Figure*> figuresVector {circle, rectangle, line, ring, squareCircle};

    MenuButton circleBut1("Show/Hide", figuresVector, ActionType::CHANGE_VISIBILITY, Shape::CircleFigure);
    MenuButton rectangleBut1("Show/Hide", figuresVector, ActionType::CHANGE_VISIBILITY, Shape::RectangleFigure);
    MenuButton lineBut1("Change color", figuresVector, ActionType::ACTION, Shape::LineFigure);
    MenuButton circleBut2("Increase size", figuresVector, ActionType::INCREASE_SIZE, Shape::CircleFigure);
    MenuButton rectangleBut2("Increase size", figuresVector, ActionType::INCREASE_SIZE, Shape::RectangleFigure);
    MenuButton circleBut3("Decrease size", figuresVector, ActionType::DECREASE_SIZE, Shape::CircleFigure);
    MenuButton rectangleBut3("Decrease size", figuresVector, ActionType::DECREASE_SIZE, Shape::RectangleFigure);
    MenuButton circleBut4("Set random position", figuresVector, ActionType::RANDOM_POS, Shape::CircleFigure);
    MenuButton rectangleBut4("Set random position", figuresVector, ActionType::RANDOM_POS, Shape::RectangleFigure);

    MenuButton* butArr[9] {&circleBut1, &rectangleBut1, &lineBut1, &circleBut2, &rectangleBut2, &circleBut3, &rectangleBut3, &circleBut4, &rectangleBut4};

    Menu menu(butArr, 9);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            menu.handleEvent(window, event);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) circle->move(sf::Vector2f(-3.0f, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) circle->move(sf::Vector2f(3.0f, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) circle->move(sf::Vector2f(0.0f, -3.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) circle->move(sf::Vector2f(0.0f, 3.0f));

        window.clear(sf::Color::Black);
        for (size_t i = 0; i < figuresVector.size(); i++) figuresVector[i]->draw(window);
        menu.draw(window);
        window.display();
    }

    for (size_t i = 0; i < figuresVector.size(); i++) {
        delete figuresVector[i];
        figuresVector[i] = nullptr;
    }

    return 0;
}
