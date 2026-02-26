#include <iostream>
#include <vector>
#include <string>
#include <locale.h>

class BigInt {
private:
	bool negative = false;
	std::vector<short> digits;
	void removeZeros() {
		while (digits.size() > 1 and digits.back() == 0) {
			digits.pop_back();
		}
		if (digits.size() == 1 and digits.back() == 0) {
			negative = false;
		}
	}
public:
	BigInt() {
		digits = {0};
		negative = false;
	}

	BigInt(std::string n) {
		while (n[0] == '-') {
			negative = !negative;
			n.erase(0, 1);
		}
		while (n[0] == '+') {
			n.erase(0, 1);
		}
		for (int i = n.length() - 1; i >= 0; --i) {
			if (std::isdigit(n[i])) {
				digits.push_back(n[i] - '0');
			}
			else {
				throw std::invalid_argument("Строка содержит нечисловые символы.");
			}
		}
		removeZeros();
	}

	BigInt(const int& n) {
		std::string strn = std::to_string(n);
		while (strn[0] == '-') {
			negative = !negative;
			strn.erase(0, 1);
		}
		while (strn[0] == '+') {
			strn.erase(0, 1);
		}
		for (int i = strn.length() - 1; i >= 0; --i) {
			if (std::isdigit(strn[i])) {
				digits.push_back(strn[i] - '0');
			}
			else {
				throw std::invalid_argument("Строка содержит нечисловые символы.");
			}
		}
		removeZeros();
	}

	BigInt operator+(const BigInt& other) const {
		if (*this == 0) {
			return other;
		}
		if (other == 0) {
			return *this;
		}
		bool both_negative = false;
		if (negative and other.negative) {
			both_negative = true;
		}
		else if (negative) {
			BigInt thisCopy = *this;
			thisCopy.negative = false;
			BigInt result = other - thisCopy;
			return result;
		}
		else if (other.negative) {
			BigInt otherCopy = other;
			otherCopy.negative = false;
			BigInt result = *this - otherCopy;
			return result;
		}

		BigInt result;
		result.digits.clear();
		size_t max_len = std::max(digits.size(), other.digits.size());
		short carry = 0;

		for (size_t i = 0; i < max_len or carry != 0; ++i) {
			short sum = carry;
			if (i < digits.size()) {
				sum += digits[i];
			}
			if (i < other.digits.size()) {
				sum += other.digits[i];
			}
			result.digits.push_back(sum % 10);
			carry = sum / 10;
		}

		result.removeZeros();
		result.negative = both_negative;
		return result;
	}

	BigInt& operator+=(const BigInt& other) {
		*this = *this + other;
		return *this;
	}

	BigInt operator-(const BigInt& other) const {
		if (*this == 0) {
			BigInt copyOther = other;
			copyOther.negative = true;
			return copyOther;
		}
		if (other == 0) {
			return *this;
		}
		bool both_negative = false;
		if (negative and other.negative) {
			BigInt thisCopy = *this;
			BigInt otherCopy = other;
			thisCopy.negative = false;
			otherCopy.negative = false;
			BigInt result = otherCopy - thisCopy;
			return result;
		}
		else if (other.negative) {
			BigInt otherCopy = other;
			otherCopy.negative = false;
			BigInt result = *this + otherCopy;
			return result;
		}
		else if (negative) {
			BigInt thisCopy = *this;
			thisCopy.negative = false;
			BigInt result = thisCopy + other;
			result.negative = true;
			return result;
		}

		if (*this >= other) {
			BigInt result;
			result.digits.clear();
			short carry = 0;

			for (size_t i = 0; i < digits.size() or carry != 0; ++i) {
				short dgA = (i < digits.size()) ? digits[i] : 0;
				short dgB = (i < other.digits.size()) ? other.digits[i] : 0;
				short interval = dgA - dgB - carry;

				if (interval < 0) {
					interval += 10;
					carry = 1;
				}
				else {
					carry = 0;
				}
				result.digits.push_back(interval);
			}
			result.removeZeros();
			result.negative = both_negative;
			return result;
		}
		else {
			BigInt result;
			result.digits.clear();
			short carry = 0;

			for (size_t i = 0; i < other.digits.size() or carry != 0; ++i) {
				short dgA = (i < digits.size()) ? digits[i] : 0;
				short dgB = (i < other.digits.size()) ? other.digits[i] : 0;

				short interval = dgB - dgA - carry;

				if (interval < 0) {
					interval += 10;
					carry = 1;
				}
				else {
					carry = 0;
				}
				result.digits.push_back(interval);
			}
			result.removeZeros();
			result.negative = !both_negative;
			return result;
		}
	}

	BigInt& operator-=(const BigInt& other) {
		*this = *this - other;
		return *this;
	}

	BigInt operator*(const BigInt& other) const {
		if (*this == 0 or other == 0) {
			return BigInt(0);
		}
		if (*this == 1) {
			return other;
		}
		if (other == 1) {
			return *this;
		}
		bool res_negative = false;
		if (negative) {
			res_negative = !res_negative;
		}
		if (other.negative) {
			res_negative = !res_negative;
		}

		BigInt result;
		result.digits.clear();
		for (size_t i = 0; i < other.digits.size(); ++i) {
			BigInt interval;
			interval.digits.clear();
			short carry = 0;
			for (int j = 0; j < digits.size() or carry != 0; ++j) {
				short t = carry;
				if (j < digits.size()) {
					t += other.digits[i] * digits[j];
				}
				interval.digits.push_back(t % 10);
				carry = t / 10;
			}
			for (int k = 0; k < i; ++k) {
				interval.digits.insert(interval.digits.begin(), 0);
			}
			result += interval;
		}
		result.removeZeros();
		result.negative = res_negative;
		return result;
	}

	BigInt& operator*=(const BigInt& other) {
		*this = *this * other;
		return *this;
	}

	bool operator==(const BigInt& other) const {
		if (negative != other.negative) {
			return false;
		}
		if (digits.size() < other.digits.size()) {
			return false;
		}
		else if (digits.size() > other.digits.size()) {
			return false;
		}

		for (int i = digits.size() - 1; i >= 0; --i) {
			if (digits[i] < other.digits[i]) {
				return false;
			}
			else if (digits[i] > other.digits[i]) {
				return false;
			}
		}

		return true;
	}

	bool operator!=(const BigInt& other) const {
		return !(*this == other);
	}

	bool operator<(const BigInt& other) const {
		if (negative and !other.negative) {
			return true;
		}
		if (!negative and other.negative) {
			return false;
		}

		bool both_negative = (negative and other.negative);

		if (!both_negative) {
			if (digits.size() < other.digits.size()) {
				return true;
			}
			else if (digits.size() > other.digits.size()) {
				return false;
			}

			for (int i = digits.size() - 1; i >= 0; --i) {
				if (digits[i] < other.digits[i]) {
					return true;
				}
				else if (digits[i] > other.digits[i]) {
					return false;
				}
			}

			return false;
		}
		else {
			if (digits.size() < other.digits.size()) {
				return false;
			}
			else if (digits.size() > other.digits.size()) {
				return true;
			}

			for (int i = digits.size() - 1; i >= 0; --i) {
				if (digits[i] < other.digits[i]) {
					return false;
				}
				else if (digits[i] > other.digits[i]) {
					return true;
				}
			}

			return false;
		}
	}

	bool operator>(const BigInt& other) const {
		return (other < *this);
	}

	bool operator>=(const BigInt& other) const {
		return !(*this < other);
	}

	bool operator<=(const BigInt& other) const {
		return !(*this > other);
	}

	void printInfo() const {
		std::cout << (negative ? "-" : "");
		for (int i = digits.size() - 1; i >= 0; --i) {
			std::cout << digits[i];
		}
		std::cout << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const BigInt& n) {
		if (n.negative) {
			os << '-';
		}

		for (auto i = n.digits.rbegin(); i != n.digits.rend(); ++i) {
			os << *i;
		}
		return os;
	}

	friend std::istream& operator>>(std::istream& os, BigInt& n) {
		std::string str;
		os >> str;

		try {
			n = BigInt(str);
		}
		catch (...) {
			n = BigInt();
		}
		return os;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	BigInt x, y;
	std::cout << "Введите два числа: ";
	std::cin >> x >> y;
	std::cout << "Что хотите с ними сделать?" << std::endl;
	std::cout << "1. Сложить" << std::endl;
	std::cout << "2. Вычесть" << std::endl;
	std::cout << "3. Умножить" << std::endl;
	std::cout << "4. Сравнить (<)" << std::endl;
	std::cout << "5. Сравнить (>)" << std::endl;
	std::cout << "6. Сравнить (==)" << std::endl;
	std::cout << "7. Сравнить (!=)" << std::endl;
	short opt;
	std::cin >> opt;
	switch (opt) {
	case 1:
		std::cout << x << " + " << y << " = " << (x + y) << std::endl;
		break;

	case 2:
		std::cout << x << " - " << y << " = " << (x - y) << std::endl;
		break;

	case 3:
		std::cout << x << " * " << y << " = " << (x * y) << std::endl;
		break;

	case 4:
		if (x < y) {
			std::cout << "True" << std::endl;
		}
		else {
			std::cout << "False" << std::endl;
		}
		break;

	case 5:
		if (x > y) {
			std::cout << "True" << std::endl;
		}
		else {
			std::cout << "False" << std::endl;
		}
		break;

	case 6:
		if (x == y) {
			std::cout << "True" << std::endl;
		}
		else {
			std::cout << "False" << std::endl;
		}
		break;

	case 7:
		if (x != y) {
			std::cout << "True" << std::endl;
		}
		else {
			std::cout << "False" << std::endl;
		}
		break;
	}
}