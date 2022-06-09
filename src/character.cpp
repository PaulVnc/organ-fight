#include "character.h"

Character::Character(float x_pos, b2Vec2 facing, int initial_health, sf::Sprite sprite, b2World* world)
	:MovingObject(b2Vec2(x_pos, -10.0f), b2Vec2(0, 0), 2.0f, 1.0f, world)
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

void Character::ChangeSprite(sf::Texture new_sprite) {
	sprite.swap(new_sprite);
}

void Character::Update() {
	if (GetVelocity().y < 0.0f && GetPosition().y < -24.0f) {
		SetVelocity(b2Vec2(0.0f, 0.0f));
	}

	if (GetVelocity().y > 0.0f && GetPosition().y > -18.0f) {
		SetVelocity(b2Vec2(0.0f, 0.0f));
	}
}

void Character::Draw(sf::RenderTarget* window, float RATIO) {
	sf::RectangleShape rectangle(sf::Vector2f(RATIO*2*1.0f, RATIO*2*1.0f));
	rectangle.setPosition(RATIO * (GetPosition().x - 0.5f), RATIO * (-GetPosition().y - 0.5f));
	rectangle.setFillColor(sf::Color(0, 0, 0, 255));
	window->draw(rectangle);
}

void Character::RedirectNearbyObject(b2Body* projectile) {
	projectile->SetLinearVelocity(facing);
}