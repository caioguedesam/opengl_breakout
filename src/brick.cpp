#include "../include/brick.h"

std::vector<vec4> normalBrickColors = {
	vec4(0, 0.976, 0.960, 1.0f),
	vec4(0, 0.823, 1, 1.0f),
	vec4(0, 0.623, 1, 1.0f),
	vec4(0, 0.470, 1, 1.0f),
	vec4(0, 0.317, 1, 1.0f),
};

std::vector<vec4> specialBrickColors = {
	vec4(0, 1, 0.388, 1.0f),
	vec4(1, 0, 0.211, 1.0f)
};

Brick::Brick() {
	this->active = true;

	this->position = vec2();
	this->size = vec2();
	this->color = vec4();
	this->type = BrickType::BRICK_NORMAL;
	this->originalHp = 1;
	this->hp = 1;
	this->lastHitTime = 0;
}

Brick::Brick(vec2 size, vec2 position, int hp, BrickType type) {
	this->active = true;
	
	this->position = position;
	this->size = size;
	this->type = type;
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
	switch (type) {
	case BrickType::BRICK_BIG_PADDLE:
		color = specialBrickColors[0];
		break;
	case BrickType::BRICK_SMALL_PADDLE:
		color = specialBrickColors[1];
		break;
	default:
		if (hp <= 0)
			color = normalBrickColors[0];
		else if (hp > normalBrickColors.size())
			color = normalBrickColors.back();
		else {
			unsigned int index = hp - 1;
			color = normalBrickColors[index];
		}
		break;
	}
}