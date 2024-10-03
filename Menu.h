#include <SFML/Graphics.hpp>
#include <iostream>
#include "FigureButtons.h"

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

    }

    void handleEvent(sf::RenderWindow& window, const sf::Event& event) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (isMouseOver(openMenuButton, window)) {
                isMenuOpen = !isMenuOpen;  // Открыть/закрыть меню
            }

            if (isMenuOpen) {
                figureButtons.handleEvent(window);
                std::cout << figureButtons.activeFigure << std::endl;
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(openMenuButton);

        if (isMenuOpen) {
            window.draw(menuBackground);
            window.draw(figuresMenuBackground);
            figureButtons.draw(window);
        }
    }

private:
    sf::RectangleShape openMenuButton;
    sf::RectangleShape menuBackground;
    sf::RectangleShape figuresMenuBackground;
    FigureButtons figureButtons;
    bool isMenuOpen = false;

    bool isMouseOver(const sf::RectangleShape& button, sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBounds = button.getGlobalBounds();
        return buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
};