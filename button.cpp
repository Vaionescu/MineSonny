#include "button.h"
Button::Button() {
	x = y = w = h = 0;
	strcpy(txt, "");
}
Button::Button(int x, int y, int w, int h, const char* txt) {
	x = y = w = h = 0;
	strcpy(this->txt, "");
	if (x > 0) {
		this->x = x;
	}
	if (y > 0) {
		this->y = y;
	}
	if (w > 0) {
		this->w = w;
	}
	if (h > 0) {
		this->h = h;
	}
	if (strlen(txt) < 256) {
		strcpy(this->txt, txt);
	}
}
void Button::setX(int x) {
	if (x > 0) {
		this->x = x;
	}
}
void Button::setY(int y) {
	if (y > 0) {
		this->y = y;
	}
}
void Button::setW(int w) {
	if (w > 0) {
		this->w = w;
	}
}
void Button::setH(int h) {
	if (h > 0) {
		this->h = h;
	}
}
void Button::setText(const char* txt) {
	if (strlen(txt) < 256) {
		strcpy(this->txt, txt);
	}
}
int Button::getX() {
	return x;
}
int Button::getY() {
	return y;
}
int Button::getW() {
	return w;
}
int Button::getH() {
	return h;
}
const char* Button::getText() {
	return (const char*)txt;
}
void Button::render(SDL_Renderer *renderer, TTF_Font *font) {
	SDL_Rect *t = new SDL_Rect;
	SDL_Color *c = new SDL_Color;
	c->r = c->g = c->b = 0;
	c->a = 255;
	t->x = x;
	t->y = y;
	t->w = w;
	t->h = h;
	SDL_Surface *txt_s = TTF_RenderText_Solid(font, this->txt, *c);
	SDL_Texture *txt_t = SDL_CreateTextureFromSurface(renderer, txt_s);
	SDL_SetRenderDrawColor(renderer, 179, 179, 179, 255);
	SDL_RenderFillRect(renderer, t);
	SDL_RenderCopy(renderer, txt_t, NULL, t);
	delete t;
	delete c;
	delete txt_s;
	free(txt_t);
}
