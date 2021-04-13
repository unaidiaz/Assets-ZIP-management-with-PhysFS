#include<stdio.h>
#include <stdlib.h>
#include"Aplication.h"
#include"Globals.h"
#define finalOk 1
#define finalError -1
enum class GameState {
	Create,
	Init,
	Loop,
	End,
	Exit
};


int main(int argc, char* argv[]) {
	aplication* app = nullptr;
	//

	//
	GameState actualState;
	int mainState = finalError;
	actualState = GameState::Create;
	while (actualState != GameState::Exit) {
		switch (actualState)
		{
		case GameState::Create:
		{
			//
			app = new aplication();

			actualState = GameState::Init;
		}break;

		case GameState::Init:
		{
			bool result;
			
			result = app->InitModules();
			if (result == true) {
				actualState = GameState::Loop;
			}
			else {
				actualState = GameState::Exit;
			}



		}break;

		case GameState::Loop:
		{
			States result;
			
			result = app->LoopModules();

			if (result == States::Exit) {
				actualState = GameState::End;
			}
			


		}break;

		case GameState::End:
		{
			bool resultado = app->CleanModules();
			
			if (resultado == true) {
				mainState = finalOk;
			}
			actualState = GameState::Exit;

		}break;
		}
	}
	
	delete app;
	return mainState;
}