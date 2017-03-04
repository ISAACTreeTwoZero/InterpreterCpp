#include <iostream>
#include <string>
#include "utils/StringUtils.h"
#include "utils/FileUtils.h"
#include "interpreter/Interpreter.h"

#define print(str) std::cout << str << std::endl;

std::vector<std::string> const& source = {
	"log(\"hello world\");",
	"file_create(\"sdcard/file.txt\");"
};

std::string src = "log(\"6616\");";

int main(){
	Interpreter* interpreter = new Interpreter(src);
	interpreter->setListener(new Interpreter::Listener());
	interpreter->run();
	return 0;
}
