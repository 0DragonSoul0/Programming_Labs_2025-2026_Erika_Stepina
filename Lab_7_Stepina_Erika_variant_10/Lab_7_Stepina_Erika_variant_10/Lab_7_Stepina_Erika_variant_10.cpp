#include <iostream>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	//1 пункт.
	int a;
	int b;
	int c;
	std::cout << "Введите натуральные числа A, B и C:" << std::endl;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if ((a + b) % c == 0 and c % b == 0) {
		std::cout << "(A+B)/C - C/B = " << (a + b) / c - (c / b) << std::endl;
	}
	else if ((a + b) % c == 0 and c % b != 0) {
		std::cout << "(A+B)/C + B*C = " << (a + b) / c + (b * c) << std::endl;
	}
	else {
		std::cout << "A - B + C = " << a - b + c << std::endl;
	}
	//2 пункт.
	unsigned int n;
	std::cout << "Введите код товара (от 1 до 5): " << std::endl;
	std::cin >> n;
	switch(n) {
		case 1:
			std::cout << "Напиток безалкогольный негазированный 'Аква минерале Актив цитрус' со вкусом лимона; 0,5 л" << std::endl;
			break;
		case 2:
			std::cout << "Напиток безалкогольный на основе минеральной природной воды 'Липецкая-Лайт со вкусом лимона' негазированный 'Росинка'; 0,5 л" << std::endl;
			break;
		case 3:
			std::cout << "Вода минеральная природная лечебно-столовая питьевая 'Псыж', газированная; 1 л" << std::endl;
			break;
		case 4:
			std::cout << "Морс облепиховый пастеризованный 'Натурово'; 0,9 л" << std::endl;
			break;
		case 5:
			std::cout << "Морс клюквенный пастеризованный 'Натурово'; 0,9 л" << std::endl;
			break;
		default:
			std::cout << "Ошибка: такого товара не существует." << std::endl;
	}
	//3 пункт.
	short x;
	std::cout << "Введите число:" << std::endl;
	std::cin >> x;
	switch (x) {
		case -1:
			std::cout << "Negative number" << std::endl;
			break;
		case 1:
			std::cout << "Positive number" << std::endl;
			break;
		default:
			std::cout << "ERROR" << std::endl;
	}
}