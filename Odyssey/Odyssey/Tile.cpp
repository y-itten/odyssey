#include "Headers/Tile.h"
#include "Headers/GameController.h"
#include "Headers/LTexture.h"
#include <SDL.h>
#include <SDL_image.h>


Tile::Tile(int x, int y, int tileType){
	mBox = SDL_Rect();

	mBox.x = x;
	mBox.y = y;

	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	mType = tileType;

}

void Tile::render() {
	gTileTexture.render(mBox.x, mBox.y, &gTileClips[mType]);
}

int Tile::getType() {
	return mType;
}

SDL_Rect Tile::getBox() {
	return mBox;
}