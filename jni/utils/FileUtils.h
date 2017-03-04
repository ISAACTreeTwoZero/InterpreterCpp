#ifndef FILEUTILS_H
#define FILEUTILS_H

class FileUtils{
	public:
	
	static std::string const& read(std::string const& dir){
		std::string str;
		char line[150];
		FILE* file;
		file = fopen(dir.c_str(),"r");
		while(!feof(file)){
			fgets(line,150,file);
			str += line;
		}
		fclose(file);
		return str;
	}
	
	static bool exists(std::string const& dir){
		FILE* file;
		if((file = fopen(dir.c_str(),"r"))){
			fclose(file);
			return true;
		}
		return false;
	}
	
};

#endif
