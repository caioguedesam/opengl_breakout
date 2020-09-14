#pragma once
#include <GL/freeglut.h>
#include "../include/paddle.h"
#include "../include/ball.h"
#include "../include/level.h"
#include "../include/vec.h"
#include "../include/deltatime.h"
#include "../include/useful_math.h"
#include "../include/text_render.h"
#include "../include/camera_shake.h"
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

enum class GameState { GAME_PAUSED, GAME_PLAYING };
enum class FinishState { GAME_WIN, GAME_LOSE, GAME_UNFINISHED };

class Game {
public:
	const char* gameTitle = "Breakout!";
	GLint displayWidth, displayHeight;
	vec2 mousePosition;

	CameraShake shake;
	float brickShakeTime;
	float brickShakeAmount;
	float boundsShakeTime;
	float boundsShakeAmount;

	GameState state;
	FinishState finishState;
	bool pauseAfterUpdate;

	unsigned int score;
	vec2 scorePosition;
	int scoreForMaxSpeed;
	
	unsigned int lives;
	unsigned int startingLives;
	vec2 livesPosition;
	bool isDead;
	vec2 respawnOffset;
	vec2 respawnDirection;

	Paddle paddle;
	vec2 paddleOrigin;
	vec2 paddleSize;
	vec4 paddleColor;

	Ball ball;
	vec2 ballOrigin;
	float ballRadius;
	vec4 ballColor;
	vec2 ballDirection;
	float ballMaxSpeed, ballMinSpeed, ballFinalSpeed;

	Level level;
	std::vector<std::vector<int>> brickMatrix;
	vec2 firstBrickPos;
	vec2 brickPadding;

	void init(void);
	void display(void);
	void reshape(int w, int h);
	
	void mouseMove(int x, int y);
	void mouseInput(int button, int buttonState, int x, int y);
	void keyboardInput(unsigned char key, int x, int y);
	
	void update(void);
	void idle(void);

	void shakeCamera(float amount, float duration);
	void scorePoint(void);
	void increaseBallSpeed(void);
	void changePaddleSize(int brickValue);
	void loseLife(void);
	void win(void);
	void lose(void);
	
	void pause(void);
	void play(void);
	void quit(void);
	void reset(void);
	void respawn(void);

	void updateDeltaTime(void);
	void updateCollisions(void);
	void checkGameFinish(void);

	void initPaddle(vec2 size, vec2 position, vec4 color);
	void initBall(float radius, vec2 position, vec4 color, vec2 direction, float maxSpeed, float minSpeed);
	void initLevel(std::vector<std::vector<int>> brickMatrix, vec2 firstPosition, vec2 padding);

	void draw(void);
	void drawPaddle(void);
	void drawBall(void);
	void drawLevel(void);
	void drawScore(void);
	void drawLives(void);
	void drawVictoryScreen(void);
	void drawDefeatScreen(void);

	void displayStats(void);

	Game();
};