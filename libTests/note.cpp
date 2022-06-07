#include "note.h"
#include "movingObject.h"

Note::Note(float x_pos, std::string note, int wnf, b2World* world, float RATIO, int nuance)
	:MovingObject(b2Vec2(x_pos,0.0f),b2Vec2(0.0f,-1.0f), 0.5f,0.5f,world)
	,sound(note)
	,whole_note_frac(wnf)
	,nuance(nuance)
	,shape(sf::RectangleShape(sf::Vector2f(RATIO*2*0.5f, RATIO*2*0.5f)))
{}

void Note::changeNuance(int new_nuance) {
	nuance = new_nuance;
}

void Note::decreaseNuance() {
	nuance--;
}

void Note::draw(sf::RenderTarget* window,const float RATIO) {
	shape.setPosition(RATIO*(GetPosition().x-0.5f), RATIO*(-GetPosition().y-0.5f));
	window->draw(shape);
}