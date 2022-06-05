#pragma once
#include "box2d/box2d.h"

class Boss {
private:
	int health = 500;
	bool reflectMode = false;
	b2Body body;
public:
	//void setReflectMode(bool state);
	//void hit(int amount);
	void changeDirection();
	int bossMain();
};
