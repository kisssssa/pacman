#include "Game.h"
#include "Entity.h"
#include "Ghost.h"
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>




Game::Game() {
    int p = 0;
    createMaze();
    font.loadFromFile("C:\\Users\\allll\\Downloads\\transformerssolidnormal.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("Score:");
    scoreText.setPosition(10.f, 10.f);
    label.setFont(font);
    label.setCharacterSize(24);
    label.setFillColor(sf::Color::White);
    label.setPosition(150.f, 10.f);
    pacman = new Pacman(100, 50, cells);
    blinky = new Blinky(880, 40, cells);
    clyde = new Clyde(880, 930, cells);
    inky = new Inky(120, 920, cells);
    pinky = new Pinky(800, 800, cells);
    buffer.loadFromFile("C:\\Users\\allll\\Downloads\\start.wav");
    buffer1.loadFromFile("C:\\Users\\allll\\Downloads\\sfx-2.wav");
    buffer2.loadFromFile("C:\\Users\\allll\\Downloads\\2-track-2.wav");
    buffer3.loadFromFile("C:\\Users\\allll\\Downloads\\pryijok-i-borba.wav");
    sound = sf::Sound(buffer);
    sound1 = sf::Sound(buffer1);
    sound2 = sf::Sound(buffer2);
    sound3 = sf::Sound(buffer3);
    sound.play();
    // 500 410

    // create factory AbstractGhostFactory* ghostFactory;
    // read the text file with maze and positions of entities
    //if x - create wall and add into walls
    //if P - create pacman, add into objects
    //if b/p/i/c - create factories
    //create ghosts and add them into objects and ghosts
    //if . - create PacGum into objects
    //if o - create SuperPacGum
    //if - - create GhostHouse 
}


void Game::createMaze()
{
    char initialMap[MAP_HEIGHT][MAP_WIDTH] =
    {
       {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', ' ', ' ', ' ', ' ', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'x'},
        {'x', ' ', 'x', 'x', '.', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', ' ', 'x'},
        {'x', ' ', 'x', '.', '.', '.', 'x', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'x'},
        {'x', '@', 'x', '.', 'x', '.', 'x', '.', 'x', 'x', 'x', ' ', 'x', '@', 'x', 'x', 'x', 'x', '.', 'x'},
        {'x', ' ', 'x', '.', 'x', '.', 'x', '.', 'x', '.', 'x', '.', 'x', '.', 'x', 'x', 'x', 'x', ' ', 'x'},
        {'x', '.', 'x', '.', 'x', '.', 'x', '.', '.', '.', '.', ' ', 'x', '.', 'x', 'x', 'x', 'x', '.', 'x'},
        {'x', '.', 'x', '.', '.', '.', '.', '.', 'x', 'x', 'x', '.', 'x', '.', 'x', 'x', 'x', 'x', '.', 'x'},
        {'x', ' ', '.', '.', 'x', 'x', 'x', ' ', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'x'},
        {'x', '@', 'x', 'x', 'x', 'x', 'x', '.', 'x', 'x', 'x', 'x', 'x', '.', 'x', 'x', 'x', 'x', ' ', 'x'},
        {'x', '.', '.', '.', '.', '.', 'x', '.', 'x', 'x', 'x', '.', '.', '.', 'x', 'x', 'x', 'x', '.', 'x'},
        {'x', '.', 'x', '.', 'x', '.', 'x', ' ', 'x', 'x', 'x', '.', 'x', '.', '.', '.', '.', '.', '.', 'x'},
        {'x', '.', 'x', '.', 'x', '.', 'x', '.', 'x', 'x', 'x', '.', 'x', '.', 'x', 'x', 'x', 'x', ' ', 'x'},
        {'x', '.', 'x', ' ', 'x', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', ' ', 'x'},
        {'x', ' ', 'x', '.', 'x', 'x', 'x', 'x', 'x', 'x', 'x', '.', 'x', '.', ' ', ' ', ' ', ' ', ' ', 'x'},
        {'x', '.', 'x', '.', '.', '.', 'x', '.', '.', '.', '.', '.', 'x', '.', ' ', ' ', ' ', ' ', ' ', 'x'},
        {'x', ' ', 'x', ' ', 'x', '.', 'x', '.', 'x', 'x', 'x', ' ', 'x', ' ', ' ', ' ', ' ', ' ', ' ', 'x'},
        {'x', '.', 'x', '.', 'x', '.', 'x', '.', 'x', 'x', 'x', '.', 'x', '.', ' ', ' ', ' ', ' ', ' ', 'x'},
        {'x', '.', '.', '.', '.', ' ', '.', '.', '.', ' ', '.', ' ', '.', '.', '.', '.', '.', '.', '.', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}
    };

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            map[i][j] = initialMap[i][j];
        }
    }

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            int xPos = j * 50;
            int yPos = i * 50;

            char symbol = map[i][j];

            if (symbol == 'x')
            {
                Cell* wall = new Cell(xPos, yPos, 50);
                cells.push_back(wall);
            }
            else if (symbol == '.')
            {
                int cellCenterX = xPos + 25;
                int cellCenterY = yPos + 25;
                int pacGumX = cellCenterX - 5;
                int pacGumY = cellCenterY - 5;
                PacGum* pacGum = new PacGum(pacGumX, pacGumY, 10);
                pacGums.push_back(pacGum);
            }
            else if (symbol == '@')
            {
                int cellCenterX = xPos + 25;
                int cellCenterY = yPos + 25;
                int SPRpacGumX = cellCenterX - 10;
                int SPRpacGumY = cellCenterY - 10;

                SuperPacGum* SPR = new SuperPacGum(SPRpacGumX, SPRpacGumY, 20);
                SPRs.push_back(SPR);
            }

        }
    }
}







void Game::updateGame(float elapsedTime) {

    pacman->update(elapsedTime);
    blinky->update(elapsedTime);
    inky->update(elapsedTime);
    pinky->update(elapsedTime);
    clyde->update(elapsedTime);


    sf::Vector2f currentPosition = pacman->Getpos();


    for (int i = 0; i < SPRs.size(); ++i) {
        sf::Vector2f superPacGumPosition = SPRs[i]->getPosition();
        float distanceX = std::abs(currentPosition.x - superPacGumPosition.x - 2.f);
        float distanceY = std::abs(currentPosition.y - superPacGumPosition.y - 2.f);
        
        if (distanceX < 25.f and distanceY < 25.f) {
            for (int j = i + 1; j < SPRs.size(); ++j) {
                SPRs[j - 1] = SPRs[j];

            }
            SPRs.pop_back();
            p += 100;
            sound3.play();
            
            scoreText.setString(std::string("Score: ") + std::to_string(p));
            std::cout << "\r" << "Score: " << p << std::flush;
            break;
        }
    }





    for (int m = 0; m < pacGums.size(); ++m) {
        sf::Vector2f pacGumPosition = pacGums[m]->getPosition();
        float distanceX = std::abs(currentPosition.x - pacGumPosition.x + 3.f);
        float distanceY = std::abs(currentPosition.y - pacGumPosition.y + 3.f);
        
        if (distanceX < 25.f and distanceY < 25.f) {
            for (int n = m + 1; n < pacGums.size(); ++n) {
                pacGums[n - 1] = pacGums[n];

            }
            pacGums.pop_back();
            p = p + 10;
            sound1.play();
            
            scoreText.setString(std::string("Score: ") + std::to_string(p));
            std::cout << "\r" << "Score: " << p << std::flush;
            break;
        }
    }

    if (p == 1790) {
        scoreText.setString(std::string("You Win!"));
    }

    
    for (int i = 0; i < ghosts.size(); ++i) {
        sf::Vector2f ghostPosition = ghosts[i]->getPosition();
        float distanceX = std::abs(currentPosition.x - ghostPosition.x);
        float distanceY = std::abs(currentPosition.y - ghostPosition.y);
        if (distanceX < 5.f and distanceY < 5.f) {

            
            sound2.play();
            q = 1;
            std::cout << q << std::endl;
            break;
        }




    }



}


void Game::render(sf::RenderWindow& window) const {
    window.clear();


    for (const auto& cell : cells)
    {
        cell->render(window);
    }


    for (const auto& pacGum : pacGums) {
        pacGum->render(window);
    }

    for (const auto& SPR : SPRs) {
        SPR->render(window);
    }
    pacman->render(window);
    blinky->render(window);
    inky->render(window);
    pinky->render(window);
    clyde->render(window);
    window.draw(scoreText);
    window.draw(label);




}
	

