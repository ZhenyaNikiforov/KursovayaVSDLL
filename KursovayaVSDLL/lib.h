#pragma once
#ifdef KURSOVAYAVSDLL_EXPORTS  //Макрос экспорта
#define KURSOVAYAVSDLL_API __declspec(dllexport)
#else 
#define KURSOVAYAVSDLL_API __declspec(dllimport)
#endif

#include <iostream>

class KURSOVAYAVSDLL_API camel {
public:
	camel(double speed = 10, double timeBeforeRest = 30, double firstRest = 5, double secondRest = 8 );
	virtual double calcTime(double distantion);
protected:
	double speed = 0;
	double timeBeforeRest = 0;
	double firstRest = 0;
	double secondRest = 0;
};

class KURSOVAYAVSDLL_API speedCamel:public camel {
public:
	speedCamel(double speed = 40, double timeBeforeRest = 10, double firstRest = 5, double secondRest = 6.5, double nextRest = 8) : camel(speed, timeBeforeRest, firstRest, secondRest){};
	double calcTime (double distantion) override;
protected:
	double nextRest = 8;
};

class KURSOVAYAVSDLL_API kentauros {
public:
	kentauros(double speed = 15, double timeBeforeRest = 8, double firstRest = 2);
	virtual double calcTime(double distantion);
protected:
	double speed = 0;
	double timeBeforeRest = 0;
	double firstRest = 0;
};

class KURSOVAYAVSDLL_API boots:public kentauros {
public:
	boots(double speed = 6, double timeBeforeRest = 60, double firstRest = 10, double secondRest = 5):kentauros(speed, timeBeforeRest, firstRest) {};
	void showBoots();
	double calcTime(double distantion) override;
protected:
	double secondRest = 5;
};

class KURSOVAYAVSDLL_API eagle {
public:
	eagle(double speed = 8) {};
	virtual double calcTime(double distantion);
protected:
	double speed = 8;
};

class KURSOVAYAVSDLL_API flyingCarpet :public eagle {
public:
	flyingCarpet(double speed = 10) :eagle(speed) {};
	double calcTime(double distantion) override;
protected:
	double speed = 10;
};

class KURSOVAYAVSDLL_API broom :public eagle {
public:
	broom(double speed = 20) :eagle(speed) {};
	double calcTime(double distantion) override;
protected:
	double speed = 20;
};