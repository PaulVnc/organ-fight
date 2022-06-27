#include "box2d/box2d.h"
#include <stdio.h>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Boss.h"

int time_count = 0;

Boss::Boss(int x_pos, sf::Texture& texture, b2World& world)
	:MovingObject(b2Vec2(x_pos, -20.0f), b2Vec2(0, 0), 2.0f, 1.0f, world, texture)
{
	GetBody()->GetFixtureList()[0].SetSensor(true);
}

void Boss::changeDirection() {
	GetBody()->SetLinearVelocity(-1 * GetBody()->GetLinearVelocity());
}

int Boss::bossMain() {
	time_count = (time_count + rand() % 2) % 5000;
	if (time_count == 0) {
		printf("boss changing direction\n");
		changeDirection();
	}

	return 0;
}