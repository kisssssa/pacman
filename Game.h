#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pacman.h"
#include "Entity.h"
#include "Ghost.h"
#include "Cell.h"

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;

class Game
{
	
	int width;
	int height;
	std::vector<SuperPacGum*> SPRs;
	std::vector<PacGum*> pacGums;
	std::vector<Ghost*> ghosts;
	std::vector<Cell*> cells;
	Pacman* pacman;
	Blinky* blinky;
	Clyde* clyde;
	Inky* inky;
	Pinky* pinky;
	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	sf::SoundBuffer buffer3;
	sf::Sound sound;
	sf::Sound sound1;
	sf::Sound sound2;
	sf::Sound sound3;
	sf::Font font;
	sf::Text scoreText;
	sf::Text label;
	bool isPaused;
	char map[MAP_HEIGHT][MAP_WIDTH];
	int p;
	int q;

public:

	Game();
	std::vector<Entity> getEntities();
	std::vector<Cell> getCells();
	
	void createMaze();
	Pacman getPacman();
	void handleInput(sf::RenderWindow& window);
	
	void text();
	void updateGame(float elapsedTime); 
	void render(sf::RenderWindow& window) const;
	~Game() = default;
};

