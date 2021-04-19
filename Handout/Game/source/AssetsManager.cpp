#include"AssetsManager.h"
#include"Aplication.h"
#include"External/PhysFS/include/physfs.h"

AssetsManager::AssetsManager(aplication* APP) :Module(APP) 
{
	//TODO 1: initialize the library (1 line)
	
}
AssetsManager::~AssetsManager() 
{
	//TODO 2: Deinitialize the library (1 line)

}
bool AssetsManager::Init() 
{
	//TODO 3: add the search path (1 line)
	
	return true;
}
int AssetsManager::MakeLoad(const char* fileName) 
{
	int ret = 0;
	//TODO 5: get the information buffer, and its size with the functions and variables of the library (5 line ~)
	
	
	
	return ret;
}
SDL_RWops* AssetsManager::Load(const char* fileName) 
{
	//TODO 4: call the MakeLoad functionand get the RWops structure to load the data(3 line)
	
	return nullptr;
}
bool AssetsManager::DeleteBuffer() {
	delete[] buffer;
	return true;
}
char* AssetsManager::GetLastBuffer() {
	return buffer;
}
