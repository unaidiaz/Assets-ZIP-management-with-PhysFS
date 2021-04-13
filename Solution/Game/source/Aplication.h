#ifndef _APLICATION_H_
#define _APLICATION_H_
#include "Globals.h"

#include"AssetsManager.h"
#include"ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuloRender.h"
#include"ModuleTextures.h"
#include"ModuleAudio.h"
#include"Scene.h"
#include"Map.h"
#include"Player.h"
#define MAXMODULES 9

class aplication {
public:
	aplication();
	~aplication();
	bool InitModules();
	States LoopModules();
	bool CleanModules();
	AssetsManager* Assets = nullptr;
	ModuleWindow* Window = nullptr;
	ModuleInput* Input = nullptr;
	ModuleTextures* Texture = nullptr;
	moduleRender* render = nullptr;
	ModuleScene* scene = nullptr;
	Audio* audio = nullptr;
	Map* map = nullptr;
	Player* player = nullptr;
	Module* Modules[MAXMODULES];
};
#endif
