#include "../include/level.h"

Level::Level() {
	this->firstPosition = vec2();
	this->padding = vec2();
	this->brickSize = vec2();
}

Level::Level(std::vector<std::vector<int>> brickMatrix, vec2 firstPosition, vec2 padding) {
	this->bricks = std::vector<Brick*>();
	this->firstPosition = firstPosition;
	this->padding = padding;
	this->brickSize = vec2(30.0, 10.0);

	// Populating bricks
	if (!bricks.empty()) bricks.clear();

	for (unsigned int i = 0; i < brickMatrix.size(); i++) {
		for (unsigned int j = 0; j < brickMatrix[i].size(); j++) {
			// Create brick on position if matrix content is not 0 or lower
			if (brickMatrix[i][j] > 0) {
				vec2 pos = firstPosition + vec2(j * (brickSize.x * 2 + padding.x), i * (-brickSize.y * 2 - padding.y));
				Brick* brick = new Brick(brickSize, pos, brickMatrix[i][j]);
				bricks.push_back(brick);
			}
		}
	}
}

void Level::draw(void) {
	drawBricks();
}

void Level::drawBricks(void) {
	for (unsigned int i = 0; i < bricks.size(); i++) {
		bricks[i]->draw();
	}
}

void Level::reset(void) {
	// Reactivates all bricks in brick list
	std::vector<Brick*>::iterator it;
	for (it = bricks.begin(); it != bricks.end(); it++) {
		(*it)->active = true;
	}
}

void Level::deleteAllBricks(void) {
	std::vector<Brick*>::iterator it;
	for (it = bricks.begin(); it != bricks.end(); ) {
		delete (*it);
		it = bricks.erase(it);
	}
}

void Level::displayBrickStats(void) {
	std::vector<Brick*>::iterator it;
	for (it = bricks.begin(); it != bricks.end(); it++) {
		if ((*it)->active) {
			int index = it - bricks.begin();
			std::cout << "	Brick " << index << " (" << (*it)->hp << "HP), at position (" 
				<< (*it)->position.x << ", " << (*it)->position.y << ")" << std::endl;
		}
	}
}