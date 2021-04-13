#include"ModuloRender.h"
#include"Aplication.h"
moduloRender::moduloRender(aplication *APP):Module(APP) {

}
moduloRender::~moduloRender() {

}
bool moduloRender::Init() {
	int prop = SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(app->Window->window, -1, prop);
	SDL_RenderSetLogicalSize(renderer, WINDOWWIDTH, WINDOWHIGH);
	return true;
}
States moduloRender::Preupdate() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	return States::Continue;
}
States moduloRender::Postupdate() {
	SDL_RenderPresent(renderer);
	return States::Continue;
}
bool moduloRender::CleanUp() {
	SDL_DestroyRenderer(renderer);
	return true;
}
void moduloRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* texturesize) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = texturesize->w;
	rect.h = texturesize->h;
	SDL_RenderCopy(renderer, texture, texturesize, &rect);
}
