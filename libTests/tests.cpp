#include "box2d/box2d.h"
#include <stdio.h>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>


//FICHIER BAC À SABLE POUR TESTER LES LIBRAIRIES

int main()
{
	b2Vec2 gravity(0.0f, -1.0f);
	b2World world(gravity);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -400.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(500.0f, 5.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);


	b2BodyDef bodyDef;
	bodyDef.position.Set(0.0f, 4.0f);
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);


	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	b2Vec2 position = body->GetPosition();

	sf::RenderWindow window(sf::VideoMode(800, 600), "yay");

	sf::SoundBuffer buffer;
	sf::Sound sound;
	if (!buffer.loadFromFile("resources/sound.wav")){
		printf("ERROR");
		return -1;
	}
	sound.setBuffer(buffer);
	sound.setVolume(20);
	sound.setPitch(0.5);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					printf("keypressed\n");
					body->ApplyLinearImpulseToCenter(b2Vec2(10,0),true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
					printf("keypressed\n");
					body->ApplyLinearImpulseToCenter(b2Vec2(-10, 0),true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					body->ApplyLinearImpulseToCenter(b2Vec2(0, 20), true);
					sound.play();
				}
			}
			
		}
		sf::Event anykey;
		window.pollEvent(anykey);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			printf("keypressed\n");
			//body->ApplyLinearImpulse(b2Vec2(0, 100), body->GetMassData().center, true);
		}
		// Instruct the world to perform a single step of simulation.
		// It is generally best to keep the time step and iterations fixed.
		world.Step(timeStep, velocityIterations, positionIterations);
		// Now print the position and angle of the body.
		position = body->GetPosition();

		sf::RectangleShape box(sf::Vector2f(40, 40));
		box.setPosition(sf::Vector2f(position.x, -position.y));
		window.clear();
		window.draw(box);
		window.display();
	}
}