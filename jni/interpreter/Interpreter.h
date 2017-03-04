#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>
#include <map>
#include "utils/StringUtils.h"
#include "./Parameter.h"

class Interpreter{
	public:
	class Listener{
		public:
		Interpreter* interpreter;
		
		virtual void onRun(int line,std::string const& data);
	};
	
	enum ObjectType : int{
		System,File
	};
	
	private:
	std::map<std::string,std::string> var_value;
	std::map<std::string,ObjectType> var_type;
	std::map<std::string,std::string> func_value;
	std::map<std::string,ObjectType> func_type;
	std::map<std::string,std::string> func_data;
	
	StringUtils* strutils;
	std::string data;
	std::vector<std::string> functions;	
	Listener* listener;
	
	public:
	~Interpreter();
	Interpreter(std::string const& data);
	void run();
	bool isParameter(int line);
	Parameter* getParameter(int line);
	int length();
	std::string const& getData(int line);
	std::string const& getData();
	void addFunction(std::string const& function);
	void removeFunction(std::string const& function);
	bool isFunction(int line);
	std::string const& getFunction(int line);
	bool containsFunction(std::string const& function);
	
	void setListener(Listener* listener){
		listener->interpreter = this;
		this->listener = listener;
	}
	
	StringUtils* getStringUtils(){
		if(this->strutils==NULL){
	    	return (this->strutils = new StringUtils(this->data));
		}else{
			return this->strutils;
		}
	}
	
};

#endif
