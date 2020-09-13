#include "../include/brick.h"

std::vector<vec4> brickColors = {
	vec4(0.333f, 0.866f, 0.447f, 1.0f),
	vec4(0.333f, 0.866f, 0.713f, 1.0f),
	vec4(0.333f, 0.803f, 0.866f, 1.0f),
	vec4(0.125f, 0.376f, 0.796f, 1.0f),
	vec4(0.247f, 0.125f, 0.796f, 1.0f),
};

Brick::Brick() {
	this->active = true;

	this->position = vec2();
	this->size = vec2();
	this->color = vec4();
	this->originalHp = 1;
	this->hp = 1;
	this->lastHitTime = 0;
}

Brick::Brick(vec2 size, vec2 position, int hp) {
	this->active = true;
	
	this->position = position;
	this->size = size;
	this->originalHp = hp;
	this->hp = originalHp;
	this->lastHitTime = 0;
	setColor();
}

bool Brick::hitBrick(void) {
	unsigned int hitTime = glutGet(GLUT_ELAPSED_TIME);
	if (hitTime - lastHitTime > 50) {
		hp--;
		setColor();
		if (hp <= 0)
			destroyBrick();

		lastHitTime = hitTime;
		return true;
	}
	return false;
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

// Sets color value based on hp value
void Brick::setColor(void) {
	if (hp <= 0)
		color = brickColors[0];
	else if (hp > brickColors.size())
		color = brickColors.back();
	else {
		unsigned int index = hp - 1;
		color = brickColors[index];
	}
}