#include "gameHeader.h"
/*
*  gameFunctions.cpp
*     - The functions for the game program are in this file. 
* 
*  AUTHOR: Most of the work in this program was completed by Prof. Andy Harbert
*          Prof. Pat Smith has made modifications (December 2021)
*
*/

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen

/*
*  moveShip - This function is called to handle a keyPress event. 
*     Keyboard input is detected and ship is moved.
*   ** Part of the lab is to also handle firing a missile **
*  INPUT: The ship sprite is passed.  This merely a drawn object on the screen.
*  RETURN: None
*/
void moveShip(Sprite& ship)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		// left arrow is pressed: move our ship left 5 pixels ( this is -5 pixels to go left)
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {

		ship.move(0, -DISTANCE);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {

		ship.move(0, DISTANCE);
	}

	int locationX = static_cast<int>(ship.getPosition().x);
	int locationY = static_cast<int>(ship.getPosition().y);

	// Doesn't let the ship go off the screen
	if (locationX < 5) {
		ship.setPosition(5, locationY);
	}
	else if (locationX > WINDOW_WIDTH - 50) {
		ship.setPosition(WINDOW_WIDTH - 50, locationY);
	}
	// Keeps the ship in the lower 20% of the screen
	if (locationY < WINDOW_HEIGHT * .8) {
		ship.setPosition(locationX, WINDOW_HEIGHT * .8);
	}
	else if (locationY > WINDOW_HEIGHT - 50) {
		ship.setPosition(locationX, WINDOW_HEIGHT - 50);
	}
}

// Moves each alien left
void moveAlienLeft(Sprite& alien) {
	alien.move(-10, 0);
}

// Moves each alien right
void moveAlienRight(Sprite& alien) {
	alien.move(10, 0);
}