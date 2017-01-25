#pragma once
#include <SFML/Audio.hpp>
class soundPlayer
{
public:
	void playFart();
	void playMusic();
	soundPlayer();
private:
	sf::SoundBuffer fartBuffer;
	sf::SoundBuffer musicBuffer;
	sf::Sound fart;
	sf::Sound music;

};