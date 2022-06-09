#pragma once
#include <string>
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>
#include "movingObject.h"

class Note :public MovingObject {
private:
	std::string sound; // the sound sample played
	int whole_note_frac; //duration of the note, as a fraction of a whole note
	int nuance; // from 1 to 6, 6 being ff, 5:f,4:mf,3:mp,2:p,1:pp, 0 -> the note disappear
public:
	Note(float x_pos, std::string note, int wnf, b2World* world, float RATIO, sf::Texture& texture, int nuance = 6);
	void changeNuance(int newNuance);
	void decreaseNuance();
	void draw(sf::RenderTarget* window, const float RATIO);
	void Update();
	void Die();
};