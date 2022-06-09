#include "myMain.h"
#include "tunes.h"
#include "queue.h"
#include "jsonfunction.h"
#include "box2d/box2d.h"
#include <stdio.h>
#include <iostream>
#include "nlohmann/json.hpp"
#include "Boss.h"
#include <string>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "note.h"
#include "Movingobject.h"
#include "boss.h"
#include "character.h"
#include "keyHandler.cpp"

#define RATIO 30.0f

using namespace nlohmann;

int const height = 800;
int const width = 1200;


int myMain()
 {
	  // Inserer ici le code a appeler par myMain()
	

	std::ifstream i("resources/LionKing.json");
	nlohmann::json partition;
	i >> partition;


	std::string test_json = partition.dump(3);
	std::cout << test_json << std::endl;
	
	std::vector<mesure> all_mesures = get_mesures(partition);
	std::vector<Tunes> all_notes;
	for (const mesure& mes : all_mesures) {
		
		std::vector<Tunes> mesure_notes = get_notes(mes.json, mes.id, partition["chiffrage"], partition["tempo"]);
		all_notes.insert(all_notes.end(), mesure_notes.begin(), mesure_notes.end());

	}
	for (const Tunes& one_note : all_notes) {
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




	
	sf::VertexArray lines(sf::Lines, 2);

	lines[0].position = sf::Vector2f(0, 200);
	lines[0].color = sf::Color::Red;
	lines[1].position = sf::Vector2f(width, 200);
	lines[1].color = sf::Color::Red;

	sf::VertexArray lines2(sf::Lines, 2);

	lines2[0].position = sf::Vector2f(0, 400);
	lines2[0].color = sf::Color::Red;
	lines2[1].position = sf::Vector2f(width, 400);
	lines2[1].color = sf::Color::Red;

	sf::VertexArray lines3(sf::Lines, 2);

	lines3[0].position = sf::Vector2f(0, 600);
	lines3[0].color = sf::Color::Red;
	lines3[1].position = sf::Vector2f(width, 600);
	lines3[1].color = sf::Color::Red;

	std::vector<Note> notes;

	sf::Sprite playerSprite;

	b2Vec2 gravity(0.0f, 0.0f);
	b2World world(gravity);

	Character player1(1.0f, b2Vec2(1, 0), 100, playerSprite, &world);
	bool p1CanShoot = true;
	Character player2(31.0f, b2Vec2(-1, 0), 100, playerSprite, &world);
	bool p2CanShoot = true;

	Boss boss(500, &world);


	int index = 0;
	sf::RenderWindow window(sf::VideoMode(width, height), "notes");
	sf::Clock timer;

	while (window.isOpen()) {


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				sf::Keyboard::Key k = event.key.code;
				switch (k) {
				case sf::Keyboard::Key::S:
					if (!p1CanShoot)
						break;
					p1CanShoot = false;
					if (player1.GetBody()->GetContactList()) {
						b2Body* projectile = player1.GetBody()->GetContactList()->contact->GetFixtureB()->GetBody();
						player1.RedirectNearbyObject(projectile);
					}
					break;
				case sf::Keyboard::Key::Z:
					player1.SetVelocity(b2Vec2(0.0f, 0.5f));
					break;
				case sf::Keyboard::Key::W:
					player1.SetVelocity(b2Vec2(0.0f, -0.5f));
					break;
				case sf::Keyboard::Key::H:
					if (!p2CanShoot)
						break;
					p2CanShoot = false;
					if (player2.GetBody()->GetContactList()) {
						b2Body* projectile = player2.GetBody()->GetContactList()->contact->GetFixtureB()->GetBody();
						player2.RedirectNearbyObject(projectile);
					}
					break;
				case sf::Keyboard::Key::U:
					if (player2.GetPosition().y < -18.0f)
						player2.SetVelocity(b2Vec2(0.0f, 0.5f));
					break;
				case sf::Keyboard::Key::N:
					if (player2.GetPosition().y > -24.0f)
						player2.SetVelocity(b2Vec2(0.0f,-0.5f));
					break;
				default:
					break;
				}
			}
			if (event.type == sf::Event::KeyReleased) {
				sf::Keyboard::Key k = event.key.code;
				switch (k) {
				case sf::Keyboard::Key::S:
					p1CanShoot = true;
					break;
				case sf::Keyboard::Key::Z:
					player1.SetVelocity(b2Vec2(0.0f, 0.0f));
					break;
				case sf::Keyboard::Key::W:
					player1.SetVelocity(b2Vec2(0.0f, 0.0f));
					break;
				case sf::Keyboard::Key::H:
					p2CanShoot = true;
					break;
				case sf::Keyboard::Key::U:
					player2.SetVelocity(b2Vec2(0.0f, 0.0f));
					break;
				case sf::Keyboard::Key::N:
					player2.SetVelocity(b2Vec2(0.0f, 0.0f));
					break;
				default:
					break;
				}
			}
		}

		boss.bossMain();

		window.clear(sf::Color::White);
		while (index < all_notes.size() && timer.getElapsedTime().asSeconds() >= all_notes[index].get_time()) {
			sounds_map[all_notes[index].get_tune()].play();
			index++;
			Note new_note(2.0f + (index%2)*30.0f , "C", 4, &world, RATIO);
			notes.push_back(new_note);
		}

		world.Step(1.0f / 60.0f, 6, 2);

		for (Note n : notes) {
			n.draw(&window,RATIO);
		}
		player1.Draw(&window, RATIO);
		player2.Draw(&window, RATIO);
		boss.Draw(&window, RATIO);
		window.draw(lines);
		window.draw(lines2);
		window.draw(lines3);
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