#pragma once
#include "../include/vec.h"

class Brick {
public:
	bool active;

	vec2 position;
	vec2 size;
	vec4 color;

	Brick();
	Brick(vec2 size, vec2 position);

	void hitBrick(void);
	void destroyBrick(void);

	void draw(void);
};