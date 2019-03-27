//#include "stdafx.h"
#include "CMissile.h"

CMissile::CMissile(int r, int l, cv::Point2f v) {
	_radius = r;
	_lives = l;
	_velocity = v;
}
