#include "Tunes.h"



Note::Note(float x_pos, std::string note, int wnf, b2World* world, float RATIO, int nuance)
	:MovingObject(b2Vec2(x_pos,0.0f),b2Vec2(0.0f,-0.5f), 0.5f,0.5f,world)
	,sound(note)
	,whole_note_frac(wnf)
	,nuance(nuance)
	,shape(sf::RectangleShape(sf::Vector2f(RATIO*2*0.5f, RATIO*2*0.5f)))
{}

void Note::changeNuance(int new_nuance) {
	nuance = new_nuance;
}


std::string Tunes::get_tune() const{
	return tune;
}

float Tunes::get_time() const{
	return time;
}