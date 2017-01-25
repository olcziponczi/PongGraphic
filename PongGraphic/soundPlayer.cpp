#include "stdafx.h"
#include "soundPlayer.h"


soundPlayer::soundPlayer(){

	this->fartBuffer.loadFromFile("pong2.wav");
	this->fart.setBuffer(fartBuffer);

	this->musicBuffer.loadFromFile("musicloop.wav");
	this->music.setBuffer(musicBuffer);
	this->music.setLoop(true);
}

void soundPlayer::playFart() {

	this->fart.play();
}

void soundPlayer::playMusic() {

	this->music.play();
}