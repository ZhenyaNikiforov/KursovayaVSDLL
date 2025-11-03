#pragma once
#ifdef KURSOVAYAVSDLL_EXPORTS  //Макрос экспорта
#define KURSOVAYAVSDLL_API __declspec(dllexport)
#else 
#define KURSOVAYAVSDLL_API __declspec(dllimport)
#endif

#include <iostream>

class KURSOVAYAVSDLL_API camel {
public:
	camel(std::string camelName);
	std::string namePrint();
protected:
	std::string name;
};

class KURSOVAYAVSDLL_API dog {
public:
	dog(std::string dogName);
	std::string namePrint();
protected:
	std::string name;
};

class KURSOVAYAVSDLL_API cat : public dog {
public:
	cat(std::string dogName) :dog(dogName) {};
};