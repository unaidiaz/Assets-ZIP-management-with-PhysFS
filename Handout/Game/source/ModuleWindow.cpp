#include"ModuleWindow.h"
#include"Aplication.h"
ModuleWindow::ModuleWindow(aplication* APP) :Module(APP) {

}
ModuleWindow::~ModuleWindow() {

}
bool ModuleWindow::Init() {
	bool result = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		result = false;
	}

	int prop = SDL_WINDOW_SHOWN;
	window = SDL_CreateWindow("Assets ZIP management with PhysFS", SDL_WINDOWPOS_CENTERED_MASK, SDL_WINDOWPOS_CENTERED_MASK, WINDOWWIDTH, WINDOWHIGH, prop);
	if (window == nullptr) {
		result = false;
	}
	surface = SDL_GetWindowSurface(window);
	if (surface < 0) {
		result = false;
	}
	return result;
}
bool ModuleWindow::CleanUp() 
{
	bool result = true;
	if (window != nullptr) {
		SDL_DestroyWindow(window);
	}
	if (window != nullptr) {
		result = false;
	}
	SDL_Quit();
	return result;
}