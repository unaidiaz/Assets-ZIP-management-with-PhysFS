#ifndef MODULEWINDOW_H_
#define MODULEWINDOW_H_
#include"External/SDL_image/include/SDL_image.h"
#include"Module.h"
#include"Globals.h"
class ModuleWindow :public Module {
public:
	ModuleWindow(aplication* APP);
	~ModuleWindow();
	bool Init()override;
	bool CleanUp()override;
	SDL_Window* window;
	SDL_Surface* surface;
};

#endif
