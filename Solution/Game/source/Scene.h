#ifndef _SCENE_H_
#define _SCENE_H_
#include"Module.h"
#include"Globals.h"
#include"External/SDL_image/include/SDL_image.h"
#include"External/SDL_mixer/include/SDL_mixer.h"
class ModuleScene :public Module {
public:
	ModuleScene(aplication* APP);
	~ModuleScene();
	
	bool CleanUp()override;
	bool Start()override;
	States Preupdate()override;
	States Update()override;
	States Postupdate()override;
private:
};
#endif
