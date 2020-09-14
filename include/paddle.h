#pragma once
#include "../include/vec.h"
#include "../include/useful_math.h"
#include "../include/deltatime.h"

class Paddle {
public:
	vec2 position;
	vec2 size;
	vec4 color;

	float moveSpeed;

	Paddle();
	Paddle(vec2 size, vec2 position = vec2(0.0, 0.0), vec4 color = vec4(1.0, 1.0, 1.0, 1.0), float moveSpeed = 1.5f);

	void movePaddle(vec2 mousePos);
	void reset(vec2 resetPos);

	void draw(void);
};