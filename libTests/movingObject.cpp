#include "MovingObject.h"

MovingObject::MovingObject(b2Vec2 position,b2Vec2 initial_velocity,float width, float height, b2World* world)
	:w(width),h(height)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x,position.y);
	bodyDef.fixedRotation = true;
	b2PolygonShape noteBox;
	noteBox.SetAsBox(w/2,h/2);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &noteBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;
	body = world->CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
	body->SetLinearVelocity(initial_velocity);
}

b2Body* MovingObject::GetBody() {
	return body;
}

b2Vec2 MovingObject::GetPosition() {
	auto pos = body->GetPosition();
	return pos;
}
b2Vec2 MovingObject::GetVelocity() {
	auto vel = body->GetLinearVelocity();
	return vel;
}

void MovingObject::SetPosition(b2Vec2 pos) {
	body->SetTransform(pos, 0);
}

void MovingObject::SetVelocity(b2Vec2 vel) {
	body->SetLinearVelocity(vel);
}
