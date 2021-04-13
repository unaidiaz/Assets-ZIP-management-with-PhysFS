#ifndef MODULORENDER_H_
#define MODULORENDER_H_
#include"Globals.h"
#include"Module.h"
#include"External/SDL/include/SDL.h"


class moduleRender:public Module {
public:
	moduleRender(aplication *APP);
	~moduleRender();
	bool Init()override;
	States Preupdate()override;
	States Postupdate()override;
	bool CleanUp()override;
	void Blit(SDL_Texture* texture,int x,int y,SDL_Rect* texturesize);
	SDL_Renderer* renderer=nullptr;

};
#endif 

