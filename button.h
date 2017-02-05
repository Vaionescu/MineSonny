#pragma once
#include <cstring>
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;
class Button {
private:
	int x, y, w, h;
	char txt[256];
public:
	Button();
	Button(int x, int y, int w, int h, const char* txt);
	void setX(int x);
	void setY(int y);
	void setW(int w);
	void setH(int h);
	void setText(const char* txt);
	int getX();
	int getY();
	int getW();
	int getH();
	const char* getText();
	void render(SDL_Renderer *renderer, TTF_Font *font);
};
