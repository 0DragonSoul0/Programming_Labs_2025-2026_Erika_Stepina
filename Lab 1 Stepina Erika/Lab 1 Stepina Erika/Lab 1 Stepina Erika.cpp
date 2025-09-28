#include <iostream>
#include <cmath>
#include <locale.h>
// Переменная - область памяти, которой присваивается имя и в которой хранится некоторое значение.

using namespace::std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Типы данных:" << endl;
	cout << "Целочисленные данные:" << endl;
	cout << "signed char - 1 байт, мин. -128 макс. 127;" << endl;
	cout << "unsigned char - 1 байт, мин. 0 макс. 255;" << endl;
	cout << "char - 1 байт, мин. -128 макс. 127, либо мин. 0 макс. 255 (может представлять как signed char, так и unsigned char, в зависимости от компилятора);" << endl;
	cout << "short (short int/signed short int/signed short) - 2 байта, мин. -32768 макс. 32767;" << endl;
	cout << "unsigned short (unsigned short int) - 2 байта, мин. 0 макс. 65535;" << endl;
	cout << "int (signed int/signed) - 2 байта или 4 байта (в зависимости от архитектуры процессора), мин. -32768 макс. 32767 (при 2 байтах), мин. -2 147 483 648 макс. 2 147 483 647 (при 4 байтах);" << endl;
	cout << "unsigned int (unsigned) - 2 байта или 4 байта, мин. 0 макс. 65535 (2 байта), мин. 0 макс. 4 294 967 295 (4 байта);" << endl;
	cout << "long (long int/signed long int/signed long) - 4 или 8 байт в зависимости от архитектуры, мин. -2 147 483 648 макс. 2 147 483 647 (4 байта), мин. -9 223 372 036 854 775 808 макс. 9 223 372 036 854 775 807 (8 байт);" << endl;
	cout << "unsigned long (usigned long int) - 4 байта, мин. 0 макс. 4 294 967 295;" << endl;
	cout << "long long (long long int/signed long long int/signed long long) - 8 байт, мин. -9 223 372 036 854 775 808 макс. 9 223 372 036 854 775 807;" << endl;
	cout << "unsigned long long (unsigned long long int) - 8 байт, мин. 0 макс. 18 446 744 073 709 551 615;" << endl;
	cout << "Пример арифметической операции: ";
	signed char x = -128;
	unsigned char y = 255;
	cout << "-128 + 255 = " << x + y << endl;
	cout << "Вещественные данные:" << endl;
	cout << "float - 4 байта, мин +/- 3.4E - 38 макс. 3.4E + 38" << endl;
	cout << "double - 8 байт, мин. +/- 1.7E - 308, макс. 1.7E + 308" << endl;
	cout << "long double - 8 байт, в зависимости от размера занимаемой памяти может отличаться диапазон допустимых значений" << endl;
	cout << "Пример арифметической операции: ";
	float m = 1.1;
	double w = 1.01;
	cout << "1.1 - 1.01 = " << m - w << endl;
	cout << "Символьные данные:" << endl;
	cout << "char - 1 символ в кодировке ASCII, 1 байт, мин. -128 макс. 127, либо мин. 0 макс. 255" << endl;
	cout << "wchar_t - расширенный символ, 2 байта (на Windows), либо 4 байта (на Linux), мин. 0 макс. 65535 (2 байта), мин. 0 макс. 4 294 967 295 (4 байта)" << endl;
	cout << "char8_t - 1 символ в кодировке Unicode, 1 байт, мин. 0 макс. 256" << endl;
	cout << "char16_t - 1 символ в кодировке Unicode, 2 байта, мин. 0 макс. 65535" << endl;
	cout << "char32_t - 1 символ в кодировке Unicode, 4 байта, мин. 0 макс. 4 294 967 295" << endl;
	cout << "Пример арифметической операции: ";
	char z = 25;
	char n = -5;
	cout << "25 : (-5) = " << z / n << endl;
	cout << "Логические типы:" << endl;
	cout << "bool - 1 байт, хранит одно из двух значений: true (1) или false (0)" << endl;
	cout << "Пример логической операции: " << endl;
	bool resultF = 1 > 2;
	cout << "1 > 2 " << resultF << " - ложь" << endl;
	bool resultT = 3 < 4;
	cout << "3 < 4 " << resultT << " - истина" << endl;
	return 0;
}
