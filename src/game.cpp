#include "../include/game.h"

Game::Game() {
	lastTime = 0;
	deltaTime = 0.0;

	displayWidth = 800;
	displayHeight = 600;
	mousePosition = vec2(0.0, 0.0);

	paddleOrigin = vec2(0, -200);
	paddleSize = vec2(30, 5);
	paddleColor = vec4(0.6, 0.6, 0.6, 1.0);

	ballOrigin = vec2(0, 200);
	ballRadius = 5.0;
	ballColor = vec4(1.0, 1.0, 1.0, 1.0);
	ballDirection = vec2(0.0, -1.0);
	ballSpeed = 100.0;
}

void Game::init(void) {
	initPaddle(paddleSize, paddleOrigin, paddleColor);
	initBall(ballRadius, ballOrigin, ballColor, ballDirection, ballSpeed);

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
}

void Game::update(void) {
	// Update deltatime
	updateDeltaTime();

	// Move paddle along mouse position
	paddle.movePaddle(mousePosition.x, mousePosition.y);
	ball.moveBall();
}

void Game::updateDeltaTime(void) {
	unsigned int timeElapsed = glutGet(GLUT_ELAPSED_TIME);
	if (lastTime != 0.0) {
		// Calculates difference in milliseconds and changes deltaTime to seconds
		deltaTime = (timeElapsed - lastTime)/1000.0;
	}
	if (deltaTime < 0.001) {
		// Clamping deltaTime for precision reasons.
		deltaTime = 0.0005;
	}
	lastTime = timeElapsed;
}

void Game::draw(void) {
	drawPaddle();
	drawBall();
}

void Game::idle(void) {
	// Update game logic every frame;
	update();
	// Refresh display every frame
	glutPostRedisplay();
}

void Game::initPaddle(vec2 size, vec2 position, vec4 color) {
	paddle = Paddle(size, position, color);
}

void Game::initBall(float size, vec2 position, vec4 color, vec2 direction, float speed) {
	ball = Ball(size, position, color, direction, speed);
}

void Game::drawPaddle(void) {
	// Set paddle color
	glColor3f(paddle.color.x, paddle.color.y, paddle.color.z);
	// Calculating vertex positions and drawing paddle
	glBegin(GL_POLYGON);
	glVertex2f(paddle.position.x - paddle.size.x, paddle.position.y - paddle.size.y);
	glVertex2f(paddle.position.x + paddle.size.x, paddle.position.y - paddle.size.y);
	glVertex2f(paddle.position.x + paddle.size.x, paddle.position.y + paddle.size.y);
	glVertex2f(paddle.position.x - paddle.size.x, paddle.position.y + paddle.size.y);
	glEnd();
}

void Game::drawBall(void) {
	// Change ball to appropriate position
	glPushMatrix();
	glTranslatef(ball.position.x, ball.position.y, 0.0);

	// Set ball color
	glColor3f(ball.color.x, ball.color.y, ball.color.z);
	// Drawing ball
	glutWireSphere(ball.radius, 50, 50);

	glPopMatrix();
}