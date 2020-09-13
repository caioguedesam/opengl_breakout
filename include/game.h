#pragma once
#include <GL/freeglut.h>
#include "../include/paddle.h"
#include "../include/ball.h"
#include "../include/level.h"
#include "../include/vec.h"
#include "../include/deltatime.h"
#include "../include/useful_math.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <iomanip>

enum class GameState { GAME_PAUSED, GAME_PLAYING };

class Game {
public:
	GameState state;

	const char* gameTitle = "Breakout!";
	GLint displayWidth, displayHeight;
	vec2 mousePosition;

	Paddle paddle;
	vec2 paddleOrigin;
	vec2 paddleSize;
	vec4 paddleColor;

	Ball ball;
	vec2 ballOrigin;
	float ballRadius;
	vec4 ballColor;
	vec2 ballDirection;
	float ballMaxSpeed, ballMinSpeed;

	Level level;
	std::vector<std::vector<int>> brickMatrix;
	vec2 firstBrickPos;
	vec2 brickPadding;

	void init(void);
	void display(void);
	void reshape(int w, int h);
	void mouseMove(int x, int y);
	void mouseInput(int button, int buttonState, int x, int y);
	void draw(void);
	void update(void);
	void idle(void);
	void pause(void);
	void play(void);

	void updateDeltaTime(void);
	void updateCollisions(void);

	void initPaddle(vec2 size, vec2 position, vec4 color);
	void initBall(float radius, vec2 position, vec4 color, vec2 direction, float maxSpeed, float minSpeed);
	void initLevel(std::vector<std::vector<int>> brickMatrix, vec2 firstPosition, vec2 padding);

	void drawPaddle(void);
	void drawBall(void);
	void drawLevel(void);

	Game();
};