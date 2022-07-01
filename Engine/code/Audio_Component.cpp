/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Audio_Component.hpp"
#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_audio.h>



namespace Engine
{
	Audio_Component::Audio_Component(GameObject* s, std::string rute, int _volume) :Component(s)
	{

		sample = Mix_LoadWAV(rute.c_str());
		volume = _volume;
		Mix_VolumeChunk(sample, volume);

	}
	void Audio_Component::change_chunk(std::string rute)
	{
		//https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.pdf#page=69&zoom=100,120,96 , pag 26
		Mix_FreeChunk(sample);
		sample = NULL;

		sample = Mix_LoadWAV(rute.c_str());

	}
	void Audio_Component::play_chunk()
	{
		if (Mix_PlayChannel(-1, sample, 0) == -1);
	}
	void Audio_Component::change_volume(int _volume)
	{
		volume = _volume;
		Mix_VolumeChunk(sample, _volume);
	}
}