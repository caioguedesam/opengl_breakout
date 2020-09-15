CC = g++

GLFLAGS = -lGL -lGLU -lglut
SDLFLAGS = -lSDL2 -lSDL2_mixer -DGAME_SOUND

all:
ifeq ($(SOUND),)
	$(CC) src/*.cpp -o breakout $(GLFLAGS)
else
	$(CC) src/*.cpp -o breakout $(GLFLAGS) $(SDLFLAGS)
endif