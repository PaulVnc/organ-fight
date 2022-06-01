#include "myMain.h"
<<<<<<< HEAD
#include "note.h"
#include "queue.h"
#include "box2d/box2d.h"
#include <stdio.h>
#include <iostream>
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace nlohmann;

int const height = 800;
int const width = 600;

=======
>>>>>>> paul

int myMain()
{
	  // Inserer ici le code a appeler par myMain()
<<<<<<< HEAD
	

	std::ifstream i("resources/partition_test.json");
	nlohmann::json partition;
	i >> partition;


	std::string test_json = partition.dump(3);
	std::cout << test_json << std::endl;
	nlohmann::json mesure = partition["mesures"][0];
	
	std::string test_mesure = mesure.dump(3);
	std::cout << mesure << std::endl;
	


=======
>>>>>>> paul

    return 0;
}

/*Note note = Note("D", 2.0, 1, 4.0, 100.0);
	Note* note_test = &note;
	std::cout << "La note est: " << note_test->get_tune() << " et est jouée au temps " << std::to_string(note_test->get_time()) << std::endl;

	Note note2 = Note("C", 4.0, 2, 4.0, 100.0);
	Note* note_test2 = &note2;
	std::cout << "La note est: " << note_test2->get_tune() << " et est jouée au temps " << std::to_string(note_test2->get_time()) << std::endl;

	Queue queue;
	queue.init();
	queue.add_to_queue(note_test);
	queue.add_to_queue(note_test2);


	sf::RectangleShape to_display[2];


	sf::RenderWindow window(sf::VideoMode(height, width), "notes");
	sf::Clock timer;

	while (window.isOpen()) {


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		queue.update(timer, to_display);
		for (int i = 0; i < 2; i++) {
			window.draw(to_display[i]);
		}



		window.display();
	}*/