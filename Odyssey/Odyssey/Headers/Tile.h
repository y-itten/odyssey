#ifndef GAME_TILE_H
#define GAME_TILE_H

#include "LTexture.h"

class Tile
{
	public:
		Tile(int x, int y, int tileType);

		void render();

		int getType();

		SDL_Rect getBox();

	private:
		SDL_Rect mBox;
		int mType;

};

#endif 