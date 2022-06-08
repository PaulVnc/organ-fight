#pragma once
#include "tunes.h"
#include "SFML/Graphics.hpp"

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
