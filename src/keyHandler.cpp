#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>
#include "character.h"

static void handleKeyPress(sf::Keyboard::Key k, Character* p1, Character* p2) {
	switch (k) {
	case sf::Keyboard::Key::S:
		if (!p1->GetCanShoot())
			break;
		p1->SetCanShoot(false);
		if (p1->GetBody()->GetContactList()) {
			b2Body* projectile = p1->GetBody()->GetContactList()->contact->GetFixtureB()->GetBody();
			p1->RedirectNearbyObject(projectile);
		}
		break;
	case sf::Keyboard::Key::Z:
		p1->SetVelocity(b2Vec2(0, 0.5f));
		break;
	case sf::Keyboard::Key::W:
		p1->SetVelocity(b2Vec2(0, -0.5f));
		break;
	case sf::Keyboard::Key::H:
		if (!p2->GetCanShoot())
			break;
		p2->SetCanShoot(false);
		if (p2->GetBody()->GetContactList()) {
			b2Body* projectile = p2->GetBody()->GetContactList()->contact->GetFixtureB()->GetBody();
			p2->RedirectNearbyObject(projectile);
		}
		break;
	case sf::Keyboard::Key::U:
		p2->SetVelocity(b2Vec2(0, 0.5f));
		break;
	case sf::Keyboard::Key::N:
		p2->SetVelocity(b2Vec2(0, -0.5f));
		break;
	default:
		break;
	}
}

static void handleKeyRelease(sf::Keyboard::Key k, Character* p1, Character* p2){
	switch (k) {
	case sf::Keyboard::Key::S:
		p1->SetCanShoot(true);
		break;
	case sf::Keyboard::Key::Z:
		p1->SetVelocity(b2Vec2(0.0f, 0.0f));
		break;
	case sf::Keyboard::Key::W:
		p1->SetVelocity(b2Vec2(0.0f, 0.0f));
		break;
	case sf::Keyboard::Key::H:
		p2->SetCanShoot(true);
		break;
	case sf::Keyboard::Key::U:
		p2->SetVelocity(b2Vec2(0.0f, 0.0f));
		break;
	case sf::Keyboard::Key::N:
		p2->SetVelocity(b2Vec2(0.0f, 0.0f));
		break;
	default:
		break;
	}
}