#pragma once
#include "box2d/box2d.h"
#include "movingObject.h"
#include "SFML/Graphics.hpp"

class Boss:public MovingObject {
private:
	int health;
	bool reflectMode = false;
	sf::Sprite sprite;
public:
	//void setReflectMode(bool state);
	//void hit(int amount);
	Boss(int iniitial_health, b2World* world, sf::Texture& texture);
	void changeDirection();
	int bossMain();
	void Draw(sf::RenderTarget* window, float RATIO);
};
