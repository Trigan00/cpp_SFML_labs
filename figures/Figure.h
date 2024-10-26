#ifndef FIGURE_H
#define FIGURE_H

#include "FigureShape.h"
#include "Point.h"

class Figure {
public:

    Figure(const sf::Vector2f& localPosition): point(localPosition){}

    virtual void move(const sf::Vector2f& offset) = 0;
    virtual void setSize(float offset) = 0;
    virtual void setPos(const sf::Vector2f& pos) = 0;
    virtual Shape getShape() const = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void action() = 0;

    bool getIsActive() const {return isActive;}
    void setIsActive(bool isAct) {isActive = isAct;}

    sf::Vector2f getRandomPos(int XMax = 700, int YMax = 500){
        const float offsetX = 0 + ( std::rand() % ( XMax - 0 + 1 ) ); 
        const float offsetY = 0 + ( std::rand() % ( YMax - 0 + 1 ) ); 
        return sf::Vector2f(offsetX, offsetY);
    }

private:
    bool isActive {true};

protected:
    Point point;
};

#endif // FIGURE_H
