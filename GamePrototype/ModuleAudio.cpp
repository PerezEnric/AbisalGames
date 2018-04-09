#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")

ModuleAudio::ModuleAudio()
{
	for (uint i = 0; i < MAX_MUSIC; ++i) songs[i] = nullptr;
	for (uint i = 0; i < MAX_FX; ++i) sound_effect[i] = nullptr;
}

ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Init()
{
	bool ret = true;

	LOG("Loading audio assets");

	if (Mix_Init(MIX_INIT_OGG) < 0)
	{
		LOG("An error occured: %s", Mix_GetError());
		ret = false;
	}
	else
	{
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
		{
			LOG("Can't open %s", Mix_GetError());
			ret = false;
		}
	}
	return ret;
}

bool ModuleAudio::CleanUp()
{
	LOG("Cleaning audio");
	for (uint i = 0; i < MAX_MUSIC; ++i)
	{
		if (songs[i] != nullptr)

		{
			Mix_FreeMusic(songs[i]);
		}

		for (uint i = 0; i < MAX_FX; ++i)
		{
			Mix_FreeChunk(sound_effect[i]);
		}
	}
	Mix_CloseAudio();
	Mix_Quit();
	return true;
}

void ModuleAudio::PlayMusic(Mix_Music* music_to_play, int repetitions)
{
	Mix_PlayMusic(music_to_play, repetitions);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
}

void ModuleAudio::PlaySoundEffect(Mix_Chunk* effect_to_play)
{
	Mix_PlayChannel(-1, effect_to_play, 0);
}


Mix_Music* const ModuleAudio::LoadMusic(const char* path)
{
	Mix_Music* music = nullptr;
	if (last_song < MAX_MUSIC)
	{
		music = Mix_LoadMUS(path);

		if (music = nullptr)

		{
			LOG("Can't load the song: %s", Mix_GetError());
		}
		else
		{
			songs[last_song++] = music;
		}
	}
	return music;
}

Mix_Chunk* const ModuleAudio::LoadSoundEffect(const char* path)

{
	Mix_Chunk * effect = nullptr;

	if (last_effect < MAX_FX)
	{
		effect = Mix_LoadWAV(path);
		if (effect == nullptr)
		{
			LOG("Can't load the effect: %s", Mix_GetError)
		}
	}
	return effect;
}

void ModuleAudio::UnloadMusic(Mix_Music*music)
{
	for (uint i = 0; i < last_song; ++i)
	{
		if (songs[i] == music)
		{
			Mix_FreeMusic(music);
			break;
		}
	}
}

void ModuleAudio::UnloadSoundEffect(Mix_Chunk * effect)
{
	for (uint i = 0; i < last_song; ++i)
	{
		if (sound_effect[i] == effect)
		{
			Mix_FreeChunk(effect);
			break;
		}
	}
}