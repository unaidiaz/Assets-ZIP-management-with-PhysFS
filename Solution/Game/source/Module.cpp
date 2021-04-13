#include"Module.h"

Module::Module(aplication* APP) {
	app = APP;
}
Module::~Module() {

}
bool Module::Init() {
	return true;
}
bool Module::Start() {
	return true;
}
States Module::Preupdate() {
	return States::Continue;
}
States Module::Update() {
	return States::Continue;
}
States Module::Postupdate() {
	return States::Continue;
}
bool Module::CleanUp() {
	return true;
}