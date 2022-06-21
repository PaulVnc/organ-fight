#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>


class Boss
{
private:
	sf::Vector2f position;
	sf::Shape* shape;
	b2Body* body;
	const int worldScale = 30;
public:
	Boss(float x, float y) : position(x, y) {};
	void setRectangle(float width, float height);
	void createBody(b2World& world);
	void update();
	sf::Shape& getShape() { return *shape; };
};