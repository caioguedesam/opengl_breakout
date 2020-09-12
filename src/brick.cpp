#include "../include/brick.h"

Brick::Brick() {
	this->active = true;

	this->position = vec2();
	this->size = vec2();
	this->color = vec4();
}

Brick::Brick(vec2 size, vec2 position) {
	this->active = true;
	
	this->position = position;
	this->size = size;
	this->color = vec4(1.0, 1.0, 1.0, 1.0);
}

// Change this later to get bricks that resist multiple hits
void Brick::hitBrick(void) {
	destroyBrick();
}

void Brick::destroyBrick(void) {
	active = false;
}

void Brick::draw(void) {
	if (active) {
		// Set brick color
		glColor3f(color.x, color.y, color.z);
		// Calculating vertex positions and drawing brick
		glBegin(GL_POLYGON);
		glVertex2f(position.x - size.x, position.y - size.y);
		glVertex2f(position.x + size.x, position.y - size.y);
		glVertex2f(position.x + size.x, position.y + size.y);
		glVertex2f(position.x - size.x, position.y + size.y);
		glEnd();
	}
}