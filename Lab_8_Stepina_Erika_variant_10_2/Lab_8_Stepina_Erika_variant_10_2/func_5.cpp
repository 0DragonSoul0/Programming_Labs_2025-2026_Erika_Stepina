#include "func_5.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace forlab {
	void alphabetBackwards(std::vector<std::string>& words_2) {
		std::sort(begin(words_2), end(words_2));
		for (size_t i = 0; i < words_2.size(); ++i) {
			std::cout << words_2[i] << " " << std::endl;
	}
}