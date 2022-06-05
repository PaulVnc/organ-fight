#pragma once
#include <string>
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>

class Note {
private:
	std::string sound; // the sound sample played
	int whole_note_frac; //duration of the note, as a fraction of a whole note
	int nuance; // from 1 to 6, 6 being ff, 5:f,4:mf,3:mp,2:p,1:pp, 0 -> the note disappear
	b2BodyDef noteBD;
	b2Body* noteBody;
	sf::RectangleShape shape;
public:
	explicit Note(float x_pos, std::string note, int wnf, b2World* world,const float RATIO, int nuance = 6);
	b2Body* getBody();
	void init(b2World* world);
	void changeNuance(int newNuance);
	void decreaseNuance();
	void changeVelocity(float h_vel, float v_vel);
	void draw(sf::RenderTarget* window,const float RATIO);
	b2Vec2 pos();
};