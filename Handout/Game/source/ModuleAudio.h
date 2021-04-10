#ifndef _MODULEAUDIO_H_
#define _MODULEAUDIO_H_

#include"Module.h"
#include"External/SDL/include/SDL.h"
#include"External/SDL_mixer/include/SDL_mixer.h"
#define DEFAULT_MUSIC_FADE_TIME 2.0f
#define MAX_FX 50
//struct _Mix_Music;
//struct Mix_Chunk;

class Audio : public Module
{
public:

	Audio(aplication* APP);

	// Destructor
	virtual ~Audio();

	// Called before render is available
	bool Init();

	States Update()override;
	// Called before quitting
	bool CleanUp();
	// Play a music file
	bool PlayMusic(const char* path, float fadeTime = DEFAULT_MUSIC_FADE_TIME);

	// Load a WAV in memory
	unsigned int LoadFx(const char* path);

	// Play a previously loaded WAV
	bool PlayFx(unsigned int fx, int repeat = 0);
	void Unload(int id);

	int volumeMusic;
	int volumeFx;
private:

	_Mix_Music* music;
	Mix_Chunk*	fx[MAX_FX];
};





#endif
