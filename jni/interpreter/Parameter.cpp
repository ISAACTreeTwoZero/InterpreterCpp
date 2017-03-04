#include "./Parameter.h"
#include "utils/StringUtils.h"

Parameter::Parameter(std::string const& data){
	this->data = data;
}

bool Parameter::hasNumeric(int index){
	//TODO: implement this method
	return false;
}

bool Parameter::hasAlphabetic(int index){
	//TODO: implement this method
	return false;
}

bool Parameter::hasExpression(int index){
	//TODO: implement this method
	return false;
}

bool Parameter::hasString(int index){
	StringUtils* stru = new StringUtils(this->getArg(index));
	bool hasString1 = stru->contains("\"")==true;
	bool hasString2 = stru->contains("'")==true;
	delete stru;
	if(hasString1) 
		return true;
	else if(hasString2) 
		return true;
	return false;
}


bool Parameter::hasVariable(int index){
	//TODO: implement this method
	return false;
}

bool Parameter::hasFunction(int index){
	//TODO: implement this method
	return false;
}

std::string Parameter::getString(int index){
	StringUtils*stru = new StringUtils(this->getArg(index));
	stru->replace("\"","");
	std::string result = stru->replace("'","");
	delete stru;
	return result;
}

std::string Parameter::getArg(int index){
	StringUtils* stru = new StringUtils(this->data);
	std::string result = stru->split(",")[index];
	delete stru;
	return result;
}

/*
int Parameter::length(){
	return 0;
}*/
