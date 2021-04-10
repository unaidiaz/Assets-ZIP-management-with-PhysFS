#include<stdio.h>
#include <stdlib.h>
#include"Aplication.h"
#include"Globals.h"
#define finalExito 1
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
	//crear puntero a app

	//
	GameState actualState;
	int mainState = finalError;
	actualState = GameState::Create;
	while (actualState != GameState::Exit) {
		switch (actualState)
		{
		case GameState::Create:
		{
			//crear con new y el puntero la clase
			app = new aplication();

			actualState = GameState::Init;
		}break;

		case GameState::Init:
		{
			bool result;
			//iniciar clase app y de hay todos los demas independientemente de si estan listos o no y luego os que estan preparados
			//
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
			//actualizar todos los modulos desde app diferenciando pre update y post
			//igualar ese update al resultado
			result = app->LoopModules();

			if (result == States::Exit) {
				actualState = GameState::End;
			}
			//si sale aglo mal o sale


		}break;

		case GameState::End:
		{
			bool resultado = app->CleanModules();
			//finlaizar todos los modulos
			if (resultado == true) {
				mainState = finalExito;
			}
			actualState = GameState::Exit;

		}break;
		}
	}
	//hacer el delete de app
	delete app;
	return mainState;
}