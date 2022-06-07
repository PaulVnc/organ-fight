#include "note.h"

Tunes::Tunes(float time, std::string tune) :
	time(time),
	tune(tune) {}

Tunes::Tunes(std::string tune, float beat, int id_mesure, float chiffrage, float tempo) :
	tune(tune) 
{
	time = (60/tempo)*(chiffrage*(id_mesure - 1) + beat);
}


std::string Tunes::get_tune() const{
	return tune;
}

float Tunes::get_time() const{
	return time;
}