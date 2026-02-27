#include <iostream>
#include <string>
#include "car.h"

void Menu() {
	std::cout << "Что хотите сделать?" << std::endl;
	std::cout << "1. Вывести полную информацию о машине" << std::endl;
	std::cout << "2. Увеличить пробег" << std::endl;
	std::cout << "3. Узнать текущий пробег" << std::endl;
	std::cout << "4. Узнать гос. номер" << std::endl;
}

int main() {
	try {
		setlocale(LC_ALL, "Russian");
		std::string br;
		std::string md;
		int year;
		std::string gn;
		int ml;

		std::cout << "Введите бренд автомобиля: ";
		std::getline(std::cin, br);
		std::cout << std::endl;
		std::cout << "Введите модель: ";
		std::getline(std::cin, md);
		std::cout << std::endl;
		std::cout << "Введите год выпуска: ";
		std::cin >> year;
		std::cout << std::endl;
		Car myCar(br, md, year, "A123AA", 15000);

		while (true) {
			Menu();
			short choice;
			std::cin >> choice;
			std::cout << std::endl;
			switch (choice) {
			case 1:
				std::cout << myCar.toString() << "\n" << std::endl;
				break;
			case 2:
				std::cout << "На сколько км хотите увеличить пробег? ";
				int km;
				std::cin >> km;
				std::cout << std::endl;
				myCar.addMileage(km);
				break;
			case 3:
				std::cout << "Текущий пробег: " << myCar.getMileage() << "\n";
				std::cout << std::endl;
				break;
			case 4:
				std::cout << "Гос. номер: " << myCar.getGovNumber() << "\n";
				std::cout << std::endl;
				break;
			}
		}
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
		return -1;
	}
	return 0;
}