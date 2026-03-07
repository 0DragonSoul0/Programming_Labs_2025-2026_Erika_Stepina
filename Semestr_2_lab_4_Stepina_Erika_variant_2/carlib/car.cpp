#include <iostream>
#include "car.h"

Car::Car() {
    brand = "неизвестен";
    model = "неизвестна";
    release_year = 0;
    govNumber = "A000AA";
    mileage = 0;
}

Car::Car(std::string br, std::string md, int year, std::string gn, int ml) {
    brand = br;
    model = md;
    release_year = year;
    govNumber = gn;
    mileage = ml;
    if (br.empty()) {
        brand = Car().brand;
    }
    if (std::any_of(br.begin(), br.end(), ::ispunct)) {
        throw std::invalid_argument("Ошибка: недействительное название бренда.");
    }
    if (md.empty()) {
        model = Car().model;
    }
    if (std::any_of(md.begin(), md.end(), ::ispunct)) {
        throw std::invalid_argument("Ошибка: недействительное название модели.");
    }
    if (gn.empty()) {
        govNumber = Car().govNumber;
    }
    if (gn.length() != 6 || !(isalpha(gn[0]) && isdigit(gn[1]) && isdigit(gn[2]) && isdigit(gn[3]) && isalpha(gn[4]) && isalpha(gn[5]))) {
        throw std::invalid_argument("Ошибка: недействительный гос. номер");
    }
}

Car::Car(const Car& other) {
    brand = other.brand;
    model = other.model;
    release_year = other.release_year;
    govNumber = other.govNumber;
    mileage = other.mileage;
    std::cout << "Запущен конструктор копирования." << std::endl;
}

Car::~Car() {}

std::string Car::toString() const {
    std::string out = brand + " " + model + ", " + std::to_string(release_year) + " г., гос. номер " + govNumber + ", пробег " + std::to_string(mileage) + " км";
    return out;
}

void Car::addMileage(int& km) {
    if (km < 0) {
        std::cout << "Ошибка: невозможно добавить негативный пробег" << std::endl;
        std::cout << std::endl;
        return;
    }
    else {
        mileage += km;
        //std::cout << "Пробег добавлен: " << km << " км" << std::endl;
        //std::cout << "Текущий пробег: " << mileage << " км" << std::endl;
        //std::cout << std::endl;
    }
}

int Car::getMileage() const {
    return mileage;
}

std::string Car::getGovNumber() const {
    return govNumber;
}
