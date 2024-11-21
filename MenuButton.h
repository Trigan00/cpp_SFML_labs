#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "figures/Circle.h"
#include "figures/Figure.h"
#include "figures/FigureShape.h"
#include "VectorInit.h"


enum ActionType { CREATE_CIRCLE, CHANGE_VISIBILITY, INCREASE_SIZE, DECREASE_SIZE, RANDOM_POS, ACTION, CLEAR_VECTOR, FILL_VECTOR, MOVE_CIRCLES_RIGHT, MOVE_CIRCLES_LEFT, MOVE_CIRCLES_UP, MOVE_CIRCLES_DOWN};

class MenuButton
{
public:
    sf::RectangleShape background;

    MenuButton(const std::string& name, std::vector<Figure*>& figVector, ActionType actionType, Shape figureShape) : title(name), figuresVector(figVector), action(actionType), shape(figureShape) {
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
        figuresVector.push_back(circle);
    }

    void changeVisibility() {
        if(shape == All) {
            for (size_t i = 0; i < figuresVector.size(); i++)
            {
                figuresVector[i]->setIsActive(!figuresVector[i]->getIsActive());
            }
        }else{
            for (size_t i = 0; i < figuresVector.size(); i++)
            {
                if (figuresVector[i]->getShape() == shape)
                {
                    figuresVector[i]->setIsActive(!figuresVector[i]->getIsActive());

                }
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

    void doAction() {
        for (size_t i = 0; i < figuresVector.size(); i++)
        {
            if (figuresVector[i]->getShape() == shape)
            {
                figuresVector[i]->action();

            }
        }
    }

    void clearVector(){
        for (Figure* fig : figuresVector) {
            delete fig;
        }
        figuresVector.clear();
    }

    void fillVector(){
        clearVector();
        vectorInit(&figuresVector);
    }

    void moveCircles(sf::Vector2f dir){
        for (Figure* fig : figuresVector) {
            if (Circle* circle = dynamic_cast<Circle*>(fig)) {
                circle->move(dir);
            }
        }
    }

    void onClick(){
        switch (action)
        {
        case CREATE_CIRCLE: createCircle(); break;
        case CHANGE_VISIBILITY: changeVisibility(); break;
        case INCREASE_SIZE: changeSize(5.0f); break;
        case DECREASE_SIZE: changeSize(-5.0f); break;
        case RANDOM_POS: setRandomPos(); break;
        case ACTION: doAction(); break;
        case CLEAR_VECTOR: clearVector(); break;
        case FILL_VECTOR: fillVector(); break;
        case MOVE_CIRCLES_RIGHT: moveCircles(sf::Vector2f(5.0f, 0.0f)); break;
        case MOVE_CIRCLES_LEFT: moveCircles(sf::Vector2f(-5.0f, 0.0f)); break;
        case MOVE_CIRCLES_UP: moveCircles(sf::Vector2f(0.0f, -5.0f)); break;
        case MOVE_CIRCLES_DOWN: moveCircles(sf::Vector2f(0.0f, 5.0f)); break;
        default: break;
        }
    }

private:
    std::string title;
    sf::Text buttonText;
    sf::Font font;
    std::vector<Figure*>& figuresVector;
    ActionType action;
    Shape shape;
};




#endif