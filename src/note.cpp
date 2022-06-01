#include "note.h"

Note::Note(float time, std::string tune) :
	time(time),
	tune(tune) {}

Note::Note(std::string tune, float beat, int id_mesure, float chiffrage, float tempo) :
	tune(tune) 
{
	time = (chiffrage/tempo)*(60*(id_mesure - 1) + beat);
}


std::string Note::get_tune() {
	return tune;
}

float Note::get_time() {
	return time;
}