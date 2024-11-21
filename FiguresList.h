#ifndef FIGURESLIST_H
#define FIGURESLIST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "figures/Figure.h"
#include "figures/FigureShape.h"
#include "ButActions.h"


#include "figures/Circle.h"
#include "figures/Ring.h"
#include "figures/Rectangle.h"
#include "figures/Line.h"
#include "figures/SquareCircle.h"
#include "figures/Ellipse.h"
#include "figures/Rhombus.h"
#include "figures/Trapezoid.h"
#include "figures/FigureShape.h"


struct Node {
    Figure* figure;
    Node* next;
};

class FiguresList {
public:

    void init(){
        std::srand(static_cast<unsigned>(std::time(0)));

        for (int i = 0; i < 10; i++)
        {
            Shape randomShape = static_cast<Shape>(std::rand() % 7);
            int R = std::rand() % 255;
            int G = std::rand() % 255;
            int B = std::rand() % 255;
            
            sf::Vector2f randomPos(0 + ( std::rand() % ( 600 - 0 + 1 ) ),  0 + ( std::rand() % ( 500 - 0 + 1 ) ));
            switch (randomShape) {
                case CircleFigure: add(new Circle(50.0f, randomPos, sf::Color(R, G, B))); break;
                case RectangleFigure: add(new Rectangle(120.0f, 50.0f, randomPos, sf::Color(R, G, B))); break;
                case LineFigure: add(new Line(150.0f, 5.0f, randomPos, sf::Color(R, G, B))); break;
                case RingFigure: add(new Ring(50.0f, randomPos, sf::Color(R, G, B))); break;
                case SquareCircleFigure: add(new SquareCircle(100.0f, 100.0f, randomPos, sf::Color(R, G, B))); break;
                case EllipseFigure: add(new Ellipse(100.0f, 50.0f, randomPos, sf::Color(R, G, B))); break;
                case QuadrilateralFigure: add(new Rhombus(100, 100, randomPos, sf::Color(R, G, B))); break;
            }
        }

        std::cout << "Контейнер заполнен" << std::endl;

    }

    void clear(){
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        std::cout << "Контейнер уничтожен" << std::endl;

    }

    FiguresList() : head(nullptr) {std::cout << "Создан контейнер" << std::endl; init();}

    ~FiguresList() {clear();}

    void moveByKey(sf::Vector2f dir){
        Node* temp = head;
        while (temp) {
            temp->figure->move(dir);
            temp = temp->next;
        }
    }

    void draw(sf::RenderWindow& window){
        Node* temp = head;
        while (temp) {
            temp->figure->draw(window);
            temp = temp->next;
        }
    }

    void add(Figure* figure) {
        Node* newNode = new Node{figure, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void iterator(ActionType action, Shape shape){
        Node* temp = head;
        while (temp) {
            switch (action)
            {
            case CHANGE_VISIBILITY:
                {
                    if (shape == All) temp->figure->setIsActive(!(temp->figure->getIsActive()));
                    else if (temp->figure->getShape() == shape) temp->figure->setIsActive(!(temp->figure->getIsActive()));
                    break;
                }
            case INCREASE_SIZE: if (temp->figure->getShape() == shape) temp->figure->setSize(5.0f); break;
            case DECREASE_SIZE: if (temp->figure->getShape() == shape) temp->figure->setSize(-5.0f); break;
            case RANDOM_POS: if (temp->figure->getShape() == shape) temp->figure->setPos(temp->figure->getRandomPos()); break;
            case ACTION: if (temp->figure->getShape() == shape) temp->figure->action(); break;
            case MOVE_CIRCLES_RIGHT: if (Circle* circle = dynamic_cast<Circle*>(temp->figure)) circle->move(sf::Vector2f(5.0f, 0.0f)); break;
            case MOVE_CIRCLES_LEFT: if (Circle* circle = dynamic_cast<Circle*>(temp->figure)) circle->move(sf::Vector2f(-5.0f, 0.0f)); break;
            case MOVE_CIRCLES_UP: if (Circle* circle = dynamic_cast<Circle*>(temp->figure)) circle->move(sf::Vector2f(0.0f, -5.0f)); break;
            case MOVE_CIRCLES_DOWN: if (Circle* circle = dynamic_cast<Circle*>(temp->figure)) circle->move(sf::Vector2f(0.0f, 5.0f)); break;
            default: break;
            }
            temp = temp->next;
        }
    }


private:
    Node* head;
};

#endif
