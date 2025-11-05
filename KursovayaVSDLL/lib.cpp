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

void boots::showBoots() {
	std::cout << "skor. = " << this->speed << " vrem do ot " << this->timeBeforeRest << " ost1 " << this->firstRest << " ost2 " << this->secondRest << std::endl;
};

double boots::calcTime(double distantion) {
	std::cout << "rasstoyanie " << distantion << std::endl;
	std::cout << "skor. " << this->speed << std::endl;
	double time = distantion / this->speed;
	std::cout << "vremya " << time << std::endl;
	if (time <= this->timeBeforeRest) {
		return time;
	};
	if (std::fmod(time, this->timeBeforeRest) == 0) {
		double stops = time / this->timeBeforeRest - 1;
		return time + (stops - 1) * this->secondRest + 1 * this->firstRest;
	}
	double stops = time / this->timeBeforeRest;
	int intStops = static_cast<int>(stops);
	return time + (intStops - 1) * this->secondRest + 1 * this->firstRest;
};

/*eagle::eagle(double speed) {
	this->speed = speed;
}*/

double eagle::calcTime(double distantion) {
	std::cout << "dist: " << distantion << " speed(skor.)= " << this->speed << std::endl;
	return distantion * 0.94 / this->speed;
}

double flyingCarpet::calcTime(double distantion) {
	std::cout << "dist: " << distantion << " speed.skor= " << this->speed << std::endl;
	if (distantion < 1000) { return distantion / this->speed; }
	if ((distantion >= 1000) && (distantion < 5000)) { return distantion * 0.97 / this->speed; }
	if ((distantion >= 5000) && (distantion < 10000)) { return distantion * 0.9 / this->speed; }
	if (distantion >= 10000) { return distantion * 0.95 / this->speed; }
	return 0;
}

double broom::calcTime(double distantion) {
	std::cout << "dist: " << distantion << " skor.speed " << this->speed<<std::endl;
	double thousands = distantion / 1000;
	std::cout << "skolko tyisach: " << thousands << std::endl;
	int integerThousands = static_cast<int>(thousands);
	std::cout << "cselyie tyisyachi: " << integerThousands << std::endl;
	double koeff = ((100 - integerThousands)*0.01);
	std::cout << "koef: " << koeff << std::endl;
	return distantion * koeff / speed;
}