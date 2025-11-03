#include <iostream>
#include "pch.h"
#include "lib.h"

camel::camel(std::string camelName){
	this->name = camelName;
}

std::string camel::namePrint(){
return this->name;
}

dog::dog(std::string dogName) {
	this->name = dogName;
}

std::string dog::namePrint() {
	return this->name;
}