#include "playerShip.h"
#include <iostream>

playerShip::playerShip()
{
	outfit = 'A';
	position = 22;
	health = 5;
	outlook = NULL;
	playerRect = { 0, 0, 25, 25 };
}

playerShip::playerShip(SDL_Texture* ooutlook){
	outfit = 'A';
	position = 22;
	health = 5;
	outlook = ooutlook;
	playerRect = { 0, 0, 25, 25 };
}

playerShip::~playerShip()
{
	SDL_DestroyTexture(outlook);
}

void playerShip::drawShip(std::string *draw){
	char c = ' ';
	for (int i = 0; i < position; i++)
		draw->append(sizeof(char), c);
	draw->append(sizeof(char), outfit);
	draw->append(sizeof(char), '\n');
}

void playerShip::toTheLeft(){
	if (position > 0)
		position--;
}

void playerShip::toTheRight(){
	if (position < 45)
		position++;
}

int playerShip::shoot(){
	return position;
}

void playerShip::drawShipGL(int y, void(dispTexture)(SDL_Texture* img, SDL_Rect* srcRect, SDL_Rect* destRect)){
	SDL_Rect destRect = { position*25, y*25 , 25, 25};
	dispTexture(outlook, &playerRect, &destRect);
}