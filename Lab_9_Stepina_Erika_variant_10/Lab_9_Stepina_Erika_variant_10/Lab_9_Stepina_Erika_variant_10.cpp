#include <iostream>
#include <locale.h>

int main() {
	//1 способ

	setlocale(LC_ALL, "Russian");
	long long number;
	std::cout << "Введите желаемое число типа long long:" << std::endl;
	std::cin >> number;
	long long* pointer = &number;
	std::cout << "Содержимое байтов числа:" << std::endl;
	for (int i = 0; i < sizeof(number); ++i) {
		unsigned char byte = *(((unsigned char*)pointer) + i);
		int c = byte;
		std::cout << c << " ";
	}
	return 0;

	//2 способ.

	/*long long number;
	std::cout << "Введите желаемое число типа long long:" << std::endl;
	std::cin >> number;
	unsigned char* pointer = (unsigned char*) &number;
	for (int i = 0; i < sizeof(number); ++i) {
		int byte = *(pointer + i);
		std::cout << byte << " ";
	}
	return 0;*/
}
