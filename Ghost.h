#pragma once
#include "Entity.h"
#include "Cell.h"
#include "Pacman.h"
static const float GHOST_SPEED = 10.f; 
static const float GHOST_RADIUS = 16.f;


static const sf::Color GHOST_COLOR1 = sf::Color(255, 0, 0);
static const sf::Color GHOST_COLOR2 = sf::Color(255, 0, 255);
static const sf::Color GHOST_COLOR3 = sf::Color(255, 255, 0);
static const sf::Color GHOST_COLOR4 = sf::Color(0, 0, 255);


class Ghost : public MovingEntity
{


public:
    std::vector<Cell*>& cells;
    Direction currentDirection;
    sf::Texture pau;
    Ghost(int xPos, int yPos, std::vector<Cell*>& cells) : cells(cells) {
        currentDirection = Direction::NONE;

        shape.setRadius(GHOST_RADIUS);

        shape.setPosition(sf::Vector2f(xPos, yPos));

    }

    void updateGhostDirection() {
        switch (currentDirection)
        {
        case Direction::UP:
            direction = Direction::DOWN;
            break;
        case Direction::DOWN:
            direction = Direction::LEFT;
            break;
        case Direction::LEFT:
            direction = Direction::RIGHT;
            break;
        case Direction::RIGHT:
            direction = Direction::NONE;
            break;
        case Direction::NONE:
            direction = Direction::LEFT;
            break;
        }
    }

    void update(float elapsedTime) {
        const float step = GHOST_SPEED * elapsedTime;

        sf::Vector2f movement(0.f, 0.f);
        switch (direction)
        {
        case Direction::UP:
            movement.y -= step;
            break;
        case Direction::DOWN:
            movement.y += step;
            break;
        case Direction::LEFT:
            movement.x -= step;
            break;
        case Direction::RIGHT:
            movement.x += step;
            break;
        case Direction::NONE:
            updateGhostDirection();
            break;
        }

        sf::Vector2f currentPosition = shape.getPosition();

        for (const auto& cell : cells) {
            sf::Vector2f wallPosition = cell->getPosition();

            
            float distanceX = (currentPosition.x - wallPosition.x - 9.f);
            float distanceY = (currentPosition.y - wallPosition.y - 9.f);

            
            if (std::abs(distanceX) < 42.f and std::abs(distanceY) < 42.f) {

                if (std::abs(distanceX) < 42.f) {
                    if (distanceX > 0) {
                        movement.x += step;
                    }
                    else {
                        movement.x -= step;
                    }
                }
                if (std::abs(distanceY) < 42.f) {
                    if (distanceY > 0) {
                        movement.y += step;
                    }
                    else {
                        movement.y -= step;
                    }
                }

            }
        }





        shape.move(movement);
    };
};


class Blinky : public Ghost {
public:
    Blinky(int xPos, int yPos, std::vector<Cell*>& cells) : Ghost(xPos, yPos, cells) {
        
        shape.setFillColor(GHOST_COLOR1);
    }
};
class Clyde : public Ghost {
public:
    Clyde(int xPos, int yPos, std::vector<Cell*>& cells) : Ghost(xPos, yPos, cells) {
        
        shape.setFillColor(GHOST_COLOR2);
    }
};
class Inky : public Ghost {
public:
    Inky(int xPos, int yPos, std::vector<Cell*>& cells) : Ghost(xPos, yPos, cells) {
        
        shape.setFillColor(GHOST_COLOR3);
    }
};
class Pinky : public Ghost {
public:
    Pinky(int xPos, int yPos, std::vector<Cell*>& cells) : Ghost(xPos, yPos, cells) {
        
        shape.setFillColor(GHOST_COLOR4);
    }
};
