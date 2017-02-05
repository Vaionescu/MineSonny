#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdio>
#include <cstdlib>
#include "button.h"
using namespace std;
TTF_Font *font = NULL;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;
Button quit;
int WinMain() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	font = TTF_OpenFont("OpenSans.ttf", 24);
	window = SDL_CreateWindow("MineSonny",
							  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							  804, 480,
							  SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_GetWindowSurface(window);
	atexit(SDL_Quit);
	atexit(TTF_Quit);
	bool apprun = true;
	int menu = 0;
	bool shown = false;
	while (apprun) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit(0);
			} else if (event.type == SDL_MOUSEBUTTONUP) {
				if (menu == 0 && shown == false) {
					quit.setX(595);
					quit.setY(400);
					quit.setW(200);
					quit.setH(70);
					quit.setText("Quit");
					quit.render(renderer, font);
					shown = true;
					printf("Render main menu\n");
				}
			} else if (event.type == SDL_WINDOWEVENT) {
				if (menu == 0) {
					quit.render(renderer, font);
					printf("Render main menu\n");
				}
				SDL_UpdateWindowSurface(window);
				printf("Update window surface\n");
			}
		}
		SDL_RenderPresent(renderer);
	}
	return 0;
}
