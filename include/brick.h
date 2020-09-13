#pragma once
#include "../include/vec.h"
#include <iostream>
#include <vector>

extern std::vector<vec4> brickColors;

class Brick {
public:
	bool active;

	vec2 position;
	vec2 size;
	vec4 color;
	int hp;
	unsigned int lastHitTime;

	Brick();
	Brick(vec2 size, vec2 position, int hp);

	void hitBrick(void);
	void destroyBrick(void);
	void setColor(void);

	void draw(void);
};