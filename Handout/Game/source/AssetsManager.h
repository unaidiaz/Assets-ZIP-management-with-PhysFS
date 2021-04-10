#ifndef _ASSETSMANAGER_H_
#define _ASSETSMANAGER_H_
#include"Module.h"
#include"External/SDL/include/SDL.h"
class AssetsManager :public Module {
public:
	AssetsManager(aplication* APP);
	~AssetsManager();
	bool Init();
	SDL_RWops* Load(const char* fileName);
	int MakeLoad(char** buffer, const char* fileName);

};
#endif // !_ASSETSMANAGER_H_
