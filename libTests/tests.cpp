#include "box2d/box2d.h"
#include <stdio.h>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
<<<<<<< HEAD
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>
#include <fontsub.h>

int const height = 800;
int const width = 600;

=======
#include "boss.h"

#define RATIO 30.0f
#define SCREEN_W 800
#define SCREEN_H 600
>>>>>>> paul
//FICHIER BAC À SABLE POUR TESTER LES LIBRAIRIES




int main()
{
<<<<<<< HEAD

	sf::Clock timer;
	sf::RenderWindow window(sf::VideoMode(height, width), "timer");

	sf::RectangleShape test(sf::Vector2f(100, 100));
	test.setPosition(100, 100);

	while (window.isOpen()) {
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		if (timer.getElapsedTime().asSeconds() > 2) {
			window.draw(test);
		}
		std::cout << std::to_string(timer.getElapsedTime().asSeconds()) << std::endl;

		
		
		window.display();
	}

	return 0;
}

/*b2Vec2 gravity(0.0f, -1.0f);
=======
	b2Vec2 gravity(0.0f, 0.0f);
>>>>>>> paul
	b2World world(gravity);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(4.0f, -4.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(10.0f, 1.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	float boxW = 0.7f;
	float boxH = 2.0f;
	b2BodyDef bodyDef;
	bodyDef.position.Set(1.0f, 2.0f);
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(boxW, boxH);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->SetFixedRotation(true);
	body->CreateFixture(&fixtureDef);

	float obstacleW = 1.0f;
	float obstacleH = 1.0f;
	b2BodyDef triggerDef;
	triggerDef.position.Set(4.0,-2.0f);
	triggerDef.type = b2_staticBody;
	b2Body* trigger = world.CreateBody(&triggerDef);
	b2PolygonShape triggerBox;
	triggerBox.SetAsBox(obstacleW, obstacleH);
	b2FixtureDef triggerFixtureDef;
	triggerFixtureDef.shape = &triggerBox;
	//triggerFixtureDef.isSensor = true;
	trigger->CreateFixture(&triggerFixtureDef);

	
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	b2Vec2 position = body->GetPosition();

	sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "aled");

	sf::SoundBuffer buffer;
	sf::Sound sound;
	if (!buffer.loadFromFile("resources/sound.wav")){
		printf("ERROR");
		return -1;
	}
	sound.setBuffer(buffer);
	sound.setVolume(20);
	sound.setPitch(0.5);

<<<<<<< HEAD
=======
	sf::RectangleShape calib(sf::Vector2f(10,10));
	calib.setPosition(sf::Vector2f(200.0f,200.0f));
	sf::RectangleShape calib2(sf::Vector2f(10,10));
	calib2.setPosition(sf::Vector2f(195.0f,195.0f));
	calib.setFillColor(sf::Color(255, 0, 0, 255));

	
>>>>>>> paul
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					//body->ApplyLinearImpulseToCenter(b2Vec2(10,0),true);
					body->SetLinearVelocity(b2Vec2(1, 0));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
					//body->ApplyLinearImpulseToCenter(b2Vec2(-10, 0),true);
					body->SetLinearVelocity(b2Vec2(-1, 0));
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					//body->ApplyLinearImpulseToCenter(b2Vec2(-10, 0), true);
					body->SetLinearVelocity(b2Vec2(0, 1));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					//body->ApplyLinearImpulseToCenter(b2Vec2(-10, 0), true);
					body->SetLinearVelocity(b2Vec2(0,-1));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					//body->ApplyLinearImpulseToCenter(b2Vec2(0, 20), true);
					body->SetLinearVelocity(b2Vec2(0, 0));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					body->SetLinearVelocity(b2Vec2(0, 0));
					body->SetTransform(b2Vec2(0, 0), 0);
					sound.play();
				}
			}

		}
		sf::Event anykey;
		window.pollEvent(anykey);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			//body->ApplyLinearImpulse(b2Vec2(0, 100), body->GetMassData().center, true);
		}
		// Instruct the world to perform a single step of simulation.
		// It is generally best to keep the time step and iterations fixed.
		world.Step(timeStep, velocityIterations, positionIterations);
		// Now print the position and angle of the body.
		if (body->GetContactList()) {
			if(body->GetContactList()->contact->IsTouching()&& body->GetPosition().y > -200.0f){
				printf("Ayayayay");
			}
		}


		/*if (b2TestOverlap(body->GetFixtureList()->GetAABB(0), trigger->GetFixtureList()->GetAABB(0))) {
			printf("OVERLAPPPP");
		}*/
		bossMain();

		position = body->GetPosition();
		b2Vec2 gpos = groundBody->GetPosition();

		sf::RectangleShape box(sf::Vector2f(boxW*2*RATIO,boxH*2*RATIO));
		box.setPosition(sf::Vector2f(RATIO*(position.x-boxW),SCREEN_H / 2 + RATIO*(-position.y - boxH)));

		sf::RectangleShape ground(sf::Vector2f(10.0f * 2.0f * RATIO, 1.0f * 2.0f * RATIO));
		ground.setPosition(sf::Vector2f(RATIO * (gpos.x - 10.0f),SCREEN_H / 2 + RATIO * (-gpos.y - 1.0f)));

		sf::RectangleShape obstacle(sf::Vector2f(RATIO * 2*obstacleW, RATIO * 2*obstacleH));

		obstacle.setPosition(sf::Vector2f(RATIO * (trigger->GetPosition().x-obstacleW),SCREEN_H/2 +RATIO * (-trigger->GetPosition().y-obstacleH)));
		window.clear();
		window.draw(box);
		window.draw(obstacle);
		window.draw(ground);
		window.draw(calib2);
		window.draw(calib);
		window.display();
<<<<<<< HEAD
	}*/

	/*nlohmann::json note1;
	nlohmann::json note2;
	nlohmann::json note3;

	note1["tune"] = "A";
	note1["beat"] = 2;

	note2["tune"] = "B";
	note2["beat"] = 3;


	note3["tune"] = "A";
	note3["beat"] = 1;


	nlohmann::json mesure1;
	nlohmann::json mesure2;

	mesure1["id"] = 1;
	mesure1["notes"] = {note1, note2};

	mesure2["id"] = 2;
	mesure2["notes"] = { note3 };


	nlohmann::json partition;

	/*partition = {
	  {"label", "test"},
	  {"tempo", 120},
	  {"chiffrage", 4},
	  {"mesures", mesure1, mesure2}
	};
	partition["label"] = "test";
	partition["tempo"] = 120;
	partition["chiffrage"] = 4;
	partition["mesures"] = { mesure1, mesure2 };*/

	//struct partition test_partition;
	//from_json(partition, test_partition); 


	/*std::ifstream i("resources/partition_test.json");
	nlohmann::json partition;
	i >> partition;


	std::string test_json = partition.dump(3);
	std::cout << test_json << std::endl;
	std::string test = "je teste que j'ai bien le label a 'test' : " + partition["label"].get<std::string>();
	std::cout << test << std::endl;*/
=======
	}
	
}
>>>>>>> paul
