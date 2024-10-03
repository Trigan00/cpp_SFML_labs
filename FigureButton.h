#include <SFML/Graphics.hpp>
#include "FigureShape.h"

class FigureButton{
    public:
        Shape shape;
        sf::RectangleShape button;

        sf::Text text;
        sf::Font font;

        FigureButton(Shape figureShape): shape(figureShape) {
            button.setSize(sf::Vector2f(50, 50));
            button.setFillColor(sf::Color::White);

            // text.setFont(font);
            // text.setFillColor(sf::Color::Green);
            // text.setCharacterSize(14);
            // text.setString("S");
            // switch (figureShape)
            // {
            // case Shape::CircleFigure:
            //     text.setString("S");
            //     break;
            // case Shape::RectangleFigure:
            //     text.setString("R");
            //     break;
            // default:
            //     break;
            // }

        }


        
};