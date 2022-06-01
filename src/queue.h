#pragma once
#include "note.h"

class Queue
{
public:
    void init();
    void add_to_queue(Note* note);
    void update();
    int get_head();
    int get_tail();
    int get_max_pending();

private:
    static const int MAX_PENDING = 16;
    int head_;
    int tail_;

    Note* pending_[MAX_PENDING];
};
