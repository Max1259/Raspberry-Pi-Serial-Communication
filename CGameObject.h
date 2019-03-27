#pragma once
#include "CBase4618.h"

/**
*
* @brief Controls objectts for asteroid game
*
* Controls collisions, movement, ship/asteroid/missile drawing, and holds parameters for the objects
*
* @author Max Horie
*
*/
class CGameObject {
protected:

	cv::Point2f _position;///< Position of object
	cv::Point2f _velocity;///< Velocity of object
	int _radius;///< Object radius
	int _lives;///< Object lives
	int distance;///< Distance between the center of two objects

public:
	/**
	*
	* @brief Allows object movement
	*
	* @param t Elapsed time since last movement
	*
	* @return nothing to return
	*
	*/
	void move(double t);

	/**
	*
	* @brief Detects collisions between objects
	*
	* @param obj The obj to be compared to the one calling the function
	*
	* @return True if collision has occured
	*
	*/
	bool collide(CGameObject &obj);

	/**
	*
	* @brief Detects wall collisions
	*
	* @param im The canvas to work on
	*
	* @return True if collision has occured
	*
	*/
	bool collide_wall(cv::Mat &im);

	/**
	*
	* @brief Accesses an object's lives
	*
	* @param none
	*
	* @return Number of lives
	*
	*/
	int get_lives() { return _lives; }

	/**
	*
	* @brief Sets the object's lives
	*
	* @param lives The number of lives to give the object
	*
	* @return nothing to return
	*
	*/
	void set_lives(int lives) { _lives = lives; }

	/**
	*
	* @brief Sets the object's position
	*
	* @param pos The position to set the object to
	*
	* @return nothing to return
	*
	*/
	void set_pos(cv::Point2f pos) { _position = pos; }

	/**
	*
	* @brief Gets the object's position
	*
	* @param none
	*
	* @return nothing to return
	*
	*/
	cv::Point2f get_pos() { return _position; }

	/**
	*
	* @brief Draws an object
	*
	* @param im The canvas to draw on
	*
	* @return nothing to return
	*
	*/
	void draw(cv::Mat &im, cv::Scalar colour, int thickness);
};