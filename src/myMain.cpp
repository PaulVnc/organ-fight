#include "myMain.h"
#include "Tunes.h"
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
#include "movingObject.h"
#include "character.h"
#include "keyHandler.cpp"
#include "strategies.h"
#include "soundManager.h"

#define RATIO 30.0f


using namespace nlohmann;

int const height = 800;
int const width = 1200;


int myMain()
 {
	  
	/*On commence par charger les textures utilisées par les sprites et a assignée la texture du background au sprite du background*/
#pragma region Textures
	sf::Texture texture_notes;
	if (!texture_notes.loadFromFile("resources/trans_note.png"))
	{
		std::cout << "texture load failed" << std::endl;
		return -1;

	}

	sf::Texture texture_background;
	if (!texture_background.loadFromFile("resources/background.jpg", sf::IntRect(0,0,width,height)))
	{
		std::cout << "texture load failed" << std::endl;
		return -1;

	}

	sf::Texture texture_player1;
	if (!texture_player1.loadFromFile("resources/player1_transparent.png"))
	{
		std::cout << "texture load failed" << std::endl;
		return -1;

	}

	sf::Texture texture_player2;
	if (!texture_player2.loadFromFile("resources/player2_transparent.png"))
	{
		std::cout << "texture load failed" << std::endl;
		return -1;

	}

	sf::Texture texture_boss;
	if (!texture_boss.loadFromFile("resources/Boss_Transparent.png"))
	{
		std::cout << "texture load failed" << std::endl;
		return -1;

	}

	sf::Sprite sprite_background;
	sprite_background.setTexture(texture_background);
	sprite_background.setColor(sf::Color(255, 255, 255, 220));

#pragma endregion Textures


	/*Parsing du Json de la partition*/
#pragma region parsing_json

	/*On charge le Json depuis les ressources*/
	std::ifstream i("resources/LionKing.json");
	//std::ifstream i("resources/partition_test.json");
	nlohmann::json partition;
	i >> partition;


	/*Print de debug*/
	//std::string test_json = partition.dump(3);
	//std::cout << test_json << std::endl;

	
	/*On récupère toutes les mesures du json avec les fonctions de parsing (cf. jsonfunction.h)*/
	std::vector<mesure> all_mesures = get_mesures(partition);

	/*Pour chacune des mesures on récupère toutes les tunes et on les stocke dans l'ordre dans le vecteur all_tunes*/
	std::vector<Tunes> all_tunes;
	for (const mesure& mes : all_mesures) {
		
		std::vector<Tunes> mesure_notes = get_tunes(mes.json, mes.id, partition["chiffrage"], partition["tempo"]);
		all_tunes.insert(all_tunes.end(), mesure_notes.begin(), mesure_notes.end());

	}


	/*Print de debug*/
	//for (const Tunes& one_note : all_notes) {
		//std::cout << "Note: \n tune:" << one_note.get_tune() << "\n time:" << one_note.get_time() << std::endl;
	//}
#pragma endregion parsing_json


	/*On charge les 7 fichiers audios correspondant aux 7 notes de la gamme de Do Majeur*/
	
#pragma region sound_buffer
	/*
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

	*/
	/*On créée une map associant le nom de la note au son de la note, ça permettra de récupérer le bon son pour chaque tunes* /
	/*
	std::map<std::string, sf::Sound> sounds_map;
	sounds_map["A"] = soundA;
	sounds_map["B"] = soundB;
	sounds_map["C"] = soundC;
	sounds_map["D"] = soundD;
	sounds_map["E"] = soundE;
	sounds_map["F"] = soundF;
	sounds_map["G"] = soundG;
	*/
	SoundManager soundManager;
#pragma endregion sound_buffer



	std::vector<Note> notes;


	b2Vec2 gravity(0.0f, 0.0f);
	b2World world(gravity);

	Character player1(3.5f, b2Vec2(1, 0), 100, texture_player1, world);
	bool p1CanShoot = true;
	bool p1CanGoDown = true;
	bool p1CanGoUp = true;
	Character player2(35.0f, b2Vec2(-1, 0), 100, texture_player2, world);
	bool p2CanShoot = true;
	bool p2CanGoDown = true;
	bool p2CanGoUp = true;

	Boss boss(500, texture_boss, world);


	int index = 0;
	sf::RenderWindow window(sf::VideoMode(width, height), "notes");
	sf::Clock timer;

	Context context;
	auto startStrategy = std::make_unique<BasicStrategy>();
	auto J1losingstrategy = std::make_unique<J1losingStrategy>();
	auto J2losingstrategy = std::make_unique<J2losingStrategy>();
	std::vector<std::unique_ptr<Strategy>> strategies;
	strategies.push_back(std::move(startStrategy));
	strategies.push_back(std::move(J1losingstrategy));
	strategies.push_back(std::move(J2losingstrategy));
	context.setStrategy(strategies[0].get());

#pragma region boucle_while
	while (window.isOpen()) {


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				handleKeyPress(event.key.code, &player1, &player2);
			}
			if (event.type == sf::Event::KeyReleased) {
				handleKeyRelease(event.key.code, &player1, &player2);
			}
		}

		player1.Update();
		player2.Update();

		window.clear(sf::Color::White);
		window.draw(sprite_background);

		/*A chaque tour de boucle on vérifie si le temps écoulé depuis le lancement du jeu est supérieur au temps auquel la prochaine note doit être jouée, si c'est le cas,
		on joue le son du Tunes et on crée l'objet note correspondant, qui va tomber sur l'écran et interagir avec les joueurs.
		On fait donc spawn les notes suivant le rythme de la partition*/
		while (index < all_tunes.size() && timer.getElapsedTime().asSeconds() >= all_tunes[index].get_time()) {
			//sounds_map[all_tunes[index].get_tune()].play();
			soundManager.Play(all_tunes[index].get_tune());
			Note new_note(4.0f + (context.executeStrategy())*RATIO , all_tunes[index].get_tune(), 4, world, RATIO, texture_notes);
			notes.push_back(new_note);
			index++;
		}

		world.Step(1.0f / 60.0f, 6, 2);

		for (int i = 0; i < notes.size(); i++) {
			notes[i].draw_note(window, RATIO, context, strategies);
			if (notes[i].getDead()) {
				notes.erase(notes.begin()+i);
			}
			//std::cout << n.GetPosition().y << std::endl;
		}
		player1.Draw(window, RATIO);
		player2.Draw(window, RATIO);
		boss.Draw(window, RATIO);
		window.display();
	}

    return 0;
}
#pragma endregion boucle_while