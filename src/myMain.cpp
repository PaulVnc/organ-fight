#include "myMain.h"
#include "note.h"
#include "queue.h"
#include "box2d/box2d.h"
#include <stdio.h>
#include <iostream>
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>
#include <memory>

using namespace nlohmann;


int myMain()
{
	  // Inserer ici le code a appeler par myMain()

	std::ifstream i("resources/partition_test.json");
	nlohmann::json partition;
	i >> partition;


	std::string test_json = partition.dump(3);
	std::cout << test_json << std::endl;
	
	Note note = Note("D", 2.0, 1, 4.0, 100.0);
	Note* note_test = &note;
	std::cout << "La note est: " << note_test->get_tune() << " et est jouée au temps " << std::to_string(note_test->get_time()) << std::endl;

	Queue queue;
	queue.init();
	std::cout << "head = " << queue.get_head() << std::endl;
	std::cout << "tail = " << queue.get_tail() << std::endl;
	for (int i = 0; i < queue.get_max_pending() - 4; i++) {
		queue.add_to_queue(note_test);
		std::cout << "head = " << queue.get_head() << std::endl;
		std::cout << "tail = " << queue.get_tail() << std::endl;
	}
	for (int i = 0; i < queue.get_max_pending() - 4; i++) {
		queue.update();
		std::cout << "head = " << queue.get_head() << std::endl;
		std::cout << "tail = " << queue.get_tail() << std::endl;
	}
	for (int i = 0; i < queue.get_max_pending() - 4; i++) {
		queue.add_to_queue(note_test);
		std::cout << "head = " << queue.get_head() << std::endl;
		std::cout << "tail = " << queue.get_tail() << std::endl;
	}
	for (int i = 0; i < queue.get_max_pending() - 4; i++) {
		queue.update();
		std::cout << "head = " << queue.get_head() << std::endl;
		std::cout << "tail = " << queue.get_tail() << std::endl;
	}



    return 0;
}