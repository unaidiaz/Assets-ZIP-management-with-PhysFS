#include"ModuleAudio.h"
#include"Aplication.h"

Audio::Audio(aplication* APP) : Module(APP)
{
	music = NULL;
	volumeMusic = 20;
	volumeFx = 100;
}

// Destructor
Audio::~Audio() {}
void Audio::Unload(int id)
{
	int cont = 0;
	for (int a=0; a<MAX_FX && cont <= id; a++)
	{
		if (id == cont)
		{
			Mix_FreeChunk(fx[a]);
			break;
		}
		cont++;
	}
}

// Called before render is available
bool Audio::Init()
{
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		

		ret = true;
	}

	// Load support for the JPG and PNG image formats
	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if ((init & flags) != flags)
	{
		
		ret = true;
	}

	// Initialize SDL_mixer
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		
		ret = true;
	}
	Mix_VolumeMusic(10);

	return ret;
}

States Audio::Update()
{
	/*for(int a=0;a<MAX_FX;a++)
	{
		Mix_VolumeChunk(fx[a], volumeFx);
	}

	Mix_VolumeMusic(volumeMusic);*/
	

	return States::Continue;
}

// Called before quitting
bool Audio::CleanUp()
{

	if (music != NULL)
	{
		Mix_FreeMusic(music);
	}

	for (int a = 0; a < MAX_FX; a++) 
	{
		Mix_FreeChunk(fx[a]);
	}
		

	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);

	return true;
}

// Play a music file
bool Audio::PlayMusic(const char* path, float fadeTime)
{
	bool ret = true;



	if (music != NULL)
	{
		if (fadeTime > 0.0f)
		{
			Mix_FadeOutMusic(int(fadeTime * 1000.0f));
		}
		else
		{
			Mix_HaltMusic();
		}

		// This call blocks until fade out is done
		Mix_FreeMusic(music);
	}
	//music = Mix_LoadMUS(path);
	music = Mix_LoadMUS_RW(app->Assets->Load(path),1);
	
	if (music == NULL)
	{
		
		ret = false;
	}
	else
	{
		if (fadeTime > 0.0f)
		{
			if (Mix_FadeInMusic(music, -1, (int)(fadeTime * 1000.0f)) < 0)
			{
				
				ret = false;
			}
		}
		else
		{
			if (Mix_PlayMusic(music, -1) < 0)
			{
				
				ret = false;
			}
		}
	}

	
	return ret;
}

// Load WAV
unsigned int Audio::LoadFx(const char* path)
{
	int ret = 0;

	

	Mix_Chunk* chunk=nullptr;
	chunk=Mix_LoadWAV_RW(app->Assets->Load(path),1);
	for (int a = 0; a < MAX_FX; a++) 
	{
		if (fx[a] == nullptr) {
			if (chunk != NULL)
			{
				fx[a] = chunk;
				break;
			}
		}
		ret++;
	}
	app->Assets->DeleteBuffer();

	return ret;
}

// Play WAV
bool Audio::PlayFx(unsigned int id, int repeat)
{
	bool ret = false;



	if (id >= 0 && id <= MAX_FX)
	{
		Mix_PlayChannel(-1, fx[id], repeat);
	}

	return ret;
}