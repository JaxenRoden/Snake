#include "snakeHeader.h"

void playerMovement(int movingDirection, Pixie& player) {
	if (movingDirection == UP) {
		player.move(0, -DISTANCE);
	}
	else if (movingDirection == LEFT) {
		player.move(-DISTANCE, 0);
	}
	else if (movingDirection == DOWN) {
		player.move(0, DISTANCE);
	}
	else if (movingDirection == RIGHT) {
		player.move(DISTANCE, 0 );
	}
}

int movementDirection(int direction, Pixie& player) {
	if (Keyboard::isKeyPressed(Keyboard::W))
		direction = UP;
	else if (Keyboard::isKeyPressed(Keyboard::A))
		direction = LEFT;
	else if (Keyboard::isKeyPressed(Keyboard::S))
		direction = DOWN;
	else if (Keyboard::isKeyPressed(Keyboard::D))
		direction = RIGHT;
	return direction; 
}

void snakeHeadAnimation(Pixie& player, int direction) {
	if (direction == UP)
		player.setTextureSourceFile("snakeHead.png");
	else if(direction == DOWN)
		player.setTextureSourceFile("snakeSegment.bmp");
	else if (direction == RIGHT)
		player.setTextureSourceFile("snakeHead.png");
	else if (direction == LEFT)
		player.setTextureSourceFile("snakeSegment.bmp");
}