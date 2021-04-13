#ifndef _MODULEINPUT_H_
#define _MODULEINPUT_H_
#include"Module.h"
#include "External/SDL/include/SDL_scancode.h"
#include "External/SDL/include/SDL.h"
#define MAXKEYS 256
enum class KeyState {
	KeyFree,
	KeyDown,
	KeyRepeat,
	KeyUp
};
class ModuleInput :public Module {
public:
	ModuleInput(aplication* APP);
	~ModuleInput();
	bool Init()override;
	States Preupdate()override;
	bool CleanUp()override;
	KeyState Keys[MAXKEYS];
};
#endif
