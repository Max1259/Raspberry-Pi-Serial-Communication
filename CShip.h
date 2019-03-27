#pragma once
//#include "stdafx.h"
#include "CGameObject.h"

/**
*
* @brief Creates a ship
*
* Inherits functions from CGameObject, sets ship radius and number of lives
*
* @author Max Horie
*
*/
class CShip : public CGameObject {
public:

	/**
	*
	* @brief Constructor
	*
	* @param r Sets the ship radius
	* @param l Sets the ship's number of lives
	*
	* @return nothing to return
	*
	*/
	CShip(int r, int l);
};
