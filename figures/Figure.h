#ifndef FIGURE_H
#define FIGURE_H


class Figure {
public:

    virtual void move(const sf::Vector2f& offset) = 0;
    virtual void setRandomPosition() = 0;

    sf::Vector2f getRandomPos(int from = -50, int to = 50){
        const float offsetX = from + ( std::rand() % ( to - from + 1 ) ); 
        const float offsetY = from + ( std::rand() % ( to - from + 1 ) ); 
        return sf::Vector2f(offsetX, offsetY);
    }

    bool getIsActive() const {return isActive;}
    void setIsActive(bool isAct) {isActive = isAct;}

private:
    bool isActive;  

};

#endif // FIGURE_H
