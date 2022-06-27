#pragma once
#include "SFML/Graphics.hpp"
#include "movingObject.h"

class Character :public MovingObject {
private:
	int health;
	b2Vec2 facing;
	bool canShoot = true;
public:
	Character(float x_pos,b2Vec2 facing, int initial_health, sf::Texture& texture, b2World* world);
	void SetHealth(int value);
	void AddHealth(int amount);
	void RedirectNearbyObject(b2Body* projectile);
	void Update();
	bool GetCanShoot();
	void SetCanShoot(bool value);
};