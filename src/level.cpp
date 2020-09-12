#include "../include/level.h"

Level::Level() {
	this->firstPosition = vec2();
	this->padding = vec2();
	this->brickSize = vec2();
}

Level::Level(int brickCount, vec2 firstPosition, vec2 padding) {
	this->bricks = std::vector<Brick>();
	this->firstPosition = firstPosition;
	this->padding = padding;
	this->brickSize = vec2(30.0, 10.0);

	// Populating bricks
	if (!bricks.empty()) bricks.clear();

	for (unsigned int i = 0; i < brickCount; i++) {
		std::cout << i << std::endl;
		// Adapt later for brick matrix
		vec2 pos = firstPosition + vec2(i * (brickSize.x * 2 + padding.x), 0.0);
		Brick brick = Brick(brickSize, pos);
		bricks.push_back(brick);
		std::cout << "Brick at pos: " << pos.x << ", " << pos.y << std::endl;
	}
}

void Level::draw(void) {
	drawBricks();
}

void Level::drawBricks(void) {
	for (unsigned int i = 0; i < bricks.size(); i++) {
		if(bricks[i].active)
			bricks[i].draw();
	}
}