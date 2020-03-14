#include "Headers/LTexture.h"
#include "Headers/GameConstants.h"
#include "Headers/GameController.h"
#include <SDL_image.h>

	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;

	LTexture::LTexture() {
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
	LTexture::~LTexture() {
		free();
	}

	bool LTexture::loadFromFile(std::string path) {
		free();

		SDL_Texture* newTexture = NULL;

		SDL_Surface* loadSurface = IMG_Load(path.c_str());
		if (loadSurface == NULL) {
			printf("Couldn't Load Texture from File! %s Error: %s\n", path.c_str(), IMG_GetError());
		}
		else {
			SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, 0, 0xFF, 0xFF));

			newTexture = SDL_CreateTextureFromSurface(gRenderer, loadSurface);
			if (newTexture == NULL) {
				printf("Unable to create Texture! %s Error: %s\n", path.c_str(), SDL_GetError());
			}
			else {
				mWidth = loadSurface->w;
				mHeight = loadSurface->h;
			}

			SDL_FreeSurface(loadSurface);
		}
		mTexture = newTexture;
		return mTexture != NULL;
	}

	void LTexture::free() {
		if (mTexture != NULL) {
			SDL_DestroyTexture(mTexture);
			mTexture = NULL;
			mWidth = 0;
			mHeight = 0;
		}
	}

	void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
		SDL_Rect renderQuad = { x,y, mWidth, mHeight };

		if (clip != NULL) {
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}
		SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
	}

	int LTexture::getWidth() {
		return mWidth;
	}

	int LTexture::getHeight() {
		return mHeight;
	}