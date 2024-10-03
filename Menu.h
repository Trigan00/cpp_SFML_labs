#include <SFML/Graphics.hpp>
#include <iostream>
#include "FigureButton.h"
#include "FigureShape.h"

class Menu {
public:
    Menu() {
        openMenuButton.setSize(sf::Vector2f(50, 50));
        openMenuButton.setPosition(700, 20);
        openMenuButton.setFillColor(sf::Color::Blue);

        menuBackground.setSize(sf::Vector2f(400, 300));
        menuBackground.setPosition(200, 150);
        menuBackground.setFillColor(sf::Color(0, 0, 100, 200));
  
        figuresMenuBackground.setSize(sf::Vector2f(70, 150));
        figuresMenuBackground.setPosition(130, 150);
        figuresMenuBackground.setFillColor(sf::Color(0, 100, 0, 200));

        figureShadow.setSize(sf::Vector2f(50, 50));
        figureShadow.setFillColor(sf::Color(0, 0, 0, 100));
        
        figureButtons.push_back(FigureButton(Shape::CircleFigure));
        figureButtons.push_back(FigureButton(Shape::RectangleFigure));
        for (int i = 0; i < figureButtons.size(); ++i) figureButtons[i].button.setPosition(140, 160 + i * 70);

    }

    void handleEvent(sf::RenderWindow& window, const sf::Event& event) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (isMouseOver(openMenuButton, window)) {
                isMenuOpen = !isMenuOpen;  // Открыть/закрыть меню
            }

            if (isMenuOpen) {
                for (int i = 0; i < figureButtons.size(); ++i) {
                    if (isMouseOver(figureButtons[i].button, window)) activeFigure = figureButtons[i].shape;
                }
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(openMenuButton);

        if (isMenuOpen) {
            window.draw(menuBackground);
            window.draw(figuresMenuBackground);
            for (auto& button : figureButtons) {
                if (button.shape == activeFigure) {
                    figureShadow.setPosition(button.button.getPosition());
                }
                window.draw(button.button);
            }
            window.draw(figureShadow);
        }
    }

private:
    sf::RectangleShape openMenuButton;
    sf::RectangleShape menuBackground;
    sf::RectangleShape figuresMenuBackground;
    std::vector<FigureButton> figureButtons;
    Shape activeFigure = Shape::CircleFigure;
    bool isMenuOpen = false;

    sf::RectangleShape figureShadow;

    bool isMouseOver(const sf::RectangleShape& button, sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBounds = button.getGlobalBounds();
        return buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
};