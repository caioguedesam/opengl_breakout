#include "../include/game.h"

Game breakout;
Mix_Music *music = NULL;

void display(void) {
	breakout.display();
}

void reshape(int w, int h) {
	breakout.reshape(w, h);
}

void mouseMove(int x, int y) {
	breakout.mouseMove(x, y);
}

void mouseInput(int button, int buttonState, int x, int y) {
	breakout.mouseInput(button, buttonState, x, y);
}

void keyboardInput(unsigned char key, int x, int y) {
	breakout.keyboardInput(key, x, y);
}

void idle(void) {
	breakout.idle();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(breakout.displayWidth, breakout.displayHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - breakout.displayWidth)/2, (glutGet(GLUT_SCREEN_HEIGHT) - breakout.displayHeight)/2);
	glutCreateWindow(breakout.gameTitle);
	glutSetCursor(GLUT_CURSOR_NONE);

	breakout.init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMove);
	glutMouseFunc(mouseInput);
	glutKeyboardFunc(keyboardInput);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}