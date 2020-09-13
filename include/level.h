#pragma once
#include "../include/brick.h"
#include "../include/vec.h"
#include <iostream>
#include <vector>

class Level {
public:
	std::vector<Brick*> bricks;
	vec2 firstPosition;
	vec2 padding;
	vec2 brickSize;

	Level();
	Level(std::vector<std::vector<int>> brickMatrix, vec2 firstPosition = vec2(0.0, 0.0), vec2 padding = vec2(5.0, 5.0));

	void draw(void);
	void drawBricks(void);
	void reset(void);

	void deleteAllBricks(void);
};