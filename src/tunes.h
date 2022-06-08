#pragma once
#include <string>

class Tunes {
private:
	float time;
	std::string tune;

public:
	Tunes(float time, std::string tune);
	Tunes(std::string tune, float beat, int id_mesure, float chiffrage, float tempo);
	std::string get_tune() const;
	float get_time() const;
};