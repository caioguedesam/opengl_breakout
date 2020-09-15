#include "../include/music.h"

Music::Music() {
    music = NULL;
    loopTimes = 0;
    path = "";
}

Music::Music(const char* path, int loopTimes) {
    music = NULL;
    this->loopTimes = loopTimes;
    this->path = path;
}

void Music::load(void) {
    music = Mix_LoadMUS(path);
    if(music == NULL) {
        std::cout << "Failed loading music" << std::endl;
        return;
    }
}

void Music::play(void) {
    if(Mix_PlayMusic(music, loopTimes) == -1) {
        std::cout << "Failed playing music" << std::endl;
        return;
    }
}

void Music::free(void) {
    Mix_FreeMusic(music);
}

Sound::Sound() {
    sfx = NULL;
    loopTimes = 0;
    path = "";
}

Sound::Sound(const char* path, int loopTimes) {
    sfx = NULL;
    this->loopTimes = loopTimes;
    this->path = path;
}

void Sound::load(void) {
    sfx = Mix_LoadWAV(path);
    if(sfx == NULL) {
        std::cout << "Failed loading sfx" << std::endl;
        return;
    }
}

void Sound::play(void) {
    if(Mix_PlayChannel(-1, sfx, loopTimes) == -1) {
        std::cout << "Failed playing sfx" << std::endl;
        std::cout << Mix_GetError() << std::endl;
        return;
    }
}

void Sound::free(void) {
    Mix_FreeChunk(sfx);
}

void AudioSource::addMusic(Music music) {
    this->music = music;
}

void AudioSource::addSfx(Sound sound, char key) {
    sounds.insert(std::pair<char, Sound>(key, sound));
}

void AudioSource::init(void) {
    // Initializing SDL and SDL mixer
    if(SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "Failed SDL_Init" << std::endl;
		return;
	}
	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        std::cout << "Failed Mix_OpenAudio" << std::endl;
		return;
	}

    Mix_AllocateChannels(16);
    addMusic(Music("sounds/mitsuo.ogg", -1));
    addSfx(Sound("sounds/bounce.wav", 0), 'p');
    addSfx(Sound("sounds/hit1.wav", 0), 'b');
    addSfx(Sound("sounds/wobbledown.wav", 0), 'd');
    addSfx(Sound("sounds/wobbleup.wav", 0), 'u');
    addSfx(Sound("sounds/blunk.wav", 0), 'w');

    loadAll();
}

void AudioSource::loadAll(void) {
    music.load();
    std::map<char, Sound>::iterator it;
    for(it = sounds.begin(); it != sounds.end(); it++) {
        (*it).second.load();
    }
}

void AudioSource::startMusic(void) {
    music.play();
}

void AudioSource::playSound(char key) {
    sounds[key].play();
}

void AudioSource::freeResources(void) {
    music.free();
    std::map<char, Sound>::iterator it;
    for(it = sounds.begin(); it != sounds.end(); it++) {
        (*it).second.free();
    }
}