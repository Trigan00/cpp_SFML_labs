#ifndef FIGURE_H
#define FIGURE_H

#include "FigureShape.h"


class Figure {
public:

    virtual void move(const sf::Vector2f& offset) = 0;
    virtual void setRandomPosition() = 0;
    virtual Shape getShape() const = 0;

    bool getIsActive() const {return isActive;}
    void setIsActive(bool isAct) {isActive = isAct;}

protected:
    sf::Vector2f getRandomPos(int from = -50, int to = 50){
        const float offsetX = from + ( std::rand() % ( to - from + 1 ) ); 
        const float offsetY = from + ( std::rand() % ( to - from + 1 ) ); 
        return sf::Vector2f(offsetX, offsetY);
    }

private:
    bool isActive {true};  

};

#endif // FIGURE_H
