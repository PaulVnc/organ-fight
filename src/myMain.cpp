#include "myMain.h"
#include "note.h"
#include "box2d/box2d.h"
#include <stdio.h>
#include <iostream>
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>

using namespace nlohmann;


int myMain()
{
	  // Inserer ici le code a appeler par myMain()

	std::ifstream i("resources/partition_test.json");
	nlohmann::json partition;
	i >> partition;


	std::string test_json = partition.dump(3);
	std::cout << test_json << std::endl;
	
	auto note_test = std::make_unique<Note>("D", 2.0, 1, 4.0, 100.0);
	std::cout << "La note est: " << note_test->get_tune() << " et est jouée au temps " << std::to_string(note_test->get_time()) << std::endl;

    return 0;
}