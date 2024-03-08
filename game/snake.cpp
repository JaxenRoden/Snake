#include "snakeHeader.h"

int main()
{
	// Create the window for graphics.
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake!");
	
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	Pixie snakeHead("snakeHead.png", 600, 600, SNAKE_HEAD_PIXIE);

	Pixie background("grass.png", 0, 0, BACKGROUND_PIXIE);
	background.setScale(2, 2);
	
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
				if (event.key.code == Keyboard::Space)
				{
					
				}
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		background.draw(window);

		snakeHead.draw(window);

		window.display();

	} // end body of animation loop

	return 0;
}