#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <vector>

int main() {
	setlocale(LC_ALL, "Russian");

	//3 пункт.

	std::string text;
	std::cout << "Исходный текст на английском языке:" << std::endl;
	std::ifstream openfile;
	openfile.open("C:\\C++ programming\\Lab_8_Stepina_Erika_variant_10_3\\Lab_8_Stepina_Erika_variant_10_3\\input.txt");
	if (!openfile.is_open()) {
		std::cout << "Файл не открыт." << std::endl;
		return -1;
	}
	while (!openfile.eof()) {
		std::getline(openfile, text);
		std::cout << text << std::endl;
	}

	return 0;
}