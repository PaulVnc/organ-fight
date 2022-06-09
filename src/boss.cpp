#include "box2d/box2d.h"
#include <stdio.h>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "boss.h"

int time_count=0;

Boss::Boss(int initial_health,b2World* world, sf::Texture& texture)
	:MovingObject(b2Vec2(15.0f, -20.0f), b2Vec2(0, 0), 2.0f, 2.0f, world)
	, health(initial_health)
{
	sprite.setTexture(texture);
}

void Boss::changeDirection() {
	int pattern = rand() % 4;
	switch (pattern) {
	case 0:
		SetVelocity(b2Vec2(0.0f, 0.0f));
		break;
	case 1:
		SetVelocity(b2Vec2(0.0f, 0.1f));
		break;
	case 2:
		SetVelocity(b2Vec2(0.0f, 0.0f));
		break;
	case 3:
		SetVelocity(b2Vec2(0.0f, -0.1f));
		break;
	}
}

int Boss::bossMain() {
	time_count = (time_count + rand() % 2) % 1000;
	if (time_count == 0) {
		changeDirection();
	}
	SetVelocity(b2Vec2(0.0f, GetVelocity().y));
	if (GetVelocity().y < 0.0f && GetPosition().y < -24.0f ) {
		SetVelocity(b2Vec2(0.0f, 0.0f));
	}

	if (GetVelocity().y > 0.0f && GetPosition().y > -18.0f) {
		SetVelocity(b2Vec2(0.0f, 0.0f));
	}
	return 0;
}

void Boss::Draw(sf::RenderTarget* window, float RATIO) {
	sf::RectangleShape bossShape(sf::Vector2f(RATIO*2.0f, RATIO*2.0f));
	bossShape.setPosition(sf::Vector2f(RATIO * (GetPosition().x -1.0f), RATIO* (-GetPosition().y-1.0f)));
	bossShape.setFillColor(sf::Color(255, 0, 0, 255));
	sprite.setPosition(sf::Vector2f(RATIO * (GetPosition().x - 1.0f), RATIO * (-GetPosition().y - 1.0f)));
	window->draw(bossShape);
	window->draw(sprite);
}