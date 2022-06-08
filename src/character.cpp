#include "character.h"

Character::Character(float x_pos, b2Vec2 facing, int initial_health, sf::Sprite sprite, b2World* world)
	:MovingObject(b2Vec2(x_pos, 5.0f), b2Vec2(0, 0), 0.5f, 1.2f, world)
	, health(initial_health)
	, facing(facing)
{}

void Character::SetHealth(int value) {
	health = value;
}

void Character::DeltaHealth(int amount) {
	health += amount;
}

void Character::ChangeSprite(sf::Sprite new_sprite) {
	sprite = new_sprite;
}