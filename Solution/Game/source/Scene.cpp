#include"Scene.h"
#include"Aplication.h"
#include"ModuleInput.h"
#include"External/PugiXml/src/pugixml.hpp"
#include"External/PhysFS/include/physfs.h"
ModuleScene::ModuleScene(aplication* APP) :Module(APP) 
{

}
ModuleScene::~ModuleScene() 
{

}

bool ModuleScene::CleanUp() 
{
	bool resultado = true;

	return resultado;
}
bool ModuleScene::Start() 
{
	bool resultado = true;
	app->audio->PlayMusic("Audio/Music/Jazzy.ogg");
	app->map->Load("map.tmx");
	
	return resultado;
}
States ModuleScene::Preupdate()
{
	return States::Continue;
}
States ModuleScene::Update()
{
	if (app->Input->Keys[SDL_SCANCODE_ESCAPE] == KeyState::KeyDown) 
	{
		return States::Exit;
	}
	
	
	return States::Continue;
}
States ModuleScene::Postupdate()
{

	return States::Continue;
}