#include "gameHeader.h"
/*
*  game.cpp
*     - A simple game loop that allows you to move the ship
*       and eventually fire a missile. 
*  AUTHOR: Most of the work in this program was completed by Prof. Andy Harbert
*          Prof. Pat Smith has made modifications (December 2021)
*
*/   

int main()
{
	// Create the window for graphics. 
	//  The "aliens" is the text in the title bar on the window. 
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.

	// a Texture is an image of pixels. You can load a .png file
	//   or a bitmap file.  These files are in the "Resource files" section of
	//   the solution explorer. 
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// We use the star texture as a background for space in the window.
	//  it makes it more interesting. :)
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	// An alien bitmap is provided in the Resource Files... 
	//  Perhaps you'll want to make your own alien though...

	// Sets the missle texture
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.bmp")) {
		cout << "Unable to load missle texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// Sets the alien texture
	Texture alienTexture;
	if (!alienTexture.loadFromFile("alien.bmp")) {
		cout << "Unable to load alien texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background; // the background is a sprite, though we'll never move it around. 
	background.setTexture(starsTexture); // load the starsTexture object into the sprite.
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);

	// *** You will have to code to load the  texture for the missile here. 
	// Then create the missile Sprite...  

	// initial position of the ship will be approx middle of screen
	ship.setPosition(500, 700);
 
	// creates the  missle sprite
	Sprite missile, alien1Missile;
	missile.setTexture(missileTexture);
	alien1Missile.setTexture(missileTexture);
	alien1Missile.setRotation(180);

	// creates each alien sprite
	Sprite alien1;
	alien1.setTexture(alienTexture);

	// Sets the initial spot of each alien
	alien1.setPosition(900, 5);

	// For first alien
	bool alienOneMovingLeft = true; // For movement of alien
	bool alienOneMovingRight = false; // For alien movement

	bool isMissileInFlight = false; // for firing missile

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		// This while loop checks to see if anything happened since last time
		// we drew the window and all its graphics. 
		while (window.pollEvent(event))
		{	
			if (event.type == Event::Closed) // Did the user kill the window by pressing the "X"?
				window.close();
			else if (event.type == Event::KeyPressed) // did the user press a key on the keyboard?
			{
				if (event.key.code == Keyboard::Space && !isMissileInFlight)
				{
					isMissileInFlight = true;
					// You add the code to initialize missile position
					//  You should have created a missile sprite 
					// above the main loop, maybe around line 60? 
					missile.setPosition(ship.getPosition().x + 16, ship.getPosition().y - 30);
				}
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		//detect key presses to update the position of the ship. 
		//See moveShip() function above.
		moveShip(ship);

		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		window.draw(ship);

		//Alien moving left and right for lab
		if (alienOneMovingLeft) {
			moveAlienLeft(alien1);
			window.draw(alien1);
			if (alien1.getPosition().x < 5) {
				alienOneMovingLeft = false;
				alienOneMovingRight = true;
			}
		}
		else if (alienOneMovingRight) {
			moveAlienRight(alien1);
			window.draw(alien1);
			if (alien1.getPosition().x > 900) {
				alienOneMovingRight = false;
				alienOneMovingLeft = true;
			}
		}

		// Handles a missile in flight
		if (isMissileInFlight)
		{
			window.draw(missile);
			missile.move(0, -15);
			if (missile.getPosition().y < 0) {
				isMissileInFlight = false;
				missile.setPosition(1000, 1000);
			}
		}

		FloatRect missileBounds = missile.getGlobalBounds();
		FloatRect alienBounds = alien1.getGlobalBounds();
		if (missileBounds.intersects(alienBounds) && isMissileInFlight)
		{
			isMissileInFlight = false;
			missile.setPosition(1500, 1500);
			cout << "Hit" << endl;
		}

		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

/* Write Later
when is copy constructor called
1) creating a new object, using an existing one
2) anytime you pass an object by value
Therefor pass all objects by ref! use "const"
*/