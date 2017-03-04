#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>
#include <vector>

class Parameter{
	private:
	std::string data;
	
	public:
	~Parameter();
	Parameter(std::string const& data);
	
	bool hasNumeric(int index);
	bool hasAlphabetic(int index);
	bool hasExpression(int index);
	bool hasString(int index);
	bool hasVariable(int index);
    bool hasFunction(int index);
	std::string const& getData();
	std::string getString(int index);
	std::string getArg(int index);
	//std::vector<std::string> const& getArgs();
	//int length();

};

#endif
