#pragma once
#include "nlohmann/json.hpp"
#include "note.h"

struct mesure {
	int id;
	nlohmann::json json;
};

std::vector<mesure> get_mesures(nlohmann::json json);
std::vector<Notes> get_notes(nlohmann::json json, int id_mesure, float chiffrage, float tempo);