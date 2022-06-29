#include "soundManager.h"
#include <SFML/System/Clock.hpp>

SoundManager::SoundManager() {
	sf::SoundBuffer bufferA;
	if (!bufferA.loadFromFile("resources/A.wav")) {
		printf("ERROR");
	}
	sf::SoundBuffer bufferB;
	if (!bufferB.loadFromFile("resources/B.wav")) {
		printf("ERROR");
	}
	sf::SoundBuffer bufferC;
	if (!bufferC.loadFromFile("resources/C.wav")) {
		printf("ERROR");
	}
	sf::SoundBuffer bufferD;
	if (!bufferD.loadFromFile("resources/D.wav")) {
		printf("ERROR");
	}
	sf::SoundBuffer bufferE;
	if (!bufferE.loadFromFile("resources/E.wav")) {
		printf("ERROR");
	}
	sf::SoundBuffer bufferF;
	if (!bufferF.loadFromFile("resources/F.wav")) {
		printf("ERROR");
	}
	sf::SoundBuffer bufferG;
	if (!bufferG.loadFromFile("resources/G.wav")) {
		printf("ERROR");
	}

	sounds_map["A"] = bufferA;
	sounds_map["B"] = bufferB;
	sounds_map["C"] = bufferC;
	sounds_map["D"] = bufferD;
	sounds_map["E"] = bufferE;
	sounds_map["F"] = bufferF;
	sounds_map["G"] = bufferG;

	player.setVolume(10);
}

void SoundManager::Play(std::string note, int nuance) {
	player.setBuffer(sounds_map[note]);
	player.setVolume(nuance);
	if (playMode == 0) {
		player.stop();
		player.setLoop(false);
		player.play();
	}
	else if (playMode == 1) {
		player.stop();
		player.play();
		sf::Clock tmp_clock;
		while(tmp_clock.getElapsedTime().asSeconds() < 1){
}
		printf("play twice!\n");

		player.play();
	}
	else if (playMode == 2) {
		player.setLoop(true);
		player.play();
	}
	playMode = (playMode + 1) % 3;
	//s_context.executeSoundStrategy(player);
}

sf::Sound SoundManager::GetSoundPlayer() {
	return player;
}

SoundContext* SoundManager::GetSoundContext() {
	return &s_context;
}

void SoundContext::SetSoundStrategy(SoundStrategy* new_sound_strategy) {
	s_strategy = new_sound_strategy;
}

void PlayTwice::execute(sf::Sound player) {
	player.play();
	player.play();
}

void PlayUntilNext::execute(sf::Sound player) {
	player.setLoop(true);
	player.play();
}

void SoundContext::executeSoundStrategy(sf::Sound player) {
	s_strategy->execute(player);
}
