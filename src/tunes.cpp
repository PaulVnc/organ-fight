#include "tunes.h"

/*Constructeur classique*/
Tunes::Tunes(float time, std::string tune) :
    time(time),
    tune(tune) {}

/*Constructeur prenant le champs tune, le beat de la note dans la mesure (lu dans le json de la partition) ainsi que le numéro (id) de la mesure dans laquelle se trouve la note représenté par cet objet tunes, le chiffrage du morceau et le tempo du morceau
Ces informations permettent de calculer le temps au bout duquel il faut que la note soit jouée selon un simple produit en croix*/
Tunes::Tunes(std::string tune, float beat, int id_mesure, float chiffrage, float tempo) :
    tune(tune)
{
    time = (60 / tempo) * (chiffrage * (id_mesure - 1) + beat);
}




std::string Tunes::get_tune() const {
    return tune;
}

float Tunes::get_time() const {
    return time;
}