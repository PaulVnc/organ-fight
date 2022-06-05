#include "myMain.h"
#include "note.h"
#include "queue.h"
#include "jsonfunction.h"
#include "box2d/box2d.h"
#include <stdio.h>
#include <iostream>
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

using namespace nlohmann;

int const height = 800;
int const width = 600;


int myMain()
{
	  // Inserer ici le code a appeler par myMain()
	

	std::ifstream i("resources/partition_test.json");
	nlohmann::json partition;
	i >> partition;


	std::string test_json = partition.dump(3);
	std::cout << test_json << std::endl;
	
	std::vector<mesure> all_mesures = get_mesures(partition);
	std::vector<Notes> all_notes;
	for (const mesure& mes : all_mesures) {
		
		std::vector<Notes> mesure_notes = get_notes(mes.json, mes.id, partition["chiffrage"], partition["tempo"]);
		all_notes.insert(all_notes.end(), mesure_notes.begin(), mesure_notes.end());

	}
	for (const Notes& one_note : all_notes) {
		std::cout << "Note: \n tune:" << one_note.get_tune() << "\n time:" << one_note.get_time() << std::endl;
	}

	sf::SoundBuffer buffer;
	sf::Sound soundA;
	if (!buffer.loadFromFile("resources/A.wav")) {
		printf("ERROR");
		return -1;
	}
	soundA.setBuffer(buffer);
	soundA.setVolume(20);

	sf::SoundBuffer bufferB;
	sf::Sound soundB;
	if (!bufferB.loadFromFile("resources/B.wav")) {
		printf("ERROR");
		return -1;
	}
	soundB.setBuffer(bufferB);
	soundB.setVolume(20);

	sf::SoundBuffer bufferC;
	sf::Sound soundC;
	if (!bufferC.loadFromFile("resources/C.wav")) {
		printf("ERROR");
		return -1;
	}
	soundC.setBuffer(bufferC);
	soundC.setVolume(20);


	sf::SoundBuffer bufferD;
	sf::Sound soundD;
	if (!bufferD.loadFromFile("resources/D.wav")) {
		printf("ERROR");
		return -1;
	}
	soundD.setBuffer(bufferD);
	soundD.setVolume(20);

	sf::SoundBuffer bufferE;
	sf::Sound soundE;
	if (!bufferE.loadFromFile("resources/E.wav")) {
		printf("ERROR");
		return -1;
	}
	soundE.setBuffer(bufferE);
	soundE.setVolume(20);

	sf::SoundBuffer bufferF;
	sf::Sound soundF;
	if (!bufferF.loadFromFile("resources/F.wav")) {
		printf("ERROR");
		return -1;
	}
	soundF.setBuffer(bufferF);
	soundF.setVolume(20);

	sf::SoundBuffer bufferG;
	sf::Sound soundG;
	if (!bufferG.loadFromFile("resources/G.wav")) {
		printf("ERROR");
		return -1;
	}
	soundG.setBuffer(bufferG);
	soundG.setVolume(20);

	std::map<std::string, sf::Sound> sounds_map;
	sounds_map["A"] = soundA;
	sounds_map["B"] = soundB;
	sounds_map["C"] = soundC;
	sounds_map["D"] = soundD;
	sounds_map["E"] = soundE;
	sounds_map["F"] = soundF;
	sounds_map["G"] = soundG;

	int index = 0;
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
		while (index < all_notes.size() && timer.getElapsedTime().asSeconds() >= all_notes[index].get_time()) {
			std::cout << all_notes[index].get_tune() << std::endl;
			sounds_map[all_notes[index].get_tune()].play();
			index++;
		}



		window.display();
	}

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