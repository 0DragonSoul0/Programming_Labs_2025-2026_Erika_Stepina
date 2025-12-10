#include "func_2.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace forlab {
	void sortWords(std::vector<std::string>& words) {
		size_t n = words.size();
		for (size_t i = 0; i < n - 1; ++i) {
			for (size_t j = 0; j < n - i - 1; ++j) {
				if (words[j].length() < words[j + 1].length()) {
					std::string temp = words[j];
					words[j] = words[j + 1];
					words[j + 1] = temp;
				}
			}
		}
	}
}