#pragma once
//#include "stdafx.h"
#include "CGameObject.h"

/**
*
* @brief Creates asteroids
*
* Inherits functions from CGameObject, sets asteroid radius, lives, position and velocity
*
* @author Max Horie
*
*/
class CAsteroid : public CGameObject {
public:

	/**
	*
	* @brief Constructor
	*
	* @param r Sets the asteroid radius
	* @param l Sets the asteroid's number of lives
	* @param pos Sets the asteroid's initial position
	* @param vel Sets the asteroid's velocity
	*
	* @return nothing to return
	*
	*/
	CAsteroid(int r, int l, cv::Point2f pos, cv::Point2f vel);
};
