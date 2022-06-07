#include <stdio.h>
#include <iostream>
#include <string>
#include "jsonfunction.h"

std::vector<mesure> get_mesures(nlohmann::json json) {
	std::vector<mesure> all_mesures;
	for (int i = 0; i < json["mesures"].size(); i++) {
		mesure mesure_i{ json["mesures"][i]["id"], json["mesures"][i]["notes"] };
		all_mesures.push_back(mesure_i);
	}
	return all_mesures;
}

std::vector<Tunes> get_notes(nlohmann::json json, int id_mesure, float chiffrage, float tempo) {
	std::vector<Tunes> all_notes;
	if (json.is_array()) {
		for (int i = 0; i < json.size(); i++) {
			Tunes note = Tunes(json[i]["tune"], json[i]["beat"], id_mesure, chiffrage, tempo);
			all_notes.push_back(note);
		}
	}
	else {
		Tunes note = Tunes(json["tune"], json["beat"], id_mesure, chiffrage, tempo);
		all_notes.push_back(note);
	}
	return all_notes;
}