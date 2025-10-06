#include <iostream>
#include <cmath>
#include <locale.h>
#include <bitset>

int main() {
	setlocale(LC_ALL, "Russian");
	unsigned short number;
	std::cout << "1 пункт." << std::endl;
	std::cout << "Введите число от 0 до 255:" << std::endl;
	std::cin >> number;
	if (number & (1 << 0)) {
		std::cout << "Наличие основного напряжения питания: есть." << std::endl;
	}
	else {
		std::cout << "Наличие основного напряжения питания: нет." << std::endl;
	}
	if (number & (1 << 1)) {
		std::cout << "Резерв" << std::endl;
	}
	else {
		std::cout << "Резерв" << std::endl;
	}
	if (number & (1 << 2)) {
		std::cout << "Состояние двери шкафа управления: открыта." << std::endl;
	}
	else {
		std::cout << "Состояние двери шкафа управления: закрыта." << std::endl;
	}
	if (number & (1 << 3)) {
		std::cout << "Состояние выхода №1: включен." << std::endl;
	}
	else {
		std::cout << "Состояние выхода №1: отключен." << std::endl;
	}
	if (number & (1 << 4)) {
		std::cout << "Состояние выхода №2: включен." << std::endl;
	}
	else {
		std::cout << "Состояние выхода №2: отключен." << std::endl;
	}
	if (number & (1 << 5)) {
		std::cout << "Состояние резервного аккумулятора: разряжен." << std::endl;
	}
	else {
		std::cout << "Состояние резервного аккумулятора: заряжен." << std::endl;
	}
	bool error_1 = number & (1 << 6);
	bool error_2 = number & (1 << 7);
	if ((error_1 == false) & (error_2 == false)) {
		std::cout << "Нет ошибки." << std::endl;
	}
	if ((error_1 == false) & (error_2 == true)) {
		std::cout << "Ошибка: низкое входное напряжение." << std::endl;
	}
	if ((error_1 == true) & (error_2 == false)) {
		std::cout << "Ошибка: высокое входное напряжение." << std::endl;
	}
	if ((error_1 == true) & (error_2 == true)) {
		std::cout << "Резерв" << std::endl;
	}
	std::cout << "2 пункт (изменённые данные)." << std::endl;
	std::bitset<8> binary{number};
	binary = ~binary;
	unsigned short number_2 = (unsigned short)binary.to_ulong();
	if (number_2 &(1 << 0)) {
		std::cout << "Наличие основного напряжения питания: есть." << std::endl;
	}
	else {
		std::cout << "Наличие основного напряжения питания: нет." << std::endl;
	}
	if (number_2 & (1 << 1)) {
		std::cout << "Резерв" << std::endl;
	}
	else {
		std::cout << "Резерв" << std::endl;
	}
	if (number_2 & (1 << 2)) {
		std::cout << "Состояние двери шкафа управления: открыта." << std::endl;
	}
	else {
		std::cout << "Состояние двери шкафа управления: закрыта." << std::endl;
	}
	if (number_2 & (1 << 3)) {
		std::cout << "Состояние выхода №1: включен." << std::endl;
	}
	else {
		std::cout << "Состояние выхода №1: отключен." << std::endl;
	}
	if (number_2 & (1 << 4)) {
		std::cout << "Состояние выхода №2: включен." << std::endl;
	}
	else {
		std::cout << "Состояние выхода №2: отключен." << std::endl;
	}
	if (number_2 & (1 << 5)) {
		std::cout << "Состояние резервного аккумулятора: разряжен." << std::endl;
	}
	else {
		std::cout << "Состояние резервного аккумулятора: заряжен." << std::endl;
	}
	bool error_3 = number_2 & (1 << 6);
	bool error_4 = number_2 & (1 << 7);
	if ((error_3 == false) & (error_4 == false)) {
		std::cout << "Нет ошибки." << std::endl;
	}
	if ((error_3 == false) & (error_4 == true)) {
		std::cout << "Ошибка: низкое входное напряжение." << std::endl;
	}
	if ((error_3 == true) & (error_4 == false)) {
		std::cout << "Ошибка: высокое входное напряжение." << std::endl;
	}
	if ((error_3 == true) & (error_4 == true)) {
		std::cout << "Резерв" << std::endl;
	}
	return 0;
}
