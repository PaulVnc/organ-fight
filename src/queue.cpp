#include "queue.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>


void Queue::init() {
	head_ = 0;
	tail_ = 0;
}

void Queue::add_to_queue(Note* note) {
	assert((tail_ + 1) % MAX_PENDING != head_);

	pending_[tail_] = note;
	tail_ = (tail_ + 1) % MAX_PENDING;
}

void Queue::update() {
	if (head_ == tail_) return;

	std::cout << "updated" << std::endl;

	head_ = (head_ + 1) % MAX_PENDING;
}

int Queue::get_head() {
	return head_;
}

int Queue::get_tail() {
	return tail_;
}

int Queue::get_max_pending() {
	return MAX_PENDING;
}