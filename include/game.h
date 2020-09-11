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
	vec2 paddleOrigin;
	vec2 paddleSize;
	vec4 paddleColor;

	void init(void);
	void display(void);
	void reshape(int w, int h);
	void draw(void);
	void idle(void);

	void initPaddle(vec2 size, vec2 center, vec4 color);

	void drawPaddle();

	Game();
};