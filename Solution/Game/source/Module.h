#ifndef MODULE_H_
#define MODULE_H_
//
#include"Globals.h"

class aplication;
class Module {
public:
	aplication* app;
	Module(aplication* APP);
	~Module();
	virtual bool Init();
	virtual bool Start();
	virtual States Preupdate();
	virtual States Update();
	virtual States Postupdate();
	virtual bool CleanUp();
};
#endif
