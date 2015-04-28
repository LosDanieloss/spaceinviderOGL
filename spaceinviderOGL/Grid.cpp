#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	rows = 26;
	cols = 45;
	for (int i = 0; i <= rows; i++)
	for (int j = 0; j <= cols; j++)
		board[i][j] = ' ';
	board[0][10] = 'x';
	srcRect = { 0, 0, 25, 25};
}

Grid::Grid(SDL_Texture* sshot, SDL_Texture* eenemy, SDL_Texture* bboom){
	rows = 26;
	cols = 45;
	for (int i = 0; i <= rows; i++)
	for (int j = 0; j <= cols; j++)
		board[i][j] = ' ';
	board[0][10] = 'x';
	shot = sshot;
	enemy = eenemy;
	boom = bboom;
	srcRect = { 0, 0, 25, 25};
}

Grid::~Grid()
{
	SDL_DestroyTexture(shot);
	SDL_DestroyTexture(enemy);
	SDL_DestroyTexture(boom);
}

void Grid::drawGrid(std::string *draw){
	for (int i = 0; i <= rows; i++){
		if (i != 0)
			draw->append(sizeof(char), '\n');
		for (int j = 0; j <= cols; j++)
			draw->append(sizeof(char), board[i][j]);
	}
	draw->append(sizeof(char), '\n');
}

void Grid::placeNewShoot(int position){
	board[rows][position] = '|';
}

int Grid::updateLook(bool move){

	if (move)
	for (int i = rows; i >= 0; i--){
		for (int j = cols; j >= 0; j--){
			if (board[i][j] == 'x' && i < rows){
				board[i][j] = ' ';
				board[i + 1][j] = 'x';
			}
			else if (board[i][j] == 'x' && i == rows){
				board[i][j] = ' ';
				return -1;
			}
		}
	}

	for (int i = 0; i <= rows; i++){
		for (int j = 0; j <= cols; j++){
			if (board[i][j] == '*'){
				board[i][j] = ' ';
			}
			if (board[i][j] == '|' && i > 0){
				board[i][j] = ' ';
				if (board[i - 1][j] == 'x'){
					board[i - 1][j] = '*';
					return 5;
				}

				else
					board[i - 1][j] = '|';
			}
			if (board[i][j] == '|' && i == 0)
				board[i][j] = ' ';
		}
	}
	return 0;
}

void Grid::placeNewEnemy(int position){
	board[0][position] = 'x';
}

void Grid::drawGridGL(void(dispTexture)(SDL_Texture* img, SDL_Rect* srcRect, SDL_Rect* destRect)){
	SDL_Texture* tmp_texture = NULL;
	SDL_Rect destRect = { 0, 0, 25, 25 };
	for (int i = 0; i <= rows; i++)
	for (int j = 0; j <= cols; j++){
		if (board[i][j] == 'x'){
			tmp_texture = enemy;
		}
		else if (board[i][j] == '|'){
			tmp_texture = shot;
		}
		else if (board[i][j] == '*'){
			tmp_texture = boom;
		}
		else
			tmp_texture = NULL;
		destRect = {j*25,i*25, 25, 25 }; // ???
		if (tmp_texture != NULL)
		dispTexture(tmp_texture, &srcRect, &destRect);
	}

	tmp_texture = NULL;
	SDL_DestroyTexture(tmp_texture);
}