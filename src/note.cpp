#include "note.h"

Notes::Notes(float time, std::string tune) :
	time(time),
	tune(tune) {}

Notes::Notes(std::string tune, float beat, int id_mesure, float chiffrage, float tempo) :
	tune(tune) 
{
	time = (60/tempo)*(chiffrage*(id_mesure - 1) + beat);
}


std::string Notes::get_tune() const{
	return tune;
}

float Notes::get_time() const{
	return time;
}