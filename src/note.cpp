#include "note.h"

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
	if (GetVelocity().x == 0 && GetPosition().x > 4.0f && GetPosition().x < 24.0f) {
		Die();
		dead = true;
	}
}

void Note::Die() {
	GetBody()->DestroyFixture(&(GetBody()->GetFixtureList()[0]));
	dead = true;
	return;
}

void Note::draw_note(sf::RenderTarget* window,const float RATIO) {
	if (dead)
		return;
	Update();
	sprite.setPosition(RATIO * (GetPosition().x - 0.5f), RATIO * (-GetPosition().y - 0.5f));
	//window->draw(shape);
	if (!dead)
		Draw(window, RATIO);
}