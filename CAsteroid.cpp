//#include "stdafx.h"
#include "CAsteroid.h"

CAsteroid::CAsteroid(int r, int l, cv::Point2f pos, cv::Point2f vel) {

	_radius = r;
	_lives = l;
	_position = pos;
	_velocity = vel;

}
