#include "../include/paddle.h"

Paddle::Paddle() {
	this->position = vec2();
	this->size = vec2();
	this->color = vec4();
	this->moveSpeed = 0.0;
}

Paddle::Paddle(vec2 size, vec2 position, vec4 color, float moveSpeed) {
	this->position = position;
	this->size = size;
	this->color = color;

	this->moveSpeed = moveSpeed;
}

void Paddle::movePaddle(vec2 mousePos) {
	position.x = easeOutExpo(position.x, mousePos.x, moveSpeed * deltaTime);
}

void Paddle::reset(vec2 resetPos) {
	position.x = resetPos.x;
}

void Paddle::draw(void) {
	// Set paddle color
	glColor3f(color.x, color.y, color.z);
	// Calculating vertex positions and drawing paddle
	glBegin(GL_POLYGON);
	glVertex2f(position.x - size.x, position.y - size.y);
	glVertex2f(position.x + size.x, position.y - size.y);
	glVertex2f(position.x + size.x, position.y + size.y);
	glVertex2f(position.x - size.x, position.y + size.y);
	glEnd();
}