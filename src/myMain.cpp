#include "myMain.h"
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
	std::string test = "je teste que j'ai bien le label a 'test' : " + partition["label"].get<std::string>();
	std::cout << test << std::endl;

    return 0;
}