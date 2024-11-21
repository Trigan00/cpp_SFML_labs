#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "figures/Circle.h"
#include "figures/Figure.h"
#include "figures/FigureShape.h"
#include "ButActions.h"
#include "FiguresList.h"



class MenuButton
{
public:
    sf::RectangleShape background;

    MenuButton(const std::string& name, FiguresList& list, ActionType actionType, Shape figureShape) : title(name), FigList(list), action(actionType), shape(figureShape) {
        background.setSize(sf::Vector2f(250, 50));
        background.setFillColor(sf::Color::Magenta);

        if (!font.loadFromFile("Roboto-Light.ttf")) {
            throw std::runtime_error("Cannot load font");
        }

        buttonText.setFont(font);
        buttonText.setString(name);
        buttonText.setCharacterSize(24);
        buttonText.setFillColor(sf::Color::White);

    };

    Shape getShape() const {
        return shape;
    }

    void setTextPos(int x, int y){
        buttonText.setPosition(
            x + (background.getSize().x - buttonText.getLocalBounds().width) / 2, 
            y + (background.getSize().y - buttonText.getLocalBounds().height) / 2
        );
    }

    void draw(sf::RenderWindow& window) {
        window.draw(background);
        window.draw(buttonText);
    }

    void createCircle(){
        Circle* circle = new Circle(50.0f, sf::Vector2f(400.0f, 200.0f),sf::Color::Green);
        circle->setPos(circle->getRandomPos());
        FigList.add(circle);
    }

    void clearVector(){
        FigList.clear();
    }

    void fillVector(){
        FigList.init();
    }

    void onClick(){
        
        switch (action)
        {
        case CREATE_CIRCLE: createCircle(); break;
        case CLEAR_VECTOR: clearVector(); break;
        case FILL_VECTOR: fillVector(); break;
        default: FigList.iterator(action, shape); break;
        }
    }

private:
    std::string title;
    sf::Text buttonText;
    sf::Font font;
    FiguresList& FigList;
    ActionType action;
    Shape shape;
};




#endif