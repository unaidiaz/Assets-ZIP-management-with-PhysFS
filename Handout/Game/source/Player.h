#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Module.h"
#include "Animation.h"
#include"External/SDL_image/include/SDL_image.h"
#include "Point.h"
class Player: public Module {
public:
	Player(aplication* APP);
	~Player();
	bool Start()override;
	States Preupdate()override;
	States Update()override;
	States Postupdate()override;
private:
	Animation front;
	Animation back;
	Animation right;
	Animation left;
	iPoint position;
	Animation* actual;
	SDL_Texture* playerText;
	int step;
	int counter;
};

#endif
