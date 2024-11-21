#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "WindowConsts.h"
#include "Menu.h"
#include "figures/FigureShape.h"
#include "FiguresList.h"
#include "MenuButton.h"
// #include "VectorInit.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "SFML Project");
    window.setFramerateLimit(60);

    // std::vector<Figure*> figuresVector {};
    FiguresList list = FiguresList();
    // vectorInit(&list);

    MenuButton circleBut0("Create", list, ActionType::CREATE_CIRCLE, Shape::CircleFigure);
    MenuButton circleBut1("Show/Hide", list, ActionType::CHANGE_VISIBILITY, Shape::CircleFigure);
    MenuButton rectangleBut1("Show/Hide", list, ActionType::CHANGE_VISIBILITY, Shape::RectangleFigure);
    MenuButton lineBut1("Change color", list, ActionType::ACTION, Shape::LineFigure);
    MenuButton circleBut2("Increase size", list, ActionType::INCREASE_SIZE, Shape::CircleFigure);
    MenuButton rectangleBut2("Increase size", list, ActionType::INCREASE_SIZE, Shape::RectangleFigure);
    MenuButton circleBut3("Decrease size", list, ActionType::DECREASE_SIZE, Shape::CircleFigure);
    MenuButton rectangleBut3("Decrease size", list, ActionType::DECREASE_SIZE, Shape::RectangleFigure);
    MenuButton circleBut4("Set random position", list, ActionType::RANDOM_POS, Shape::CircleFigure);
    MenuButton rectangleBut4("Set random position", list, ActionType::RANDOM_POS, Shape::RectangleFigure);
    MenuButton ellipseBut1("Rotate", list, ActionType::ACTION, Shape::EllipseFigure);

    MenuButton allBut0("Show/Hide", list, ActionType::CHANGE_VISIBILITY, Shape::All);
    MenuButton allBut1("Fill vector", list, ActionType::FILL_VECTOR, Shape::All);
    MenuButton allBut2("Clear vector", list, ActionType::CLEAR_VECTOR, Shape::All);
    MenuButton allBut3("Move circles up", list, ActionType::MOVE_CIRCLES_UP, Shape::All);
    MenuButton allBut4("Move circles down", list, ActionType::MOVE_CIRCLES_DOWN, Shape::All);
    MenuButton allBut5("Move circles right", list, ActionType::MOVE_CIRCLES_RIGHT, Shape::All);
    MenuButton allBut6("Move circles left", list, ActionType::MOVE_CIRCLES_LEFT, Shape::All);


    MenuButton* butArr[18] {&circleBut0, &circleBut1, &rectangleBut1, &lineBut1, &circleBut2, &rectangleBut2,
                            &circleBut3, &rectangleBut3, &circleBut4, &rectangleBut4, &ellipseBut1, &allBut0, &allBut1, &allBut2, &allBut3, &allBut4, &allBut5, &allBut6};

    Menu menu(butArr, 18);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            menu.handleEvent(window, event);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) list.moveByKey(sf::Vector2f(-3.0f, 0.0f)); 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) list.moveByKey(sf::Vector2f(3.0f, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) list.moveByKey(sf::Vector2f(0.0f, -3.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) list.moveByKey(sf::Vector2f(0.0f, 3.0f));
        
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) figuresVector[0]->move(sf::Vector2f(-3.0f, 0.0f)); 
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) figuresVector[0]->move(sf::Vector2f(3.0f, 0.0f));
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) figuresVector[0]->move(sf::Vector2f(0.0f, -3.0f));
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) figuresVector[0]->move(sf::Vector2f(0.0f, 3.0f));

        window.clear(sf::Color::Black);
        list.draw(window);
        menu.draw(window);
        window.display();
    }


    return 0;
}
