#ifndef MODULOTEXTURAS_H_
#define MODULOTEXTURAS_H_
#include"Module.h"

#include"External/SDL/include/SDL.h"
#include"External/SDL_image/include/SDL_image.h"
#define MAXTEXTURES 50
class ModuleTextures :public Module {
public:
	ModuleTextures(aplication* APP);
	~ModuleTextures();
	bool Init()override;
	SDL_Texture* Load(const char* archivo);
	void Unload(SDL_Texture* textura);
	bool CleanUp()override;
	//
	bool Start()override;
	//
	SDL_Texture* textures[MAXTEXTURES];
};
#endif
