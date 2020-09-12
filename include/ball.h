#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include "../include/vec.h"
#include "../include/deltatime.h"
#include "../include/paddle.h"

class Ball {
public:
	vec2 position;
	float radius;
	vec4 color;

	vec2 moveDirection;
	float moveSpeed;

	Ball();
	Ball(float radius, vec2 position = vec2(0.0, 0.0), vec4 color = vec4(1.0, 1.0, 1.0, 1.0), vec2 moveDirection = vec2(0.0, -1.0), float moveSpeed = 10.0);

	void moveBall();
	bool collidesWithRect(float xmin, float ymin, float xmax, float ymax);
	bool collidesWithPaddle(Paddle paddle);
	vec2 collisionDirectionWithRect(float xcenter, float ycenter);
	vec2 collisionDirectionWithPaddle(Paddle paddle);
	void checkPaddleCollision(Paddle paddle);
};