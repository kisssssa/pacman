#pragma once
#include <SFML/Graphics.hpp>

enum struct Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};


class Entity
{
protected:
	int xPos;
	int yPos;
	int size;


public:
	virtual sf::FloatRect getBounds() = 0;
	//virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	sf::Vector2f getPosition() const { return sf::Vector2f(xPos, yPos); }

};

class StaticEntity : public Entity {
protected:
	sf::FloatRect bounds;
	sf::RectangleShape shape;
public:
	sf::FloatRect getBounds() override {
		return shape.getGlobalBounds();
	}

};

class PacGum : public StaticEntity {


public:
	PacGum(int x, int y, int radius) {
		xPos = x;
		yPos = y;
		size = radius;
	}

	void render(sf::RenderWindow& window) {
		sf::CircleShape shape(size / 2); // Создаем круг с радиусом равным половине размера
		shape.setFillColor(sf::Color(255, 183, 174));
		shape.setPosition(sf::Vector2f(xPos, yPos));
		shape.setOrigin(size / 2, size / 2); // Устанавливаем центр круга в его середину
		window.draw(shape);
	}

};

class SuperPacGum : public StaticEntity
{
public:

	SuperPacGum(int x, int y, int s) {
		xPos = x;
		yPos = y;
		size = s;
	}
	void render(sf::RenderWindow& window) {
		sf::CircleShape circle(size / 2.f); // Создаем круглую форму
		circle.setFillColor(sf::Color(255, 183, 174));
		circle.setPosition(sf::Vector2f(xPos, yPos));
		circle.setOrigin(size / 2.f, size / 2.f); // Устанавливаем центр круга
		window.draw(circle);
	}
};


class MovingEntity : public Entity {
protected:
	int speed;
	sf::Vector2i speedVec;
	Direction direction;
	sf::CircleShape shape;
	sf::Sprite sprite;





public:
	void unpdatePosition() {

	}
	void render(sf::RenderWindow& window) {
		window.draw(shape);
		window.draw(sprite);
	}
	sf::FloatRect getBounds() {
		return shape.getGlobalBounds();
	}
	//setters, getters, etc. 
}
