#include <iostream>
#include <cmath>
#include "pch.h"
#include "lib.h"

camel::camel(double speed, double timeBeforeRest, double firstRest, double secondRest){
	this->speed = speed;
	this->timeBeforeRest = timeBeforeRest;
	this->firstRest = firstRest;
	this->secondRest = secondRest;
}

double camel::calcTime(double distantion) {
	double time = distantion / this->speed;
	if (time <= this->timeBeforeRest) {
		return time;
	};
	if (std::fmod(time, this->timeBeforeRest) == 0) {
		double stops = time / this->timeBeforeRest - 1;
		return time + (stops - 1) * this->secondRest + 1 * this->firstRest;
	}
	double stops = time / this->timeBeforeRest;
	int intStops = static_cast<int>(stops);
	return time + (intStops - 1)*this->secondRest + 1*this->firstRest;
}