#include "note.h"
#include <stdio.h>
#include <iostream>

Note::Note(float x_pos, std::string note, int wnf, b2World* world, float RATIO, sf::Texture& texture, int nuance)
	:MovingObject(b2Vec2(x_pos,5.0f),b2Vec2(0.0f,-0.5f), 0.5f,0.5f,world, texture)
	,sound(note)
	,whole_note_frac(wnf)
	,nuance(nuance)
{}

void Note::changeNuance(int new_nuance) {
	nuance = new_nuance;
}

void Note::decreaseNuance() {
	nuance--;
}

void Note::Update() {
	if (dead)
		return;
	if (GetPosition().y < -30.0f) {
		Die();
		dead = true;
	}
}

void Note::Die() {
	GetBody()->DestroyFixture(&(GetBody()->GetFixtureList()[0]));
	dead = true;
	return;
}

void Note::draw_note(sf::RenderTarget& window,const float RATIO, Context& context, std::vector<std::unique_ptr<Strategy>>& strategies) {
		Update();
	if (dead) {
		if (GetPosition().x < 10) {
			context.setStrategy(strategies[1].get());
			std::cout << "change to strategie 1" << std::endl;
		}
		else
		{
			context.setStrategy(strategies[2].get());
			std::cout << "change to strategie 2" << std::endl;
		}
		return;
	}


	sprite.setPosition(RATIO * (GetPosition().x - 0.5f), RATIO * (-GetPosition().y - 0.5f));
	if (!dead)
		Draw(window, RATIO);
}

bool Note::getDead() {
	return dead;
}