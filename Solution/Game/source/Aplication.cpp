#include"Aplication.h"
#include"Module.h"
aplication::aplication() {
	//hacer aqui el new de todo y meter en el array de punteros modulos
	Modules[0] = Window = new ModuleWindow(this);
	Modules[1] = Input = new ModuleInput(this);
	Modules[2] = Texture = new ModuleTextures(this);
	Modules[3] = audio = new Audio(this);
	Modules[4] = Assets = new AssetsManager(this);
	Modules[5] = scene = new ModuleScene(this);
	Modules[6] = map = new Map(this);
	Modules[7] = player = new Player(this);
	Modules[8] = render = new moduloRender(this);

}
aplication::~aplication() {

}
//aqui loops
bool aplication::InitModules() {
	bool result = true;
	//iniciar primero todos y luego empezar los que tengan que empezar (al principio todos tambien)
	for (int a = 0; a < MAXMODULES && result == true; a++) {
		result = Modules[a]->Init();
	}
	for (int a = 0; a < MAXMODULES && result == true; a++) {
		result = Modules[a]->Start();
	}
	return result;
}
States aplication::LoopModules() {
	States result = States::Continue;
	for (int a = 0; a < MAXMODULES && result == States::Continue; a++) {
		result = Modules[a]->Preupdate();
	}
	for (int a = 0; a < MAXMODULES && result == States::Continue; a++) {
		result = Modules[a]->Update();
	}
	for (int a = 0; a < MAXMODULES && result == States::Continue; a++) {
		result = Modules[a]->Postupdate();
	}
	//hacer pre update post
	return result;
}
bool aplication::CleanModules() {
	bool result = true;
	for (int a = 0; a < MAXMODULES && result == true; a++) {
		result = Modules[a]->CleanUp();
	}
	//limpiar todo los modulos
	return result;
}