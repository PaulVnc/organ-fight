#pragma once
#include "SFML/Graphics.hpp"
#include "movingObject.h"

class Character :public MovingObject {
private:
	int health;
	sf::Texture sprite;
	b2Vec2 facing;
public:
	Character(float x_pos,b2Vec2 facing, int initial_health, sf::Sprite sprite, b2World* world);
	void SetHealth(int value);
	void AddHealth(int amount);
	void ChangeSprite(sf::Texture new_sprite);
	void Draw(sf::RenderTarget* window, float RATIO);
	void RedirectNearbyObject(b2Body* projectile);
	void Update();
};