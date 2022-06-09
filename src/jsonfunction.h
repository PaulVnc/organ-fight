#pragma once
#include "nlohmann/json.hpp"
#include "tunes.h"

/*Ce fichier d�fini les fonctions qui parsent le Json de partition ainsi que la struct mesure:
Cette structure contient 2 champs
- l'id de la mesure, qui d�signe son "ordre" dans la partition
	ex: la mesure 1 est jou�e en premier etc.
- un json repr�sentant les diff�rentes notes contenues dans cette mesure*/

struct mesure {
	int id;
	nlohmann::json json;
};

std::vector<mesure> get_mesures(nlohmann::json json);
std::vector<Tunes> get_tunes(nlohmann::json json, int id_mesure, float chiffrage, float tempo);