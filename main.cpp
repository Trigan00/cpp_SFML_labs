#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "WindowConsts.h"
#include "Menu.h"
#include "figures/FigureShape.h"
#include "MenuButton.h"
#include "VectorInit.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "SFML Project");
    window.setFramerateLimit(60);

    // Circle* circle = new Circle(50.0f, 50.0f, sf::Vector2f(300.0f, 200.0f),sf::Color::Cyan);
    // Rectangle* rectangle = new Rectangle(120.0f, 50.0f, sf::Vector2f(400.0f, 50.0f), sf::Color::Magenta);
    // Rectangle* line = new Line(150.0f, 5.0f, sf::Vector2f(100.0f, 30.0f), sf::Color::Yellow);
    // Circle* ring = new Ring(50.0f, sf::Vector2f(100.0f, 400.0f),sf::Color::Red);
    // Rectangle* squareCircle = new SquareCircle(100.0f, 100.0f, sf::Vector2f(300.0f, 400.0f), sf::Color::Red);
    // Ellipse* ellipse = new Ellipse(100.0f, 50.0f, sf::Vector2f(500.0f, 450.0f),sf::Color::Red);
    // Rhombus* rhombus = new Rhombus(100, 200, sf::Vector2f(20, 100), sf::Color::Red);
    // Trapezoid* trapezoid = new Trapezoid(100.0f, 130.0f, sf::Vector2f(450.0f, 250.0f), sf::Color::Red);

    // std::vector<Figure*> figuresVector {circle, rectangle, line, ring, squareCircle, rhombus, trapezoid, ellipse};
    std::vector<Figure*> figuresVector {};
    vectorInit(&figuresVector);

    MenuButton circleBut0("Create", figuresVector, ActionType::CREATE_CIRCLE, Shape::CircleFigure);
    MenuButton circleBut1("Show/Hide", figuresVector, ActionType::CHANGE_VISIBILITY, Shape::CircleFigure);
    MenuButton rectangleBut1("Show/Hide", figuresVector, ActionType::CHANGE_VISIBILITY, Shape::RectangleFigure);
    MenuButton lineBut1("Change color", figuresVector, ActionType::ACTION, Shape::LineFigure);
    MenuButton circleBut2("Increase size", figuresVector, ActionType::INCREASE_SIZE, Shape::CircleFigure);
    MenuButton rectangleBut2("Increase size", figuresVector, ActionType::INCREASE_SIZE, Shape::RectangleFigure);
    MenuButton circleBut3("Decrease size", figuresVector, ActionType::DECREASE_SIZE, Shape::CircleFigure);
    MenuButton rectangleBut3("Decrease size", figuresVector, ActionType::DECREASE_SIZE, Shape::RectangleFigure);
    MenuButton circleBut4("Set random position", figuresVector, ActionType::RANDOM_POS, Shape::CircleFigure);
    MenuButton rectangleBut4("Set random position", figuresVector, ActionType::RANDOM_POS, Shape::RectangleFigure);
    MenuButton ellipseBut1("Rotate", figuresVector, ActionType::ACTION, Shape::EllipseFigure);

    MenuButton allBut0("Show/Hide", figuresVector, ActionType::CHANGE_VISIBILITY, Shape::All);
    MenuButton allBut1("Fill vector", figuresVector, ActionType::FILL_VECTOR, Shape::All);
    MenuButton allBut2("Clear vector", figuresVector, ActionType::CLEAR_VECTOR, Shape::All);
    MenuButton allBut3("Move circles up", figuresVector, ActionType::MOVE_CIRCLES_UP, Shape::All);
    MenuButton allBut4("Move circles down", figuresVector, ActionType::MOVE_CIRCLES_DOWN, Shape::All);
    MenuButton allBut5("Move circles right", figuresVector, ActionType::MOVE_CIRCLES_RIGHT, Shape::All);
    MenuButton allBut6("Move circles left", figuresVector, ActionType::MOVE_CIRCLES_LEFT, Shape::All);


    MenuButton* butArr[18] {&circleBut0, &circleBut1, &rectangleBut1, &lineBut1, &circleBut2, &rectangleBut2,
                            &circleBut3, &rectangleBut3, &circleBut4, &rectangleBut4, &ellipseBut1, &allBut0, &allBut1, &allBut2, &allBut3, &allBut4, &allBut5, &allBut6};

    Menu menu(butArr, 18);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            menu.handleEvent(window, event);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) for (size_t i = 0; i < figuresVector.size(); i++) figuresVector[i]->move(sf::Vector2f(-3.0f, 0.0f)); 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) for (size_t i = 0; i < figuresVector.size(); i++) figuresVector[i]->move(sf::Vector2f(3.0f, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) for (size_t i = 0; i < figuresVector.size(); i++) figuresVector[i]->move(sf::Vector2f(0.0f, -3.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) for (size_t i = 0; i < figuresVector.size(); i++) figuresVector[i]->move(sf::Vector2f(0.0f, 3.0f));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) figuresVector[0]->move(sf::Vector2f(-3.0f, 0.0f)); 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) figuresVector[0]->move(sf::Vector2f(3.0f, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) figuresVector[0]->move(sf::Vector2f(0.0f, -3.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) figuresVector[0]->move(sf::Vector2f(0.0f, 3.0f));

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
