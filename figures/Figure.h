#ifndef FIGURE_H
#define FIGURE_H

#include "FigureShape.h"
#include "Point.h"

class Figure {
public:

    Figure(const sf::Vector2f& localPosition, float w, float h): point(localPosition), width(w), height(h){}

    virtual void setSize(float offset) = 0;
    virtual void setPos(const sf::Vector2f& pos) = 0;
    virtual Shape getShape() const = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void action() = 0;

    bool getIsActive() const {return isActive;}
    void setIsActive(bool isAct) {isActive = isAct;}

    void move(const sf::Vector2f& offset) {
        const sf::Vector2f newPos = point.getPos() + offset;
        if (!posCheck(newPos)) return;
        point.setPos(point.getPos() + offset);
    }

    sf::Vector2f getRandomPos(int XMax = 700, int YMax = 500){
        const float offsetX = 0 + ( std::rand() % ( XMax - 0 + 1 ) ); 
        const float offsetY = 0 + ( std::rand() % ( YMax - 0 + 1 ) ); 
        return sf::Vector2f(offsetX, offsetY);
    }

private:
    bool isActive {true};

protected:
    Point point;
    float width;
    float height;
    
    bool posCheck(sf::Vector2f newPos) {
        if (newPos.x < 0) return false;
        if (newPos.x + width > windowX) return false;
        if (newPos.y < 0) return false;
        if (newPos.y + height > windowY) return false;
        return true;
    }
};

#endif // FIGURE_H
