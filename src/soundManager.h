#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
#include <string>
#include <vector>

class SoundStrategy {
public:
	virtual void execute(sf::Sound player);
	virtual ~SoundStrategy() = default;
};

class SoundContext {
private:
	SoundStrategy* s_strategy;
public:
	void SetSoundStrategy(SoundStrategy* new_strategy);
	void executeSoundStrategy(sf::Sound player);
};

class SoundManager {
public:
	SoundManager();
	void Play(std::string note,int nuance);
	SoundContext* GetSoundContext();
	sf::Sound GetSoundPlayer();
private:
	SoundContext s_context;
	std::map<std::string, sf::SoundBuffer> sounds_map;
	sf::Sound player;
	int playMode = 0;
};

class PlayTwice: public SoundStrategy {
	void execute(sf::Sound player) override;
};

class PlayUntilNext : public SoundStrategy {
	void execute(sf::Sound player) override;
};