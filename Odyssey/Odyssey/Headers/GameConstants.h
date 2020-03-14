#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

//Level dimensions 
const int LEVEL_WIDTH = 640;
const int LEVEL_HEIGHT = 480;

//Tile dimensions
const int TILE_WIDTH = 16;
const int TILE_HEIGHT = 16;
const int TOTAL_TILES = (LEVEL_HEIGHT / TILE_HEIGHT) * (LEVEL_WIDTH / TILE_WIDTH); // 30 x 40
const int TOTAL_GRASS_TILE_SPRITES = 8;
const int TOTAL_WATER_TILE_SPRITES = 8;
const int WATER_TILE_HEIGHT_OFFSET = 128;

//Grass Sprites:
const int TILE_GRASS_0 = 0;
const int TILE_GRASS_1 = 1;
const int TILE_GRASS_2 = 2;
const int TILE_GRASS_3 = 3;
const int TILE_GRASS_4 = 4;
const int TILE_GRASS_5 = 5;
const int TILE_GRASS_6 = 6;
const int TILE_GRASS_7 = 7;

//Water Sprites:
const int TILE_WATER_0 = 0;
const int TILE_WATER_1 = 1;
const int TILE_WATER_2 = 2;
const int TILE_WATER_3 = 3;
const int TILE_WATER_4 = 4;
const int TILE_WATER_5 = 5;
const int TILE_WATER_6 = 6;
const int TILE_WATER_7 = 7;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#endif