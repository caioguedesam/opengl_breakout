#include "../include/game.h"

Game breakout;

void display(void) {
	breakout.display();
}

void reshape(int w, int h) {
	breakout.reshape(w, h);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(breakout.displayWidth, breakout.displayHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - breakout.displayWidth)/2, (glutGet(GLUT_SCREEN_HEIGHT) - breakout.displayHeight)/2);
	glutCreateWindow(breakout.gameTitle);

	breakout.init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;
}