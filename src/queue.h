#pragma once
#include "note.h"

class Queue
{
public:
    static void init()
    {
        head_ = 0;
        tail_ = 0;
    }

private:
    static const int MAX_PENDING = 16;
    static int head_;
    static int tail_;

    static Note pending_[MAX_PENDING];
};
