#pragma once

#include "Sound.h"

#include <SDL.h>
#include <vector>
#include <memory>




class AudioManager
{
	static SDL_AudioSpec sAudioFormat;
	static std::vector<std::shared_ptr<Sound> > sSoundVector;
	static std::shared_ptr<AudioManager> sInstance;

	static void mixAudio(void *unused, Uint8 *stream, int len);

	AudioManager();

public:
	static std::shared_ptr<AudioManager> & getInstance();

	void init();
	void deinit();

	void registerSound(std::shared_ptr<Sound> & sound);
	void unregisterSound(std::shared_ptr<Sound> & sound);

	void play();
	void stop();

	virtual ~AudioManager();
};
