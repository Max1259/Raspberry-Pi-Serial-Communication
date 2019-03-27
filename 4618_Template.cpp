//#include "stdafx.h"

#include <string>
#include <iostream>
#include <thread>

#include "CControlPi.h"
#include "CBase4618.h"
#include "CGameObject.h"
#include "CAsteroidGame.h"

// OpenCV Include
#include <opencv2/opencv.hpp>

#define MAX_SERVO 2150
#define MIN_SERVO 500

using namespace std;

void ast();

CControlPi ctrl;

void print_menu();
void servo();

int main() {

    char command;
    int result;

    ast();
//    do {

//		print_menu();
//		ctrl.init();

//		cin >> command;

//		switch (toupper(command)) {
//
//			case 'A':
//            while (1) {
//				ctrl.get_analog();
//            }
//				break;
//
//			case 'B':
//                while(1) {
//                result = ctrl.get_button(32);
//                }//cout << "Button Test: " << result << endl;
//				break;
//
//			case 'D':
//			do {
//                ctrl.get_data(0, 32, result);
//                std::cout << result << std::endl;
//			} while (1);
//				break;
//
//			case 'S':
//				servo();
//				break;
//            case 'T':
//                ast();
//                break;
//
//			default:
//				cout << "Command unknown. Try again." << endl;
//		}
//
//	} while (command != 'Q' && command != 'q');

	return 0;
}

void print_menu()
{
	cout << "****************************************" << endl << "ELEX 4618 Lab 3: Embedded Control" << endl << "Max Horie, A01010912" << endl << "****************************************" << endl;
	cout << "(A)nalog test" << endl << "(B)utton debounce test" << endl << "(D)igital IO test" << endl << "(S)ervo Test" << endl << "(Q)uit" << endl << "As(t)eroids" << endl;
}

void servo()
{
	while (1) {

		ctrl.set_data(2, 19, MIN_SERVO);
		cout << "SERVO TEST: CH " << 19 << " 0 DEGREES" << endl;
		cv::waitKey(500);
		ctrl.set_data(2, 19, MAX_SERVO);
		cout << "SERVO TEST: CH " << 19 << " 180 DEGREES" << endl;
		cv::waitKey(500);
	}
}

void ast() {

    cv::Size size(800, 500);
    string comstring = "";
	CAsteroidGame asteroids(comstring, size);
	asteroids.run();

}
