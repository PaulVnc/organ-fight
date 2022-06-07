#include "queue.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>


void Queue::init() {
	head_ = 0;
	tail_ = 0;
}

void Queue::add_to_queue(Tunes* note) {
	assert((tail_ + 1) % MAX_PENDING != head_);

	pending_[tail_] = note;
	tail_ = (tail_ + 1) % MAX_PENDING;
}

void Queue::update(sf::Clock timer, sf::RectangleShape to_display[]) {
	if (head_ == tail_) return;

	if (timer.getElapsedTime().asSeconds() >= pending_[head_]->get_time()) {
		sf::RectangleShape shape(sf::Vector2f(timer.getElapsedTime().asSeconds()*100, timer.getElapsedTime().asSeconds() * 100));
		shape.setPosition(timer.getElapsedTime().asSeconds(), timer.getElapsedTime().asSeconds() * 100);
		if (timer.getElapsedTime().asSeconds() < 1) {
			to_display[0] = shape;
		}
		else {
			to_display[1] = shape;
		}

		std::cout << "drwed" << std::endl;
		head_ = (head_ + 1) % MAX_PENDING;
		return;
	}

	return;

	
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