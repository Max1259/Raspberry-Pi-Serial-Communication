//#include "stdafx.h"
#include "CAsteroidGame.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

#define FPS 60

CShip ship(10, 10);

CAsteroidGame::CAsteroidGame(string comport, cv::Size size) {

	ctrl.init();

	_canvas = cv::Mat::zeros(size, CV_8UC3);
}

void CAsteroidGame::update() {

	auto end_time = chrono::system_clock::now() + chrono::milliseconds(FPS);

	start_tic = cv::getTickCount();

	//every 6 cycles, create an asteroid and put it in the vector
	if (asteroid_counter == 6) {

		CAsteroid new_asteroid(rand() % 25 + 15, 1, cv::Point2f(rand() % _canvas.size().width, 0), cv::Point2f(rand() % 100 -50, rand() % 150 + 50));
		asteroid_vec.push_back(new_asteroid);
		asteroid_counter = 0;
	}

	//if top button is pressed, reset lives and clear vectors
	if (ctrl.get_button(33) == 0) {
		ship.set_lives(10);
		asteroid_vec.clear();
		missile_vec.clear();
	}

	//if bottom button is pressed, create a missile and put it in the vector
	ctrl.get_data(0, 32, result);
	if (result == 0) {

		CMissile new_missile(1, 1, cv::Point2f(0, -250));
		new_missile.set_pos(ship.get_pos());
		missile_vec.push_back(new_missile);
	}

	//get analog input, map it to the canvas, and set edge limits
	tie(x, y) = ctrl.get_analog();
	x = (_canvas.size().width * 1.4) * x - (_canvas.size().width / 5);

	if (x > _canvas.size().width - 13) { x = _canvas.size().width - 13; }
	if (x < 12) { x = 12; }

	y = (_canvas.size().height * 1.4) * y - (_canvas.size().height / 5);

	if (y > _canvas.size().height - 13) { y = _canvas.size().height - 13; }
	if (y < 12) { y = 12; }

	//set the ship position to the analog input
	ship.set_pos(cv::Point2f(x, y));

	//check missile/asteroid + wall collisions and missile + asteroid collisions
	for (int i = 0; i < missile_vec.size(); i++) {

		if (missile_vec[i].collide_wall(_canvas)) {

			missile_vec[i].set_lives(0);
		}

		for (int j = 0; j < asteroid_vec.size(); j++) {


			if (asteroid_vec[j].collide_wall(_canvas)) {

				asteroid_vec[j].set_lives(0);

			}
			else if (asteroid_vec[j].collide(missile_vec[i])) {

				missile_vec[i].set_lives(0);
				asteroid_vec[j].set_lives(0);
				score += 50;
			}
		}
	}

	//move missiles, erase any with 0 lives
	for (int i = 0; i < missile_vec.size(); i++) {

		missile_vec[i].move(elapsed);

		if (missile_vec[i].get_lives() == 0) {

			missile_vec.erase(missile_vec.begin() + i);
		}
	}

	//move asteroids, erase any with 0 lives, and check asteroid + ship collisions
	for (int j = 0; j < asteroid_vec.size(); j++) {

		asteroid_vec[j].move(elapsed);

		if (asteroid_vec[j].collide(ship)) {
			if (ship.get_lives() > 1) {

				ship.set_lives(ship.get_lives() - 1);
				asteroid_vec[j].set_lives(0);

			}
			else {
				ship.set_lives(10);
				asteroid_vec.clear();
				missile_vec.clear();
			}
		}

		if (asteroid_vec[j].get_lives() == 0) {

			asteroid_vec.erase(asteroid_vec.begin() + j);
		}
	}

	asteroid_counter++;

    this_thread::sleep_until(end_time);

	//check elapsed time
	elapsed = (cv::getTickCount() - start_tic) / freq;

}
void CAsteroidGame::draw() {

	_canvas = cv::Mat::zeros(_canvas.size(), CV_8UC3);

	player_lives = "LIVES:  " + std::to_string(ship.get_lives());
	player_score = "SCORE: " + std::to_string(score);

	cv::putText(_canvas, player_lives, cv::Point(10, 20), CV_FONT_HERSHEY_COMPLEX, 0.6, cv::Scalar::all(255), 1, CV_AA);
	cv::putText(_canvas, player_score, cv::Point(10, 40), CV_FONT_HERSHEY_COMPLEX, 0.6, cv::Scalar::all(255), 1, CV_AA);

	ship.draw(_canvas, cv::Scalar(235,100, 18), 1);

	for (int i = 0; i < missile_vec.size(); i++) {

		missile_vec[i].draw(_canvas, cv::Scalar::all(255), 1);
	}

	for (int j = 0; j < asteroid_vec.size(); j++) {

		asteroid_vec[j].draw(_canvas, cv::Scalar::all(255), -1);
	}

}
