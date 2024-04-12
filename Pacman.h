#pragma once
#include "Entity.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>



static const sf::Color PACKMAN_COLOR = sf::Color(255, 216, 0);
static const float PACKMAN_SPEED = 120.f; // pixels per second.
static const float PACKMAN_RADIUS = 16.f; // pixels



class Pacman : public MovingEntity
{
private:
    Direction currentDirection;
    bool isMoving;
    std::vector<Cell*>& cells;
    std::vector<Entity*> objects;
    sf::Texture texture;



public:
    Pacman(int xPos, int yPos, std::vector<Cell*>& cells) : cells(cells) {
        currentDirection = Direction::NONE;
        isMoving = false;
        shape.setRadius(PACKMAN_RADIUS);
        shape.setFillColor(PACKMAN_COLOR);
        shape.setPosition(sf::Vector2f(xPos, yPos));
        texture.loadFromFile("C:\\Users\\allll\\Downloads\\pngwing.com.png");
        sprite.setTexture(texture); 
        sprite.setPosition(sf::Vector2f(xPos, yPos));
        sprite.setScale(2.f * PACKMAN_RADIUS / texture.getSize().x, 2.f * PACKMAN_RADIUS / texture.getSize().y);


    }
    sf::Vector2f Getpos() {
        return shape.getPosition();
    }
    sf::Vector2f Getpos2() {
        return sprite.getPosition();
    }

    void updatePacmanDirection() {
        Direction newDirection = Direction::NONE;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            newDirection = Direction::UP;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            newDirection = Direction::DOWN;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            newDirection = Direction::LEFT;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            newDirection = Direction::RIGHT;
        }
        else if (currentDirection != Direction::NONE) {
            newDirection = currentDirection; 
        }
        
        if (newDirection != Direction::NONE) {
            currentDirection = newDirection;
            isMoving = true;
        }
    }

    void update(float elapsedTime) {
        sf::Vector2f currentPosition = shape.getPosition();
        const float step = PACKMAN_SPEED * elapsedTime;
        sprite.setPosition(shape.getPosition());

        updatePacmanDirection();

        sf::Vector2f movement(0.f, 0.f);
        switch (currentDirection)
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
            isMoving = false;
            break;
        }

        if (isMoving) {
            


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
};



