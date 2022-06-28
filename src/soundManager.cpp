#include "soundManager.h"

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

void SoundManager::Play(std::string note,int nuance) {
	player.setBuffer(sounds_map[note]);
	player.setVolume(nuance);
	player.play();
}

SoundContext SoundManager::GetSoundContext() {
	return s_context;
}