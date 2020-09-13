#include "../include/game.h"

Game::Game() {
	state = GameState::GAME_PAUSED;
	score = 0;
	scorePosition = vec2(-350.0, -250.0);
	
	lives = 3;
	livesPosition = vec2(280.0, -250.0);
	isDead = false;
	respawnOffset = vec2(0.0, 12.0);
	respawnDirection = vec2(0.0, 1.0);

	lastTime = 0;
	deltaTime = 0.0;

	displayWidth = 800;
	displayHeight = 600;
	mousePosition = vec2(0.0, 0.0);

	paddleOrigin = vec2(0, -200);
	paddleSize = vec2(30, 5);
	paddleColor = vec4(0.6, 0.6, 0.6, 1.0);

	ballOrigin = vec2(0, -100);
	ballRadius = 5.0;
	ballColor = vec4(1.0, 1.0, 1.0, 1.0);
	ballDirection = vec2(0.0, -1.0);
	ballMaxSpeed = 200.0;
	ballMinSpeed = 100.0;

	brickMatrix = {
		{4,4,4,4,4,4,4,4,4,4,4},
		{3,3,3,3,3,3,3,3,3,3,3},
		{2,2,2,2,2,2,2,2,2,2,2},
		{1,1,1,1,1,1,1,1,1,1,1}
	};
	firstBrickPos = vec2(-320.0, 280.0);
	brickPadding = vec2(5.0, 2.0);
}

void Game::init(void) {
	initPaddle(paddleSize, paddleOrigin, paddleColor);
	initBall(ballRadius, ballOrigin, ballColor, ballDirection, ballMaxSpeed, ballMinSpeed);
	initLevel(brickMatrix, firstBrickPos, brickPadding);

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

void Game::mouseInput(int button, int buttonState, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		// On mouse left click
		if (buttonState == GLUT_DOWN) {
			if (state == GameState::GAME_PAUSED)
				play();
			else
				pause();
		}
		break;
	default:
		break;
	}
}

void Game::keyboardInput(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
		quit();
		break;
	case 'r':
		reset();
		break;
	case ' ':
		if(state == GameState::GAME_PLAYING)
			respawn();
		break;
	default:
		break;
	}
}

void Game::update(void) {
	if (state == GameState::GAME_PLAYING) {
		updateDeltaTime();
		updateCollisions();

		// Move paddle along mouse position
		paddle.movePaddle(mousePosition.x, mousePosition.y);
		ball.moveBall();
	}	
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
	else if (deltaTime > 0.5) {
		// If game is paused, prevent deltaTime from overshooting.
		deltaTime = 0.0005;
	}
	lastTime = timeElapsed;
}

void Game::updateCollisions(void) {
	ball.clampBallToScreenBounds(displayWidth, displayHeight);
	ball.checkPaddleCollision(paddle);
	if (!isDead && ball.checkDeath(paddle))
		loseLife();
	if (ball.checkBrickCollision(level))
		scorePoint();
}

void Game::idle(void) {
	// Update game logic every frame;
	update();
	// Refresh display every frame
	glutPostRedisplay();
}

void Game::scorePoint(void) {
	score++;
}

void Game::loseLife(void) {
	lives--;
	lives = clampMin(lives, 0);
	isDead = true;
}

void Game::pause(void) {
	state = GameState::GAME_PAUSED;
}

void Game::play(void) {
	state = GameState::GAME_PLAYING;
	lastTime = glutGet(GLUT_ELAPSED_TIME);
}

void Game::quit(void) {
	level.deleteAllBricks();
	exit(EXIT_SUCCESS);
}

void Game::reset(void) {
	level.reset();
	paddle.reset(paddleOrigin);
	ball.reset(ballOrigin, ballDirection);
	pause();
}

void Game::respawn(void) {
	if (isDead && lives > 0) {
		isDead = false;
		ball.reset(paddle.position + respawnOffset, respawnDirection);
	}
}

void Game::initPaddle(vec2 size, vec2 position, vec4 color) {
	paddle = Paddle(size, position, color);
}

void Game::initBall(float size, vec2 position, vec4 color, vec2 direction, float maxSpeed, float minSpeed) {
	ball = Ball(size, position, color, direction, maxSpeed, minSpeed);
}

void Game::initLevel(std::vector<std::vector<int>> brickMatrix, vec2 firstPosition, vec2 padding) {
	level = Level(brickMatrix, firstPosition, padding);
}

void Game::draw(void) {
	drawScore();
	drawLives();
	drawPaddle();
	drawBall();
	drawLevel();
}

void Game::drawPaddle(void) {
	paddle.draw();
}

void Game::drawBall(void) {
	if (isDead && lives > 0)
		ball.drawOnPosition(paddle.position + respawnOffset);
	else
		ball.draw();
}

void Game::drawLevel(void) {
	level.draw();
}

void Game::drawScore(void) {
	vec4 color = vec4(1.0, 1.0, 1.0, 1.0);
	std::string scoreString = std::to_string(score);
	scoreString = "SCORE: " + scoreString;
	//renderStrokeString(scorePosition.x, scorePosition.y, GLUT_STROKE_MONO_ROMAN, color, scoreString.c_str(), 0.1);
	renderBitmapString(scorePosition.x, scorePosition.y, GLUT_BITMAP_HELVETICA_18, color, scoreString.c_str());
}

void Game::drawLives(void) {
	vec4 color = vec4(1.0, 1.0, 1.0, 1.0);
	std::string livesString = std::to_string(lives);
	livesString = "LIVES: " + livesString;
	//renderStrokeString(scorePosition.x, scorePosition.y, GLUT_STROKE_MONO_ROMAN, color, scoreString.c_str(), 0.1);
	renderBitmapString(livesPosition.x, livesPosition.y, GLUT_BITMAP_HELVETICA_18, color, livesString.c_str());
}