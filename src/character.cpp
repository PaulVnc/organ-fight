#include "character.h"

Character::Character(float x_pos, b2Vec2 facing, int initial_health, sf::Texture& texture, b2World& world)
	:MovingObject(b2Vec2(x_pos, -20.0f), b2Vec2(0, 0), 2.0f, 2.0f, world, texture)
	, health(initial_health)
	, facing(facing)
{
	GetBody()->GetFixtureList()[0].SetSensor(true);
}

void Character::SetHealth(int value) {
	health = value;
}

void Character::AddHealth(int amount) {
	health += amount;
}

void Character::Update() {
	if (GetVelocity().y < 0.0f && GetPosition().y < -24.0f) {
		SetVelocity(b2Vec2(0.0f, 0.0f));
	}

	if (GetVelocity().y > 0.0f && GetPosition().y > -18.0f) {
		SetVelocity(b2Vec2(0.0f, 0.0f));
	}
}

void Character::RedirectNearbyObject(b2Body* projectile) {
	projectile->SetLinearVelocity(facing);
}

bool Character::GetCanShoot() {
	return canShoot;
}

void Character::SetCanShoot(bool value) {
	canShoot = value;
}