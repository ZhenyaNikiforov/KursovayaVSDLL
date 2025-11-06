#pragma once
#ifdef KURSOVAYAVSDLL_EXPORTS  //Макрос экспорта
#define KURSOVAYAVSDLL_API __declspec(dllexport)
#else 
#define KURSOVAYAVSDLL_API __declspec(dllimport)
#endif

#include <iostream>

class KURSOVAYAVSDLL_API camel {//класс верблюда
public:
	camel(double speed = 10, double timeBeforeRest = 30, double firstRest = 5, double secondRest = 8 );//конструктор
	virtual double calcTime(double distantion);//будем переопределять в наследнике
protected://наследуемые поля
	double speed = 0;
	double timeBeforeRest = 0;
	double firstRest = 0;
	double secondRest = 0;
};

class KURSOVAYAVSDLL_API speedCamel:public camel {//наследуем скоростного верблюда от обычного
public:
	speedCamel(double speed = 40, double timeBeforeRest = 10, double firstRest = 5, double secondRest = 6.5, double nextRest = 8) : camel(speed, timeBeforeRest, firstRest, secondRest){};
	double calcTime (double distantion) override;//-переопределяем расчёт времени
protected:
	double nextRest = 8;
};

class KURSOVAYAVSDLL_API kentauros {//-класс кентавра
public:
	kentauros(double speed = 15, double timeBeforeRest = 8, double firstRest = 2);
	virtual double calcTime(double distantion);//-будем переопределять в наследнике
protected:
	double speed = 0;
	double timeBeforeRest = 0;
	double firstRest = 0;
};

class KURSOVAYAVSDLL_API boots:public kentauros {//наследуем ботинки от кентавра
public:
	boots(double speed = 6, double timeBeforeRest = 60, double firstRest = 10, double secondRest = 5):kentauros(speed, timeBeforeRest, firstRest) {};
	double calcTime(double distantion) override;//переопределяем расчёт времени
protected:
	double secondRest = 5;
};

class KURSOVAYAVSDLL_API eagle {//класс орла;
public:
	eagle(double speed = 8) {};
	virtual double calcTime(double distantion);//будем переопределять в ковре и метле;
protected:
	double speed = 8;
};

class KURSOVAYAVSDLL_API flyingCarpet :public eagle {//летающий ковёр от орла;
public:
	flyingCarpet(double speed = 10) :eagle(speed) {};
	double calcTime(double distantion) override;//переопределяем расчёт времени;
protected:
	double speed = 10;
};

class KURSOVAYAVSDLL_API broom :public eagle {//метла от орла;
public:
	broom(double speed = 20) :eagle(speed) {};
	double calcTime(double distantion) override;//переопределяем расчёт времени;
protected:
	double speed = 20;
};