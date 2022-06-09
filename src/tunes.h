#pragma once
#include <string>

/* Cette classe repr�sente les notes pars�es du Json de la partition.
Le champs time: c'est le temps absolu (en secondes) � laquelle la note doit �tre jou�e
	ex: si time = 9.05 alors la note doit �tre jou�e 9.05s apr�s le d�but de la partition
Le champs tune: c'est une string contenant le nom de la note (en anglais) � jouer
	ex: si tune = B alors la note est un Si
	
Ainsi, l'enchainement de Tunes repr�sente le m�lodie �crite textuellement dans le Json de la partition*/

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