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

double speedCamel::calcTime(double distantion) {
	std::cout<<"distantion = "<<distantion<<std::endl;
	std::cout << "skorost = " << this->speed << std::endl;
	double time = distantion / this->speed;
	std::cout << "vremya = " << time << std::endl;
	std::cout << "vremya do otd. = " << this->timeBeforeRest << std::endl;
	std::cout << "1-otd " << this->firstRest << " vtor-otd " << this->secondRest << " tret-otd " << this->nextRest << std::endl;
	if (time <= this->timeBeforeRest) {
		return time;
	}
	if (std::fmod(time, this->timeBeforeRest) == 0) {
		double stops = time / this->timeBeforeRest - 1;
		if (stops == 1) { return time + this->firstRest; }
		if (stops == 2) { return time + this->firstRest + this->secondRest; }
		return time + (stops - 2)*this->nextRest + this->firstRest*1 + this->secondRest*1;
	}
	double stops = time / this->timeBeforeRest;
	int intStops = static_cast<int>(stops);
	if(intStops==1){return time + this->firstRest;}
	if(intStops==2){return time + this->firstRest + this->secondRest;}
	return time + (intStops-2)*this->nextRest + this->firstRest * 1 + this->secondRest * 1;
}

kentauros::kentauros(double speed, double timeBeforeRest, double firstRest) {
	this->speed = speed;
	this->timeBeforeRest = timeBeforeRest;
	this->firstRest = firstRest;
}

double kentauros::calcTime(double distantion) {
	std::cout << "Eto metod calcTime kentauros!" << std::endl;
	std::cout << "distantion = " << distantion << std::endl;
	std::cout << "speed = " << this->speed << std::endl;
	double time = distantion / this->speed;
	std::cout << "obshee vremya = " << time << std::endl;
	if (time <= this->timeBeforeRest) {
		return time;
	};
	if (std::fmod(time, this->timeBeforeRest) == 0) {
		double stops = time / this->timeBeforeRest - 1;
		return time + stops * this->firstRest;
	}
	double stops = time / this->timeBeforeRest;
	int intStops = static_cast<int>(stops);
	return time + intStops * this->firstRest;
}