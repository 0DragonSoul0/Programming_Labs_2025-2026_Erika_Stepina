#include "func_1.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace forlab {
	std::vector<std::string> getWords(const std::string& text, const std::string& exceptions) {
		const std::string punctuation = "\",.?!:()";
		const char splitter = ' ';
		std::vector<std::string> words;
		size_t start = 0;
		size_t end = text.find(splitter);
		bool isRight = true;

		while (end != std::string::npos) {
			isRight = true;
			std::string temp = text.substr(start, end - start);
			for (char c : temp) {
				if (exceptions.find(c) != std::string::npos) {
					isRight = false;
					break;
				}
			}
			if (isRight == true) {
				while (punctuation.find(temp[0]) != std::string::npos) {
					temp.erase(0, 1);
				}
				while (punctuation.find(temp[temp.length() - 1]) != std::string::npos) {
					temp.erase(temp.length() - 1, temp.length());
				}
				words.push_back(temp);
			}
			start = end + 1;
			end = text.find(splitter, start);
		}

		isRight = true;
		std::string temp = text.substr(start, end - start);
		for (char c : temp) {
			if (exceptions.find(c) != std::string::npos) {
				isRight = false;
				break;
			}
		}
		if (isRight == true) {
			while (punctuation.find(temp[0]) != std::string::npos) {
				temp.erase(0, 1);
			}
			while (punctuation.find(temp[temp.length() - 1]) != std::string::npos) {
				temp.erase(temp.length() - 1, temp.length());
			}
			words.push_back(temp);
		}
		return words;
	}
}