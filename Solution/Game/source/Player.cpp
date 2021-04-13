#include "Player.h"
#include"ModuleTextures.h"
#include "ModuleInput.h"
#include"Aplication.h"
#include"ModuleAudio.h"

Player::Player(aplication* APP) : Module(APP)
{
	front.PushBack({ 1,1,30,35 });
	front.PushBack({ 48,1,30,35 });
	front.PushBack({ 93,1,30,35 });
	front.loop = true;
	front.speed = 0.1f;

	back.PushBack({1,72,30,35});
	back.PushBack({ 47,72,30,35 });
	back.PushBack({ 93,72,30,35 });
	back.loop = true;
	back.speed = 0.1f;

	right.PushBack({ 1,36,32,35 });
	right.PushBack({ 47,36,32,35 });
	right.PushBack({ 92,36,32,35 });
	right.loop = true;
	right.speed = 0.1f;

	left.PushBack({ 0,107,32,38 });
	left.PushBack({ 45,107,32,38 });
	left.PushBack({ 91,107,32,38 });
	left.loop = true;
	left.speed = 0.1f;
	actual = &front;

	position = { 90,0 };
	counter = 0;
}
Player::~Player() 
{

}
bool Player::Start() 
{
	step = app->audio->LoadFx("Audio/fx/step.wav");
	playerText = app->Texture->Load("Textures/Player.png");
	return true;
}
States Player::Preupdate()
{
	return States::Continue;
}
States Player::Update()
{
	if (app->Input->Keys[SDL_SCANCODE_W] == KeyState::KeyDown) 
	{
		counter++;
		position.y -= 1;
		actual = &back;
		actual->Update();
	}else if (app->Input->Keys[SDL_SCANCODE_S] == KeyState::KeyDown)
	{
		counter++;
		position.y += 1;
		actual = &front;
		actual->Update();
	}
	else if (app->Input->Keys[SDL_SCANCODE_D] == KeyState::KeyDown)
	{
		counter++;
		position.x += 1;
		actual = &right;
		actual->Update();
	}
	else if (app->Input->Keys[SDL_SCANCODE_A] == KeyState::KeyDown)
	{
		counter++;
		position.x -= 1;
		actual = &left;
		actual->Update();
	}
	
	return States::Continue;
}
States Player::Postupdate()
{
	if (counter == 30) {
		app->audio->PlayFx(step);
		counter = 0;
	}
	SDL_Rect rect = actual->GetCurrentFrame();
	app->render->Blit(playerText, position.x, position.y, &rect);
	return States::Continue;
}