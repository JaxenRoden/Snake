#include "Pixie.h"

int Pixie::nextPixieID = 0;

/*
Default constructor for a pixie
* Nothing is passed in and a new pixie is made
*/
Pixie::Pixie() {
	myID = nextPixieID++;
	sprite.setPosition(0, 0);
	pixieType = UNDEFINED_PIXIE;

	nextPixie = nullptr;
	previousPixie = nullptr;
}

/* 
Constructor for a pixie
* Gets passed a file name for the texture
* Two floats for position
* and a type
*/
Pixie::Pixie(string fileName, float x, float y, int type) {
	setTextureSourceFile(fileName);
	sprite.setPosition(x, y);
	myID = nextPixieID++;
	pixieType = type;

	nextPixie = nullptr;
	previousPixie = nullptr;
}

/*
Sets the texture of the sprite
* Takes in the file name from the constructor
* If the file does not open the program stops
* Sets the texture to the sprite 
*/
void Pixie::setTextureSourceFile(string fileName) {
	if (!texture.loadFromFile(fileName)) {
		cout << "Unable to load " << fileName << endl;
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(texture);
}