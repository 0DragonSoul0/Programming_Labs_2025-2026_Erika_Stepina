#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <vector>
#include "func_4.hpp"
#include "func_5.hpp"

int main() {
	setlocale(LC_ALL, "Russian");

	//2 пункт.

	std::string text_2;
	std::cout << "Введите текст на английском языке:" << std::endl;
	std::getline(std::cin, text_2);

	std::vector<std::string> words_2 = forlab::getWords_2(text_2);
	forlab::alphabetBackwards(words_2);

	//for (size_t i = 0; i < words_2.size(); ++i) {
		//std::cout << words_2[i] << " " << std::endl;

	return 0;
}