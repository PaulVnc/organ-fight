#include "queue.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>

/*
CETTE CLASSE N'EST PAS UTILISEE

Cette classe a été créée dans l'optique d'implémenter le game programming pattern Event Queue, mais après réflexion c'était sortir un bazooka pour tuer une mouche
dans le contexte de ce projet, on a donc changer de méthode

(mais supprimer les fichiers ça affole le Cmake alors j'ai peur et je laisse les fichiers mais ils servent plus à rien)
*/


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