#include "note.h"

Note::Note(float x_pos, std::string note, int wnf, b2World* world, float RATIO, sf::Texture& texture, int nuance)
	:MovingObject(b2Vec2(x_pos,5.0f),b2Vec2(0.0f,-0.5f), 0.5f,0.5f,world)
	,sound(note)
	,whole_note_frac(wnf)
	,nuance(nuance)
	,shape(sf::RectangleShape(sf::Vector2f(RATIO*2*0.5f, RATIO*2*0.5f)))
{
	sprite.setTexture(texture);
	
}

void Note::changeNuance(int new_nuance) {
	nuance = new_nuance;
}

void Note::decreaseNuance() {
	nuance--;
}

void Note::Update() {
	if (dead)
		return;
	if (GetVelocity() == b2Vec2(0.0f, 0.0f)){
		dead = true;
		Die();
	}
}

void Note::Die() {
	GetBody()->DestroyFixture(&(GetBody()->GetFixtureList()[0]));
	dead = true;
	return;
}

void Note::draw(sf::RenderTarget* window,const float RATIO) {
	if (dead)
		return;
	Update();
	shape.setPosition(RATIO*(GetPosition().x-0.5f), RATIO*(-GetPosition().y-0.5f));
	shape.setFillColor(sf::Color(0, 0, 0, 255));
	sprite.setPosition(RATIO * (GetPosition().x - 0.5f), RATIO * (-GetPosition().y - 0.5f));
	//window->draw(shape);
	if(!dead)
		window->draw(sprite);
}