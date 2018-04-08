#include "ModuleAudio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#include "SDL/include/SDL.h"
#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")

ModuleAudio::ModuleAudio()
{

}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Init()
{
	LOG("Loading audio assets");
	bool ret = true;

	if (SDL_Init(MIX_INIT_OGG) > 0)
	{
		return false;
	}
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
}

bool ModuleAudio::Start()
{

	firstlvlmusic = Mix_LoadMUS("IntotheHumanBody(Stage1).ogg");

	if (firstlvlmusic == NULL)
	{
		LOG("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());


		return false;
	}

	return true;
}

update_status ModuleAudio::Update()
{
	// check if music is playing
	LOG("music is%s playing.\n", Mix_PlayingMusic() ? "" : " not");

	Mix_PlayMusic(firstlvlmusic, -1);

	return UPDATE_CONTINUE;
}

bool ModuleAudio::CleanUp()
{

	Mix_FreeMusic(firstlvlmusic);
	firstlvlmusic = NULL;
	Mix_CloseAudio();
	return true;
}
