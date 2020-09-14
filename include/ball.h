#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include "../include/vec.h"
#include "../include/deltatime.h"
#include "../include/paddle.h"
#include "../include/level.h"
#include "../include/useful_math.h"

class Ball {
public:
	bool active;

	vec2 position;
	float radius;
	vec4 color;

	vec2 moveDirection;
	float moveSpeed;
	float maxSpeed, minSpeed;
	float maxAngle;

	Ball();
	Ball(float radius, vec2 position = vec2(0.0, 0.0), vec4 color = vec4(1.0, 1.0, 1.0, 1.0), 
		vec2 moveDirection = vec2(0.0, -1.0), float maxSpeed = 100.0, float minSpeed = 50.0);

	void moveBall();
	void destroyBall();
	void reset(vec2 resetPos, vec2 resetDir);
	bool clampBallToScreenBounds(float width, float height);

	bool collidesWithRect(float xmin, float ymin, float xmax, float ymax);
	bool collidesWithPaddle(Paddle paddle);
	bool collidesWithBrick(Brick brick);
	bool isBelowPaddle(Paddle paddle);

	vec2 collisionDirectionWithRect(float xcenter, float ycenter);
	vec2 collisionDirectionWithPaddle(Paddle paddle);
	vec2 collisionDirectionWithBrick(Brick brick);
	float collisionAngle(vec2 collisionDirection);

	void checkPaddleCollision(Paddle paddle);
	int checkBrickCollision(Level level);
	bool checkDeath(Paddle paddle);

	void draw(void);
	void drawOnPosition(vec2 drawPos);
};