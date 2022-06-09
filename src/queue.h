#pragma once
#include "tunes.h"
#include "SFML/Graphics.hpp"

/*
CETTE CLASSE N'EST PAS UTILISEE

Cette classe a été créée dans l'optique d'implémenter le game programming pattern Event Queue, mais après réflexion c'était sortir un bazooka pour tuer une mouche
dans le contexte de ce projet, on a donc changer de méthode

(mais supprimer les fichiers ça affole le Cmake alors j'ai peur et je laisse les fichiers mais ils servent plus à rien)
*/

class Queue
{
public:
    void init();
    void add_to_queue(Tunes* note);
    void update(sf::Clock timer, sf::RectangleShape to_display[]);
    int get_head();
    int get_tail();
    int get_max_pending();

private:
    static const int MAX_PENDING = 16;
    int head_;
    int tail_;

    Tunes* pending_[MAX_PENDING];
};
