#pragma once
#include <string>
#include <locale.h>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iostream>

class BigInt {
private:
	bool neg = false;
	std::vector<short> digits;
	void removeZeros() {
		while (digits.size() > 1 && digits.back() == 0) {
			digits.pop_back();
		}
		if (digits.size() == 1 && digits.back() == 0) {
			neg = false;
		}
	}
public:
	BigInt();

	BigInt(std::string num);

	BigInt(const int& num);

	BigInt operator+(const BigInt& other) const;

	BigInt& operator+=(const BigInt& other);

	BigInt operator-(const BigInt& other) const;

	BigInt& operator-=(const BigInt& other);

	BigInt operator*(const BigInt& other) const;

	BigInt& operator*=(const BigInt& other);

	bool operator==(const BigInt& other) const;

	bool operator!=(const BigInt& other) const;

	bool operator<(const BigInt& other) const;

	bool operator>(const BigInt& other) const;

	bool operator>=(const BigInt& other) const;

	bool operator<=(const BigInt& other) const;

	void printInfo() const;

	friend std::ostream& operator<<(std::ostream& os, const BigInt& n);

	friend std::istream& operator>>(std::istream& os, BigInt& n);

};