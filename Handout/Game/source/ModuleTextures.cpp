#include"ModuleTextures.h"
#include"Aplication.h"
ModuleTextures::ModuleTextures(aplication* APP) :Module(APP) {
	for (int a = 0; a < MAXTEXTURES; a++) {
		textures[a] = nullptr;
	}
}
ModuleTextures::~ModuleTextures() {

}
bool ModuleTextures::Init() {
	bool result = true;
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		result = false;
	}
	return result;
}
bool ModuleTextures::Start() {
	return true;
}

SDL_Texture* ModuleTextures::Load(const char* archivo) {
	SDL_Surface* surface;
	surface = IMG_Load_RW(app->Assets->Load(archivo),1);
	SDL_Texture* texture;
	texture = SDL_CreateTextureFromSurface(app->render->renderer, surface);
	for (int a = 0; a < MAXTEXTURES; a++) {
		if (textures[a] == nullptr) {
			textures[a] = texture;
			break;
		}
	}
	app->Assets->DeleteBuffer();
	return texture;
}
void ModuleTextures::Unload(SDL_Texture* textura) {
	for (int a = 0; a < MAXTEXTURES; a++) {
		if (textures[a] == textura) {
			SDL_DestroyTexture(textura);
			textures[a] = nullptr;
			break;
		}
	}
}
bool ModuleTextures::CleanUp() {
	bool resultado = true;
	for (int a = 0; a < MAXTEXTURES; a++) {
		if (textures[a] != nullptr) {
			SDL_DestroyTexture(textures[a]);
			textures[a] = nullptr;
		}
	}
	IMG_Quit();
	return resultado;
}
