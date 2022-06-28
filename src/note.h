#pragma once
#include <string>
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>
#include "movingObject.h"
#include "strategies.h"
#include "soundManager.h"

class Note :public MovingObject {
private:
	std::string sound; // the sound sample played
	int whole_note_frac; //duration of the note, as a fraction of a whole note
	int nuance; // from 1 to 6, 6 being ff, 5:f,4:mf,3:mp,2:p,1:pp, 0 -> the note disappear
	bool dead = false;
	sf::Sprite sprite;
	SoundManager* sound_manager;
	float oldVelocity = 0.0f;
public:
	Note(float x_pos, std::string note, int wnf, b2World& world, float RATIO, sf::Texture& texture, SoundManager* soundManager, int nuance = 18);
	void changeNuance(int newNuance);
	void decreaseNuance();
	void draw_note(sf::RenderTarget& window, const float RATIO, Context& context, std::vector<std::unique_ptr<Strategy>>& strategies);
	void Update();
	void Die();
	bool getDead();
};