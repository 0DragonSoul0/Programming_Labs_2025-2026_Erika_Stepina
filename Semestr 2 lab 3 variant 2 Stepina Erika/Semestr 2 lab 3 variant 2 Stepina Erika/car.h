#pragma once
#include <string>
#include <locale.h>
#include <cctype>

class Car {
private:
	std::string brand;
	std::string model;
	int release_year;
	std::string govNumber;
	int mileage;
public:
	Car();
	Car(std::string br, std::string md, int year, std::string gn, int ml);
	Car(const Car& other);
	~Car();
	std::string toString() const;
	void addMileage(int& km);
	int getMileage() const;
	std::string getGovNumber() const;
};