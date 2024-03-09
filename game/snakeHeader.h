#pragma once

// includes go below
#include <iostream>

using namespace std;

// these two lines are specific to the SFML graphics library. 
#include <SFML/Graphics.hpp>
using namespace sf;
#include "snakeHeader.h";

// Constants for the game 
const float DISTANCE = 10.0f; // When the ship moves it moves 5 pixels at a time. 
const int WINDOW_WIDTH = 1200; // window is 1200 pixels wide
const int WINDOW_HEIGHT = 1200; // window is 1200 pixels vertically "high"

// Constants for Pixie Types
const int UNDEFINED_PIXIE = -1; // Used to determine what object the Pixie holds
const int SNAKE_HEAD_PIXIE = 0; // Used to determine what object the Pixie holds
const int SNAKE_BODY_PIXIE = 1; // Used to determine what object the Pixie holds
const int APPLE_PIXIE = 2; // Used to determine what object the Pixie holds
const int BACKGROUND_PIXIE = 3; // Used to determine what object the Pixie holds
const int UP = 1;
const int DOWN = 3;
const int LEFT = 2;
const int RIGHT = 4;
const int STATIONARY = 0;

class Pixie;



//class
#include "Pixie.h"

//functions in snakeFunctions.cpp
void playerMovement(int movingDirection, Pixie& player);
int movementDirection(int direction, Pixie& player);
void snakeHeadAnimation(Pixie& player, int direction);

