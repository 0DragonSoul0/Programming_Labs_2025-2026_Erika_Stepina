#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <vector>
#include "func_1.hpp"
#include "func_2.hpp"
#include "func_3.hpp"

int main() {
	setlocale(LC_ALL, "Russian");

	//1 пункт.

	std::string text;
	std::cout << "Исходный текст на английском языке:" << std::endl;
	std::ifstream openfile;
	openfile.open("C:\\C++ programming\\Lab_8_Stepina_Erika_variant_10\\Lab_8_Stepina_Erika_variant_10\\file_1.txt");
	if (!openfile.is_open()) {
		std::cout << "Файл не открыт." << std::endl;
		return -1;
	}
	while (!openfile.eof()) {
		std::getline(openfile, text);
		std::cout << text << std::endl;
	}
	/*std::getline(std::cin, text);*/

	std::string exceptions;
	std::cout << "Вывод слов с какими английскими буквами хотите исключить? (пишите подряд)" << std::endl;
	std::getline(std::cin, exceptions);

	size_t N;
	std::cout << "Сколько самых длинных слов (> 0) хотите вывести на экран?" << std::endl;
	std::cin >> N;

	std::vector<std::string> words = forlab::getWords(text, exceptions);
	forlab::sortWords(words);
	forlab::outUntilN(words, N);

	return 0;
}