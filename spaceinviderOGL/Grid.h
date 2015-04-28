#pragma once

#include <string>
#include <SDL.h>

class Grid
{
private:
	SDL_Texture* shot;
	SDL_Texture* enemy;
	SDL_Texture* boom;
	SDL_Rect srcRect;

public:
	char board[27][46];
	int cols, rows;

	Grid();
	Grid(SDL_Texture* sshot, SDL_Texture* eenemy, SDL_Texture* bboom);
	~Grid();
	void drawGrid(std::string *draw);
	void drawGridGL(void(dispTexture)(SDL_Texture* img, SDL_Rect* srcRect, SDL_Rect* destRect));
	void placeNewShoot(int position);
	int updateLook(bool move);
	void placeNewEnemy(int position);
};

