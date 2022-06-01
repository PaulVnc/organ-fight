#include "note.h"

Note::Note(float x_pos, std::string note, int wnf, b2World* world,const float RATIO, int nuance)
	:sound(note)
	, whole_note_frac(wnf)
	, nuance(nuance)
	, shape(sf::RectangleShape(sf::Vector2f(RATIO*2*0.5f, RATIO*2*0.5f)))
{
	noteBD.type = b2_dynamicBody;
	noteBD.position.Set(x_pos, 0.0f);
	noteBD.fixedRotation = true;
	b2PolygonShape noteBox;
	noteBox.SetAsBox(0.5f, 0.5f);
	b2FixtureDef noteFixtureDef;
	noteFixtureDef.shape = &noteBox;
	noteFixtureDef.density = 1.0f;
	noteFixtureDef.friction = 0.3f;
	noteBody = world->CreateBody(&noteBD);
	noteBody->CreateFixture(&noteFixtureDef);
	noteBody->SetLinearVelocity(b2Vec2(0, -1.0f));
}

void Note::changeNuance(int new_nuance) {
	nuance = new_nuance;
}

void Note::changeVelocity(float h_vel, float v_vel) {
	noteBody->SetLinearVelocity(b2Vec2(h_vel, v_vel));
}

void Note::decreaseNuance() {
	nuance--;
}

b2Body* Note::getBody() {
	return noteBody;
}

b2Vec2 Note::pos() {
	auto pos = noteBody->GetPosition();
	return pos;
}

void Note::draw(sf::RenderTarget* window,const float RATIO) {
	shape.setPosition(RATIO*(pos().x-0.5f), RATIO*(-pos().y-0.5f));
	window->draw(shape);
}