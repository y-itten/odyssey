#include "Headers/GameConstants.h"
#include "Headers/GameController.h"
#include "Headers/Tile.h"
#include "Tile.cpp"
#include "LTexture.cpp"
#include "Headers/LTexture.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>

bool init();

bool loadMedia(Tile* tiles[]);

void close(Tile* tiles[]);

bool setTiles(Tile* tiles[]);

SDL_Window* gWindow = NULL;

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia(Tile* tiles[])
{
	bool success = true;

	if (!gTileTexture.loadFromFile("textures/world/tiles/tiles.png"))
	{
		printf("Failed to load tile set texture!\n");
		success = false;
	}

	if (!setTiles(tiles))
	{
		printf("Failed to load tile set!\n");
		success = false;
	}

	return success;
}

void close(Tile* tiles[])
{

	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		if (tiles[i] != NULL)
		{
			delete tiles[i];
			tiles[i] = NULL;
		}
	}

	gTileTexture.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}



bool setTiles(Tile* tiles[])
{
	bool tilesLoaded = true;

	int x = 0, y = 0;

	std::ifstream map("Map/first.map");

	if (map.fail())
	{
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	}
	else
	{

		for (int i = 0; i < TOTAL_TILES; ++i)
		{

			int tileType = -1;


			map >> tileType;

			if (map.fail())
			{

				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}


			if ((tileType >= 0) && (tileType < TOTAL_GRASS_TILE_SPRITES))
			{
				tiles[i] = new Tile(x, y, tileType);
			}

			else
			{

				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}

			x += TILE_WIDTH;

			if (x >= LEVEL_WIDTH)
			{
				x = 0;

				y += TILE_HEIGHT;
			}
		}

		if (tilesLoaded)
		{
			gTileClips[TILE_GRASS_0].x = 0;
			gTileClips[TILE_GRASS_0].y = 0;
			gTileClips[TILE_GRASS_0].w = TILE_WIDTH;
			gTileClips[TILE_GRASS_0].h = TILE_HEIGHT;

			gTileClips[TILE_GRASS_1].x = 0;
			gTileClips[TILE_GRASS_1].y = 16;
			gTileClips[TILE_GRASS_1].w = TILE_WIDTH;
			gTileClips[TILE_GRASS_1].h = TILE_HEIGHT;

			gTileClips[TILE_GRASS_2].x = 0;
			gTileClips[TILE_GRASS_2].y = 32;
			gTileClips[TILE_GRASS_2].w = TILE_WIDTH;
			gTileClips[TILE_GRASS_2].h = TILE_HEIGHT;

			gTileClips[TILE_GRASS_3].x = 0;
			gTileClips[TILE_GRASS_3].y = 48;
			gTileClips[TILE_GRASS_3].w = TILE_WIDTH;
			gTileClips[TILE_GRASS_3].h = TILE_HEIGHT;

			gTileClips[TILE_GRASS_4].x = 0;
			gTileClips[TILE_GRASS_4].y = 64;
			gTileClips[TILE_GRASS_4].w = TILE_WIDTH;
			gTileClips[TILE_GRASS_4].h = TILE_HEIGHT;

			gTileClips[TILE_GRASS_5].x = 0;
			gTileClips[TILE_GRASS_5].y = 80;
			gTileClips[TILE_GRASS_5].w = TILE_WIDTH;
			gTileClips[TILE_GRASS_5].h = TILE_HEIGHT;

			gTileClips[TILE_GRASS_6].x = 0;
			gTileClips[TILE_GRASS_6].y = 96;
			gTileClips[TILE_GRASS_6].w = TILE_WIDTH;
			gTileClips[TILE_GRASS_6].h = TILE_HEIGHT;

			gTileClips[TILE_GRASS_7].x = 0;
			gTileClips[TILE_GRASS_7].y = 112;
			gTileClips[TILE_GRASS_7].w = TILE_WIDTH;
			gTileClips[TILE_GRASS_7].h = TILE_HEIGHT;

		}
	}

	map.close();

	return tilesLoaded;
}




int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Tile* tileSet[TOTAL_TILES];

		if (!loadMedia(tileSet))
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;

			SDL_Event e;

			while (!quit)
			{

				while (SDL_PollEvent(&e) != 0)
				{

					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

				}

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				for (int i = 0; i < TOTAL_TILES; ++i)
				{
					tileSet[i]->render();
				}

				SDL_RenderPresent(gRenderer);
			}
		}

		close(tileSet);
	}

	return 0;
}