#pragma once
//#include "stdafx.h"
#include "CGameObject.h"

/**
*
* @brief Creates missiles
*
* Inherits functions from CGameObject, sets missile radius, lives, and velocity
*
* @author Max Horie
*
*/
class CMissile : public CGameObject {
public:

	/**
	*
	* @brief Constructor
	*
	* @param r Sets the missile radius
	* @param l Sets the missile's number of lives
	* @param v Sets the asteroid's velocity
	*
	* @return nothing to return
	*
	*/
	CMissile(int r, int l, cv::Point2f v);
};
