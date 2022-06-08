#include "boss.h"

void Boss::setRectangle(float width, float height) {
	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
	rectangle->setPosition(position);
	rectangle->setOrigin(width / 2, height / 2);
    rectangle->setFillColor(sf::Color::Blue);
    shape = rectangle;
}

void Boss::createBody(b2World& world) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x / worldScale, position.y / worldScale);
    body = world.CreateBody(&bodyDef);

    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(shape->getLocalBounds().width / 2 / worldScale, shape->getLocalBounds().height / 2 / worldScale);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &polygonShape;
    //fixtureDef.density = dynamic;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

void Boss::update() {
    shape->setPosition(body->GetPosition().x * worldScale, body->GetPosition().y * worldScale);
}