#include <iostream>
#include <algorithm>
#include "./StringUtils.h"

StringUtils::StringUtils(std::string const& data){
	this->data = data;
}

StringUtils::~StringUtils(){
	
}

/*
  @link https://github.com/ekg/split
  @author @ekg
  @type Method
  @return vector with all contents string by delimiter
  @string data to be delimited
  @string delimiter using whatever character
*/

std::vector<std::string> const& StringUtils::split(std::string const& delimiter){
	std::vector<std::string>& vecstr = *new std::vector<std::string>();
	char* tok;
	char cchars [this->data.size()+1];
	char* cstr = &cchars[0];
	strcpy(cstr, this->data.c_str());
	tok = strtok(cstr,delimiter.c_str());
	while(tok!=NULL){
		vecstr.push_back(tok);
		tok = strtok(NULL, delimiter.c_str());
	}
	return vecstr;
}

std::size_t StringUtils::indexOf(std::string const& input){
	this->currentIndexOf = input;
	return this->data.find(input);
}

bool StringUtils::contains(std::string const& input){
	return this->data.find(input)!=std::string::npos;
}

/*
std::string const& StringUtils::substring(std::size_t x,std::size_t y){
	StringUtils* stru = new StringUtils(this->data.substr(x,y));
	stru->replace("(","");//temporary
	stru->replace(")","");//temporary
	std::string data = stru->replace(";","");//temporary
	delete stru;
	return data;
	
}*/


std::string const& StringUtils::substring(std::string const& x,std::string const& y){
	std::string result = this->data.substr(this->indexOf(x)+1,this->indexOf(y));
	result.resize(result.length()-y.length());
	return result;
	
}

std::string const& StringUtils::replace(std::string const& input,std::string const& output){
	std::replace(this->data.begin(),this->data.end(),*input.c_str(),*output.c_str());
	return this->data;
}
