#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <SDL.h>
#include "GameConstants.h"
#include "LTexture.h"

SDL_Renderer* gRenderer = NULL;
SDL_Rect gTileClips[TOTAL_GRASS_TILE_SPRITES];
LTexture gTileTexture;



#endif