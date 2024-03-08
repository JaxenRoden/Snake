#pragma once

// includes go below
#include <iostream>

using namespace std;

// these two lines are specific to the SFML graphics library. 
#include <SFML/Graphics.hpp>
using namespace sf;

// Constants for the game 
const float DISTANCE = 5.0f; // When the ship moves it moves 5 pixels at a time. 
const int WINDOW_WIDTH = 1000; // window is 1000 pixels wide
const int WINDOW_HEIGHT = 800; // window is 800 pixels vertically "high"

// Constants for Pixie Types
const int UNDEFINED_PIXIE = -1; // Used to determine what object the Pixie holds
const int PLAYER_SHIP_PIXIE = 0; // Used to determine what object the Pixie holds
const int PLAYER_MISSILE_PIXIE = 1; // Used to determine what object the Pixie holds
const int BACKGROUND_PIXIE = 2; // Used to determine what object the Pixie holds

class Pixie;

//class
#include "Pixie.h"

