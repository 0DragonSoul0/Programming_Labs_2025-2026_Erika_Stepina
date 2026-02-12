#include <iostream>
#include <string>
#include <locale.h>

class Car {
private:
	std::string brand;
	std::string model;
	std::string number;
	std::string govNumber;
	double mileage;

public:
	Car() {
		brand = "неизвестен";
		model = "неизвестна";
		number = "-";
		govNumber = "A000AA";
		mileage = 0.0;
	}

	Car(std::string br, std::string mod, std::string n, std::string gn, double ml) {
		brand = br;
		model = mod;
		number = n;
		mileage = ml;
		if (!setGovNumber(gn)) {
			govNumber = "ERROR";
		}
	}

	Car(const Car& other) {
		brand = other.brand;
		model = other.model;
		number = other.number;
		govNumber = other.govNumber;
		mileage = other.mileage;
		std::cout << "Запущен конструктор копирования." << std::endl;
	}

	~Car() {
		std::cout << "Запущен деструктор: " << brand << " " << model << std::endl;
	}

	bool setGovNumber(std::string gn) {
		if (gn.length() != 6) {
			std::cout << "Ошибка: гос. номер должен состоять из 6 символов" << std::endl;
			return false;
		}

		bool isValid = isalpha(gn[0]) and isdigit(gn[1]) and isdigit(gn[2]) and isdigit(gn[3]) and isalpha(gn[4]) and isalpha(gn[5]);

		if (isValid) {
			govNumber = gn;
			return true;
		}
		else {
			std::cout << "Ошибка: недействительный гос. номер" << std::endl;
			return false;
		}
	}

	bool setNumber(std::string n) {
		bool validSymbolsInNumber;
		bool validNumber = !n.empty() and n.length() == 17;
		const std::string validSymbols = "0123456789QWERTYUIOPASDFGHJKLZXCVBNM";
		for (char c : n) {
			if (validSymbols.find(c) != std::string::npos) {
				validSymbolsInNumber = true;
			}
			else {
				validSymbolsInNumber = false;
			}
		}
		if (validNumber and validSymbolsInNumber) {
			number = n;
			return true;
		}

		else {
			std::cout << "Ошибка: некорректный номер кузова" << std::endl;
			return false;
		}
	}

	std::string getBrand() const {
		return brand;
	}
	std::string getModel() const {
		return model;
	}
	std::string getNumber() const {
		return number;
	}
	std::string getGovNumber() const {
		return govNumber;
	}
	double getMileage() const {
		return mileage;
	}

	void printInfo() const {
		std::cout << "Марка: " << brand << std::endl;
		std::cout << "Модель: " << model << std::endl;
		std::cout << "Номер кузова: " << number << std::endl;
		std::cout << "Гос. номер: " << govNumber << std::endl;
		std::cout << "Пробег: " << mileage << " км" << std::endl;
	}

	void rollbackMileage(double x) {
		if (x < 0) {
			std::cout << "Ошибка: невозможно скрутить пробег на негативное число" << std::endl;
			return;
		}
		if (x > mileage) {
			std::cout << "Пробег скручен до 0." << std::endl;
			mileage = 0;
		}
		else {
			mileage -= x;
			std::cout << "Пробег скручен на " << x << " км" << std::endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	Car myCar("Chevrolet", "Lacetti", "ABC123456", "O669AA", 150000);
	myCar.printInfo();

	myCar.setNumber("WBAVA51000C123456");

	myCar.setGovNumber("O700AA");

	myCar.rollbackMileage(100000);
	std::cout << "Пробег: " << myCar.getMileage() << " км" << std::endl << std::endl;

	Car copyCar = myCar;
	copyCar.printInfo();

	return 0;
}