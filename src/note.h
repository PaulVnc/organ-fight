#pragma once
#include <string>

class Notes {
private:
	float time;
	std::string tune;
public:
	Notes(float time, std::string tune);
	Notes(std::string tune, float beat, int id_mesure, float chiffrage, float tempo);
	std::string get_tune() const;
	float get_time() const;
};