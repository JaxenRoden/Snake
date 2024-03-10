#pragma once
#include "snakeHeader.h"

/*
This is a wrapper class that wraps around a sprite
* It can set a texture, a scale, a position, and can draw it to the window
*/
class Pixie {
public:
	Pixie(); // Default constructor
	Pixie(string, float, float, int); // Sets each part of the Pixie
	void draw(RenderWindow& window) { window.draw(sprite); } // Draws the Pixie to the screen
	void move(float x, float y) { sprite.move(x, y); } // Moves the Pixie
	void setScale(float xScale, float yScale) { sprite.setScale(xScale, yScale); } // Sets the scale of the Pixie
	void setRotation(float angle) { sprite.setRotation(angle); } // Sets the rotation of the Pixie
	void setPosition(float x, float y) { sprite.setPosition(x, y); } // Sets the position of the Pixie
	float getX() { return sprite.getPosition().x; } // Gets the x position of the Pixie
	float getY() { return sprite.getPosition().y; } // Gets the y position of the Pixie
	Sprite getSprite() { return sprite; } // Gets the sprite that the pixie is
	Texture getTexture() { return texture; } // gets the texture that the Pixie has
	int getID() { return myID; } // Gets teh id of the Pixie
	int getType() { return pixieType; } // Gets the type of the Pixie
	Pixie* getNext() { return nextPixie; } // Gets the next Pixie being made
	Pixie* getPrevious() { return previousPixie; } // Gets the previous Pixie made
	Pixie* getSelfPointer() { return this; } // Gets the current Pixie
	void setType(int type) { pixieType = type; } // Sets the type of the Pixie
	void setX(float x) { sprite.setPosition(x, sprite.getPosition().y); } // Sets the x position of the Pixie
	void setY(float y) { sprite.setPosition(sprite.getPosition().x, y); } // Sets the y position of the Pixie
	void setTextureSourceFile(string filename); // Opens the file for the texture to get loaded into

private:
	Texture texture; // Sets the texture of the Pixie
	Sprite sprite; // Sets the Pixie as a sprite
	Pixie* nextPixie; // Pointer to the next Pixie
	Pixie* previousPixie; // Pointer to the previous Pixie
	static int nextPixieID; // Total number of Pixies
	int myID; // ID of the Pixie
	int pixieType; // Type of the Pixie
};

