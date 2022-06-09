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