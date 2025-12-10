#include "func_4.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace forlab {
	std::vector<std::string> getWords_2(const std::string& text_2) {
		const std::string punctuation = "\",.?!:()";
		const char splitter = ' ';
		const std::string vowels = "aeiouyAEIOUY";
		std::vector<std::string> words_2;
		size_t start = 0;
		size_t end = text_2.find(splitter);

		while (end != std::string::npos) {
			std::string temp = text_2.substr(start, end - start);
			for (int i = 0; i < temp.length(); ++i) {
				int count = 1;
				for (int j = i + 1; j < temp.length(); ++j) {
					if (temp[i] == temp[j]) {
						count += 1;
					}
				}
				if (count > 1) {
					for (char c : temp) {
						if (vowels.find(c) != std::string::npos) {
							temp.replace(c, 1, "");
						}
					}
					while (punctuation.find(temp[0]) != std::string::npos) {
						temp.erase(0, 1);
					}
					while (punctuation.find(temp[temp.length() - 1]) != std::string::npos) {
						temp.erase(temp.length() - 1, temp.length());
					}
					words_2.push_back(temp);
				}
				else if (count == 1) {
					while (punctuation.find(temp[0]) != std::string::npos) {
						temp.erase(0, 1);
					}
					while (punctuation.find(temp[temp.length() - 1]) != std::string::npos) {
						temp.erase(temp.length() - 1, temp.length());
					}
					words_2.push_back(temp);
				}
				count = 1;
			}
			start = end + 1;
			end = text_2.find(splitter, start);
		}
		return words_2;
	}
}