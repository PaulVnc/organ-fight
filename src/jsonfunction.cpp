#include <stdio.h>
#include <iostream>
#include <string>
#include "jsonfunction.h"

/*Cette fonction prend en argument le Json de partition, contenant un tableau de toutes les mesures du morceau et les extrait pour les stocker dans un vecteur de mesure qu'elle renvoit.
C'est donc une simple boucle for sur le tableau de mesure du json, pour chaque élément on récupère l'id et le json contenant les notes de la mesure*/

std::vector<mesure> get_mesures(nlohmann::json json) {
	std::vector<mesure> all_mesures;
	for (int i = 0; i < json["mesures"].size(); i++) {
		mesure mesure_i{ json["mesures"][i]["id"], json["mesures"][i]["notes"] };
		all_mesures.push_back(mesure_i);
	}
	return all_mesures;
}

/*Cette focntion prend en argument un json de notes contenues dans une mesure (elle est donc destinées à prendre en argument un json de la forme mesure.json),
ainsi que des données nécessaires au calcul du champ time d'un objet de la classe Tunes (cf. Tunes.h pour plus d'explication sur ce champ).
Il y a 2 cas de figures qui peuvent arriver:
	- il n'y a qu'une note dans la mesure: dans ce cas il suffit de récupérer les champs "tune" et "beat" de cette note dans le json et d'apeller le constructeur de Tunes avec ces arguments
	- il y a plusieurs notes dans la mesure: dans ce cas, le json des notes est un tableau et il faut itérer sur chaque note de ce tableau pour créer les objets Tunes correspondants
		ex: Voir les mesures 1 et 2 du json ressources/partition_test.json pour voir les 2 cas de figure.
La fonction renvoie un vecteur de Tunes corresondant aux notes de la mesures passée en argument*/

std::vector<Tunes> get_tunes(nlohmann::json json, int id_mesure, float chiffrage, float tempo) {
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