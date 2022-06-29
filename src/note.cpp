#include "note.h"
#include <stdio.h>
#include <iostream>

Note::Note(float x_pos, std::string note, int wnf, b2World& world, float RATIO, sf::Texture& texture, SoundManager* soundManager, int nuance)
	:MovingObject(b2Vec2(x_pos,0.0f),b2Vec2(0.0f,-0.5f), 0.5f,0.5f,world, texture)
	,sound(note)
	,whole_note_frac(wnf)
	,nuance(nuance)
	,sound_manager(soundManager)
{}

void Note::changeNuance(int new_nuance) {
	nuance = new_nuance;
}

void Note::decreaseNuance() {
	nuance-=3;
	if (nuance <= 0) {
		Die();
	}
}

void Note::Update() {
	if (dead)
		return;
	float pos_x = GetPosition().x;
	float pos_y = GetPosition().y;
	if (pos_y < -30.0f) {
		Die();
		dead = true;
	}
	if (6 < pos_x && pos_x < 32 && GetBody()->GetContactList()) {
		Die();
		dead = true;
	}
	if (GetVelocity().x == 0 && oldVelocity == 1) {
		oldVelocity = 0;
		sound_manager->Play(sound, nuance);
		decreaseNuance();
	}
	if (abs(GetVelocity().x) == 1 && oldVelocity == 0) {
		oldVelocity = 1;
		sound_manager->Play(sound, nuance);
		decreaseNuance();
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
		}
		else
		{
			context.setStrategy(strategies[2].get());
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