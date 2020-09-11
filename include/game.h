#pragma once
#include <GL/freeglut.h>
#include "../include/paddle.h"
#include "../include/vec.h"
#include <iostream>

class Game {
public:
	const char* gameTitle = "Breakout!";
	GLint displayWidth, displayHeight;

	Paddle paddle;

	void init(void);
	void display(void);
	void reshape(int w, int h);

	Game();
};