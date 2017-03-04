#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>
#include <sstream>

class StringUtils{
	private:
	std::string data;
	std::string currentIndexOf;
	public:
	
	~StringUtils();
	StringUtils(std::string const& data);
	std::vector<std::string> const& split(std::string const& delimiter);
	std::size_t indexOf(std::string const& input);
	bool contains(std::string const& input);
	//std::string const& substring(std::size_t x,std::size_t y);
	std::string const& substring(std::string const& x,std::string const& y);
	std::string const& replace(std::string const& input,std::string const& output);
	
	template <class T>
	static std::string const& toString(T const& object){
		std::stringstream ss;
    	ss << object;
    	return ss.str();
	}
};

#endif
