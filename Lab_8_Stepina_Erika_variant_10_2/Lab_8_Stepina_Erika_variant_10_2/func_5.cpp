#include "func_5.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

namespace forlab {
	void alphabetBackwards(std::vector<std::string>& words_2) {
		std::sort(words_2.begin(), words_2.end(), std::greater<std::string>());
		for (size_t i = 0; i < words_2.size(); ++i) {
			std::cout << words_2[i] << " ";
		}
	}
}