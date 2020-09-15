#pragma once
#ifdef GAME_SOUND
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <map>

class Music {
public:
    Mix_Music* music;
    int loopTimes;
    const char* path;

    Music();
    Music(const char* path, int loopTimes);
    void load(void);
    void play(void);
    void free(void);
};

class Sound {
public:
    Mix_Chunk* sfx;
    int loopTimes;
    const char* path;

    Sound();
    Sound(const char* path, int loopTimes);
    void load(void);
    void play(void);
    void free(void);
};

class AudioSource {
public:
    Music music;
    std::map<char, Sound> sounds;

    void init(void);
    void addMusic(Music music);
    void addSfx(Sound sfx, char key);
    void loadAll(void);
    void startMusic(void);
    void playSound(char key);
    void freeResources(void);
};
#endif