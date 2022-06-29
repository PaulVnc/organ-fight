#pragma once
#include <string>
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>

class MovingObject {
private:
	b2BodyDef bodyDef;
	b2Body* body;
	float h;
	float w;
	sf::Sprite sprite;
public:
	MovingObject(b2Vec2 position, b2Vec2 initial_velocity, float width, float height, b2World& world, sf::Texture& texture);
	void SetVelocity(b2Vec2 vel);
	void SetPosition(b2Vec2 pos);
	b2Body* GetBody();
	b2Vec2 GetPosition();
	b2Vec2 GetVelocity();
	virtual void Draw(sf::RenderTarget& window, float RATIO);
	sf::Sprite getSprite() const;
	virtual ~MovingObject() = default;
};