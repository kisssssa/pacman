#pragma once
#include "Entity.h"
#include<iostream>

class Cell : public StaticEntity
{
private:
    int size;

public:
    Cell(int x, int y, int s) : size(s) {
        xPos = x;
        yPos = y;
    }

    void render(sf::RenderWindow& window) {
        shape.setFillColor(sf::Color(52, 93, 199));
        shape.setSize(sf::Vector2f(size, size));
        shape.setPosition(sf::Vector2f(xPos, yPos));
        window.draw(shape);
    }

    sf::Vector2f getPosition() const {
        return sf::Vector2f(xPos, yPos);
    }

    int getSize() const {
        return size;
    }
};



