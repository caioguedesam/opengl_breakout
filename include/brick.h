#pragma once
#include "../include/vec.h"
#include "../include/paddle.h"
#include <iostream>
#include <vector>

extern std::vector<vec4> normalBrickColors;
extern std::vector<vec4> specialBrickColors;

enum class BrickType { BRICK_NORMAL = 1, BRICK_BIG_PADDLE = -1, BRICK_SMALL_PADDLE = -2 };

class Brick {
public:
	bool active;

	vec2 position;
	vec2 size;
	vec4 color;
	BrickType type;
	int hp;
	int originalHp;
	unsigned int lastHitTime;

	Brick();
	Brick(vec2 size, vec2 position, int hp, BrickType type = BrickType::BRICK_NORMAL);

	bool hitBrick(void);
	void destroyBrick(void);
	void setColor(void);

	void draw(void);
};