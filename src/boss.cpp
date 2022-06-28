#include "box2d/box2d.h"
#include <stdio.h>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Boss.h"

int time_count = 0;

Boss::Boss(int health, sf::Texture& texture, b2World& world)
	:MovingObject(b2Vec2(17.0f, -20.0f), b2Vec2(0, 0), 2.0f, 2.0f, world, texture)
	,health(health)
{
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

void Boss::bossMain() {
	if (dead)
		return;
	time_count = (time_count + rand() %2) % 2000;
	if (time_count == 0) {
		changeDirection();
	}
	SetVelocity(b2Vec2(0.0f, GetVelocity().y));
	if (GetVelocity().y < 0.0f && GetPosition().y < -24.0f) {
		SetVelocity(b2Vec2(0.0f, 0.0f));
	}

	if (GetVelocity().y > 0.0f && GetPosition().y > -18.0f) {
		SetVelocity(b2Vec2(0.0f, 0.0f));
	}
	if (GetBody()->GetContactList()) {
		printf("Aiyeuh\n");
		health -= 20;
	}
	if (health <= 0) {
		dead = true;
		GetBody()->DestroyFixture(&(GetBody()->GetFixtureList()[0]));
	}

	return;
}

void Boss::Draw(sf::RenderTarget& window,const float RATIO) {
	if (dead)
		return;
	bossMain();
	//sprite.setPosition(RATIO * (GetPosition().x - w), RATIO * (-GetPosition().y - 0.5f));
	//window->draw(shape);
	if (!dead)
		MovingObject::Draw(window, RATIO);
}