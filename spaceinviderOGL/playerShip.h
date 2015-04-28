#pragma once

#include <string>
#include <SDL.h>

class playerShip
{
private:
	SDL_Texture* outlook;
	SDL_Rect playerRect;

public:

	char outfit;
	int position;
	int health;

	playerShip();
	playerShip(SDL_Texture* ooutlook);
	~playerShip();
	void drawShip(std::string* draw);
	void drawShipGL(int y ,void(dispTexture)(SDL_Texture* img, SDL_Rect* srcRect, SDL_Rect* destRect));
	void toTheLeft();
	void toTheRight();
	int shoot();
};

