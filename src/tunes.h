#pragma once
#include <string>

/* Cette classe représente les notes parsées du Json de la partition.
Le champs time: c'est le temps absolu (en secondes) à laquelle la note doit être jouée
	ex: si time = 9.05 alors la note doit être jouée 9.05s après le début de la partition
Le champs tune: c'est une string contenant le nom de la note (en anglais) à jouer
	ex: si tune = B alors la note est un Si
	
Ainsi, l'enchainement de Tunes représente le mélodie écrite textuellement dans le Json de la partition*/

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