#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "figures/Figure.h"
#include "figures/FigureShape.h"

enum ActionType {CHANGE_VISIBILITY};

class MenuButton
{
public:
    sf::RectangleShape background;

    MenuButton(std::string& name, Figure* fig, ActionType actionType) : title(name), figure(fig), action(actionType) {
        background.setSize(sf::Vector2f(200, 50));
        background.setFillColor(sf::Color::Magenta);
    };

    Shape getShape() const {
        return figure->getShape();
    }

    void changeVisibility() {
        figure->setIsActive(!figure->getIsActive());
    }

    void onClick(){
        switch (action)
        {
        case CHANGE_VISIBILITY:
            changeVisibility();
            break;
        
        default:
            break;
        }
    }

private:
    std::string title;
    Figure* figure;
    ActionType action;
};




#endif