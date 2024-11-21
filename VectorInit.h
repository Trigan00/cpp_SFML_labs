#ifndef VECTORINIT_H
#define VECTORINIT_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "figures/Figure.h"
#include "figures/Circle.h"
#include "figures/Ring.h"
#include "figures/Rectangle.h"
#include "figures/Line.h"
#include "figures/SquareCircle.h"
#include "figures/Ellipse.h"
#include "figures/Rhombus.h"
#include "figures/Trapezoid.h"
#include "figures/FigureShape.h"

sf::Vector2f getRandomPos(int XMax = 600, int YMax = 500){
    const float x = 0 + ( std::rand() % ( XMax - 0 + 1 ) ); 
    const float y = 0 + ( std::rand() % ( YMax - 0 + 1 ) ); 
    return sf::Vector2f(x, y);
}

void vectorInit(std::vector<Figure*>* vector){
    std::srand(static_cast<unsigned>(std::time(0)));

    for (int i = 0; i < 10; i++)
    {
        Shape randomShape = static_cast<Shape>(std::rand() % 7);
        int R = std::rand() % 255;
        int G = std::rand() % 255;
        int B = std::rand() % 255;
        
        sf::Vector2f randomPos = getRandomPos();
        switch (randomShape) {
            case CircleFigure: vector->push_back(new Circle(50.0f, randomPos, sf::Color(R, G, B))); break;
            case RectangleFigure: vector->push_back(new Rectangle(120.0f, 50.0f, randomPos, sf::Color(R, G, B))); break;
            case LineFigure: vector->push_back(new Line(150.0f, 5.0f, randomPos, sf::Color(R, G, B))); break;
            case RingFigure: vector->push_back(new Ring(50.0f, randomPos, sf::Color(R, G, B))); break;
            case SquareCircleFigure: vector->push_back(new SquareCircle(100.0f, 100.0f, randomPos, sf::Color(R, G, B))); break;
            case EllipseFigure: vector->push_back(new Ellipse(100.0f, 50.0f, randomPos, sf::Color(R, G, B))); break;
            case QuadrilateralFigure: vector->push_back(new Rhombus(100, 100, randomPos, sf::Color(R, G, B))); break;
        }
    }

}

#endif