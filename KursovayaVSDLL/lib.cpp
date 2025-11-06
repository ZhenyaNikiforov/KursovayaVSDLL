#include <iostream>
#include <cmath>
#include "pch.h"
#include "lib.h"

camel::camel(double speed, double timeBeforeRest, double firstRest, double secondRest){ //- конструктор верблюда
	this->speed = speed;
	this->timeBeforeRest = timeBeforeRest;
	this->firstRest = firstRest;
	this->secondRest = secondRest;
}

double camel::calcTime(double distantion) { //- расчЄт времени верблюда
	double time = distantion / this->speed; //- врем€ = рассто€ние / скорость
	if (time <= this->timeBeforeRest) { //- если врем€ меньше или равно времени до отдыха...
		return time; //- то вернуть врем€ и прервать.
	};
	if (std::fmod(time, this->timeBeforeRest) == 0) { //- если врем€ больше и делитс€ на врем€ до отдыха без остатка...
		double stops = time / this->timeBeforeRest - 1; //- то кол-во остановок это врем€/врем€ до отдыха минус послед. ост.
		return time + (stops - 1) * this->secondRest + 1 * this->firstRest;//вернуть врем€+(кол-во ост.-1)*длит.ост.+длит.1-й ост.
	}
	double stops = time / this->timeBeforeRest;//иначе кол-во ост.= врем€/врем€ до отдыха
	int intStops = static_cast<int>(stops);//кол-во ост. привести к целому числу
	return time + (intStops - 1)*this->secondRest + 1*this->firstRest;//вернуть врем.+(кол-во ост.-1)*длит.обыч.ост.+длит.1-й ост.
}

double speedCamel::calcTime(double distantion) {//-расчЄт времени быстрого верблюда;
	double time = distantion / this->speed;
	if (time <= this->timeBeforeRest) {
		return time;
	}
	if (std::fmod(time, this->timeBeforeRest) == 0) {
		double stops = time / this->timeBeforeRest - 1;
		if (stops == 1) { return time + this->firstRest; }//если остан.одна, вернуть врем€+врем.1-й остан.;
		if (stops == 2) { return time + this->firstRest + this->secondRest; }//если остан.две, вернуть врем.+врем.1.ост+врем.2.ост.;
		return time + (stops - 2)*this->nextRest + this->firstRest*1 + this->secondRest*1;//остан.с ориг.врем. вычисл.отдельно;
	}
	double stops = time / this->timeBeforeRest;
	int intStops = static_cast<int>(stops);
	if(intStops==1){return time + this->firstRest;}
	if(intStops==2){return time + this->firstRest + this->secondRest;}
	return time + (intStops-2)*this->nextRest + this->firstRest * 1 + this->secondRest * 1;
}

kentauros::kentauros(double speed, double timeBeforeRest, double firstRest) {//-конструктор кентавра;
	this->speed = speed;
	this->timeBeforeRest = timeBeforeRest;
	this->firstRest = firstRest;
}

double kentauros::calcTime(double distantion) {//расчЄт времени кентавра;
	double time = distantion / this->speed;
	if (time <= this->timeBeforeRest) {
		return time;
	};
	if (std::fmod(time, this->timeBeforeRest) == 0) {
		double stops = time / this->timeBeforeRest - 1;
		return time + stops * this->firstRest;//все остановки одинаковой длины;
	}
	double stops = time / this->timeBeforeRest;//ничего не вычитаем если остановка с концом не совпадает;
	int intStops = static_cast<int>(stops);
	return time + intStops * this->firstRest;
}

double boots::calcTime(double distantion) {
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
	return time + (intStops - 1) * this->secondRest + 1 * this->firstRest;
};

/*- ќпредел€ем врем€ орла: умножаем дистанцию на понижающий коэффициент и делим на скорость -*/
double eagle::calcTime(double distantion) {
	return distantion * 0.94 / this->speed;
}

double flyingCarpet::calcTime(double distantion) {//врем€ летающего ковра
	if (distantion < 1000) { return distantion / this->speed; }//если рассто€ние меньше 1000, без сокращ.;
	if ((distantion >= 1000) && (distantion < 5000)) { return distantion * 0.97 / this->speed; }
	if ((distantion >= 5000) && (distantion < 10000)) { return distantion * 0.9 / this->speed; }
	if (distantion >= 10000) { return distantion * 0.95 / this->speed; }
	return 0;
}

double broom::calcTime(double distantion) {//врем€ метлы
	double thousands = distantion / 1000;//сколько тыс€ч метла должна пройти
	int integerThousands = static_cast<int>(thousands);//берЄм целое кол-во тыс€ч
	double koeff = ((100 - integerThousands)*0.01);//определ€ем пониж. коэфф. на основе рассто€ни€
	return distantion * koeff / speed;//-конеч. дистанци€
}