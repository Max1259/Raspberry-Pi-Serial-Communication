#pragma once

//#include "stdafx.h"
#include "CBase4618.h"
#include "CMissile.h"
#include "CAsteroid.h"
#include "CGameObject.h"
#include "CShip.h"
#include <string>
#include <vector>

/**
*
* @brief Controls functions for the asteroid game
*
* Inherits update/draw functions from CBase4618, also initializes the comport and canvas
*
* @author Max Horie
*
*/
class CAsteroidGame : public CBase4618 {
protected:

	double freq = cv::getTickFrequency();///< Holds the frequency for timing calcs
	double elapsed = 0;///< Holds the elapsed time to allow objects to move
	double start_tic;///< Holds the start time
	vector <CGameObject> missile_vec;///< A vector to hold the missiles
	vector <CGameObject> asteroid_vec;///< A vector to hold the asteroids
	int asteroid_counter = 0;///< Counter for asteroid spawning
	string player_lives;///< String to print lives to the canvas
	string player_score;
	int result;///< result of button press
	int score = 0;

public:

	/**
	*
	* @brief Constructor
	*
	* @param comport The com port to initialize
	* @param size The size of the canvas
	*
	* @return nothing to return
	*
	*/
	CAsteroidGame(string comport, cv::Size size);

	/**
	*
	* @brief Function to update object parameters
	*
	* @param none
	*
	* @return nothing to return
	*
	*/
	void update();

	/**
	*
	* @brief Function to output objects and text to the canvas
	*
	* @param none
	*
	* @return nothing to return
	*
	*/
	void draw();
};
