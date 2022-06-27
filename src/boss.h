#pragma once
#include "box2d/box2d.h"
#include "movingObject.h"

class Boss: public MovingObject {
private:
	int health = 500;
	bool reflectMode = false;
	bool dead = false;
public:
	//void setReflectMode(bool state);
	//void hit(int amount);
	Boss(int x_pos, sf::Texture& texture, b2World* world);
	void changeDirection();
	void bossMain();
	void Draw(sf::RenderTarget* window, const float RATIO) override;
};