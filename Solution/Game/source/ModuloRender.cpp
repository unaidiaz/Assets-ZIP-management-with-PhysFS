#include"ModuloRender.h"
#include"Aplication.h"
moduleRender::moduleRender(aplication *APP):Module(APP) {

}
moduleRender::~moduleRender() {

}
bool moduleRender::Init() {
	int prop = SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(app->Window->window, -1, prop);
	SDL_RenderSetLogicalSize(renderer, WINDOWWIDTH, WINDOWHIGH);
	return true;
}
States moduleRender::Preupdate() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	return States::Continue;
}
States moduleRender::Postupdate() {
	SDL_RenderPresent(renderer);
	return States::Continue;
}
bool moduleRender::CleanUp() {
	SDL_DestroyRenderer(renderer);
	return true;
}
void moduleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* texturesize) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = texturesize->w;
	rect.h = texturesize->h;
	SDL_RenderCopy(renderer, texture, texturesize, &rect);
}
