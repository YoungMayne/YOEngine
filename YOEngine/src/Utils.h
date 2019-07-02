#pragma once


#include <fstream>
#include <string>

#include "Types.h"


namespace YOEngine {


	inline std::string readFile(const std::string& path) {
		return std::string(std::istreambuf_iterator<char>(std::ifstream(path.c_str()).rdbuf()), std::istreambuf_iterator<char>());
	}


}