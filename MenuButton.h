#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "figures/Figure.h"
#include "figures/FigureShape.h"

enum ActionType {CHANGE_VISIBILITY, INCREASE_SIZE, DECREASE_SIZE, RANDOM_POS};

class MenuButton
{
public:
    sf::RectangleShape background;

    MenuButton(const std::string& name, std::vector<Figure*> figVector, ActionType actionType, Shape figureShape) : title(name), figuresVector(figVector), action(actionType), shape(figureShape) {
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

    void changeVisibility() {
        for (size_t i = 0; i < figuresVector.size(); i++)
        {
            if (figuresVector[i]->getShape() == shape)
            {
                figuresVector[i]->setIsActive(!figuresVector[i]->getIsActive());

            }
        }
    }

    void changeSize(float offset) {
        for (size_t i = 0; i < figuresVector.size(); i++)
        {
            if (figuresVector[i]->getShape() == shape)
            {
                figuresVector[i]->setSize(offset);

            }
        }
    }

    void setRandomPos() {
        for (size_t i = 0; i < figuresVector.size(); i++)
        {
            if (figuresVector[i]->getShape() == shape)
            {
                figuresVector[i]->setPos(figuresVector[i]->getRandomPos());

            }
        }
    }

    void onClick(){
        switch (action)
        {
        case CHANGE_VISIBILITY:
            changeVisibility();
            break;
        case INCREASE_SIZE:
            changeSize(5.0f);
            break;
        case DECREASE_SIZE:
            changeSize(-5.0f);
            break;
        case RANDOM_POS:
            setRandomPos();
            break;
        default:
            break;
        }
    }

private:
    std::string title;
    sf::Text buttonText;
    sf::Font font;
    std::vector<Figure*> figuresVector;
    ActionType action;
    Shape shape;
};




#endif