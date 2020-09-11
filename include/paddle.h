#pragma once
#include "../include/vec.h"

class Paddle {
public:
	vec2 center;
	vec2 size;
	vec4 color;

	vec2 moveDirection;
	GLfloat moveSpeed;

	Paddle();
	Paddle(vec2 size, vec2 center = vec2(0.0, 0.0), vec4 color = vec4(1.0, 1.0, 1.0, 1.0), float moveSpeed = 0.0f);

	void movePaddle(int x, int y);
};