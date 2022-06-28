#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
#include <string>

class SoundStrategy {
public:
	virtual int execute() = 0;
	virtual ~SoundStrategy() = default;
};

class SoundContext {
private:
	SoundStrategy* strategy;
public:
	void SetSoundStrategy(SoundStrategy* new_strategy);
	int executeStrategy();
};

class SoundManager {
public:
	SoundManager();
	void Play(std::string note,int nuance);
	SoundContext GetSoundContext();
private:
	SoundContext s_context;
	std::map<std::string, sf::SoundBuffer> sounds_map;
	sf::Sound player;
};

