#include "../include/game.h"

Game::Game() {
	displayWidth = 800;
	displayHeight = 600;
	mousePosition = vec2(0.0, 0.0);

	paddleOrigin = vec2(0, -200);
	paddleSize = vec2(30, 5);
	paddleColor = vec4(0.6, 0.6, 0.6, 1.0);
}

void Game::init(void) {
	initPaddle(paddleSize, paddleOrigin, paddleColor);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void Game::display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glutSwapBuffers();
}

void Game::reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-displayWidth/2, displayWidth/2, -displayHeight/2, displayHeight/2, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Game::mouseMove(int x, int y) {
	mousePosition.x = x - displayWidth / 2;
	mousePosition.y = -(y - displayHeight / 2);
	std::cout << mousePosition.x << ", " << mousePosition.y << std::endl;
}

void Game::update(void) {
	paddle.movePaddle(mousePosition.x, mousePosition.y);
}

void Game::draw(void) {
	drawPaddle();
}

void Game::idle(void) {
	// Update game logic every frame;
	update();
	// Refresh display every frame
	glutPostRedisplay();
}

void Game::initPaddle(vec2 size, vec2 center, vec4 color) {
	paddle = Paddle(size, center, color);
}

void Game::drawPaddle() {
	// Set paddle color
	glColor3f(paddle.color.x, paddle.color.y, paddle.color.z);
	// Calculating vertex positions and drawing paddle
	glBegin(GL_POLYGON);
	glVertex2f(paddle.center.x - paddle.size.x, paddle.center.y - paddle.size.y);
	glVertex2f(paddle.center.x + paddle.size.x, paddle.center.y - paddle.size.y);
	glVertex2f(paddle.center.x + paddle.size.x, paddle.center.y + paddle.size.y);
	glVertex2f(paddle.center.x - paddle.size.x, paddle.center.y + paddle.size.y);
	glEnd();
}