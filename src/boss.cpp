#include "box2d/box2d.h"
#include <stdio.h>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "boss.h"

int time_count=0;

void Boss::changeDirection() {
	body.SetLinearVelocity(-1 * body.GetLinearVelocity());
}

int Boss::bossMain() {
	time_count = (time_count + rand() % 2) % 5000;
	if (time_count == 0) {
		printf("boss changing direction\n");
		changeDirection();
	}
	
	return 0;
}