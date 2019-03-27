//#include "stdafx.h"
#include "CGameObject.h"
#include <cmath>

void CGameObject::move(double t) {

	_position += _velocity * t;
}

bool CGameObject::collide(CGameObject &obj) {

	distance = sqrt(pow(_position.x - obj._position.x, 2) + pow(_position.y - obj._position.y, 2));

	if (distance <= (obj._radius + _radius)) {
		return true;
	}
	else {
		return false;
	}
}

bool CGameObject::collide_wall(cv::Mat &im) {

	if (_position.x > im.size().width + _radius || _position.x < 0 - _radius || _position.y > im.size().height + _radius)
	{
		return true;
	}
	else {
		return false;
	}
}

void CGameObject::draw(cv::Mat &im, cv::Scalar colour, int thickness) {

	cv::circle(im, _position, _radius, colour, thickness, CV_AA);
}
