#ifndef FIGUREBUTTONS_H
#define FIGUREBUTTONS_H

#include <SFML/Graphics.hpp>
#include "figures/FigureShape.h"

struct FigureButton
{
    Shape shape;
    sf::RectangleShape button;

    FigureButton(Shape s) : shape(s), button(sf::Vector2f(50, 50)) {
        button.setFillColor(sf::Color::White);
    }
};


class FigureButtons
{
public:
    Shape activeFigure = Shape::CircleFigure;

    FigureButtons(){
        figureShadow.setSize(sf::Vector2f(50, 50));
        figureShadow.setFillColor(sf::Color(0, 0, 0, 100));
        
        figureButtonsVector.push_back(FigureButton(Shape::CircleFigure));
        figureButtonsVector.push_back(FigureButton(Shape::RectangleFigure));
        figureButtonsVector.push_back(FigureButton(Shape::LineFigure));
        figureButtonsVector.push_back(FigureButton(Shape::EllipseFigure));
        figureButtonsVector.push_back(FigureButton(Shape::All));
        for (int i = 0; i < figureButtonsVector.size(); ++i) {
            figureButtonsVector[i].button.setPosition(140, 160 + i * 70);
        }
    };

    void handleEvent(sf::RenderWindow& window) {
        for (int i = 0; i < figureButtonsVector.size(); ++i) {
            FigureButton but = figureButtonsVector[i];
            if (isMouseOver(but.button, window)) activeFigure = but.shape;
        }
    }

    void draw(sf::RenderWindow& window) {
        for (auto& button : figureButtonsVector) {
            if (button.shape == activeFigure) {
                figureShadow.setPosition(button.button.getPosition());
            }
            window.draw(button.button);
        }

        drawFigures(window);

        window.draw(figureShadow);
    }

private:

    std::vector<FigureButton> figureButtonsVector;
    sf::RectangleShape figureShadow;

    bool isMouseOver(const sf::RectangleShape& button, sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBounds = button.getGlobalBounds();
        return buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }

    void drawFigures(sf::RenderWindow& window){
        sf::CircleShape circleF(20);
        circleF.setFillColor(sf::Color::Blue);
        circleF.setPosition(145,165);

        sf::RectangleShape RectangleF(sf::Vector2f(40, 40));
        RectangleF.setFillColor(sf::Color::Blue);
        RectangleF.setPosition(145,235);
        
        sf::RectangleShape LineF(sf::Vector2f(40, 5));
        LineF.setFillColor(sf::Color::Blue);
        LineF.setPosition(145,305);
        
        sf::CircleShape ellipseF(1.0f);
        ellipseF.setPointCount(50);
        ellipseF.setScale(20, 10);
        ellipseF.setFillColor(sf::Color::Blue);
        ellipseF.setPosition(145,375);


        window.draw(circleF);
        window.draw(RectangleF);
        window.draw(LineF);
        window.draw(ellipseF);
    }


};

#endif