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
};