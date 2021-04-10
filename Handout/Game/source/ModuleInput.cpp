#include "ModuleInput.h"

ModuleInput::ModuleInput(aplication* APP) :Module(APP) {
	for (int a = 0; a < MAXKEYS; a++) {
		Keys[a] = KeyState::KeyFree;
	}
}
ModuleInput::~ModuleInput() {

}
bool ModuleInput::Init() {
	bool result = true;
	if (SDL_Init(SDL_INIT_EVENTS) < 0) {
		result = false;
	}
	//SDL_InitSubSystem(SDL_INIT_EVENTS);
	return result;
}
States ModuleInput::Preupdate() {
	States result = States::Continue;
	SDL_PumpEvents();
	const Uint8* teclado = SDL_GetKeyboardState(NULL);
	for (int a = 0; a < MAXKEYS; a++) {
		if (teclado[a] == 1) {
			if (Keys[a] == KeyState::KeyFree) {
				Keys[a] = KeyState::KeyRepeat;
			}
			else {
				Keys[a] = KeyState::KeyDown;
			}
		}
		else {
			if (Keys[a] == KeyState::KeyDown || Keys[a] == KeyState::KeyRepeat) {
				Keys[a] = KeyState::KeyUp;
			}
			else {
				Keys[a] = KeyState::KeyFree;
			}
		}
	}
	return result;
}
bool ModuleInput::CleanUp() {
	bool result = true;

	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return result;
}