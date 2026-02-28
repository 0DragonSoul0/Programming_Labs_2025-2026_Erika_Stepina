#include <iostream>
#include <vector>
#include <string>
#include <locale.h>

class BigInt {
private:
	bool negative_ = false;
	std::vector<short> digits_;
	void removeZeros() {
		while (digits_.size() > 1 && digits_.back() == 0) {
			digits_.pop_back();
		}
		if (digits_.size() == 1 && digits_.back() == 0) {
			negative_ = false;
		}
	}
public:
	BigInt() {
		digits_ = {0};
		negative_ = false;
	}

	BigInt(std::string num) {
		while (num[0] == '-') {
			negative_ = !negative_;
			num.erase(0, 1);
		}
		while (num[0] == '+') {
			num.erase(0, 1);
		}
		for (int i = num.length() - 1; i >= 0; --i) {
			if (std::isdigit(num[i])) {
				digits_.push_back(num[i] - '0');
			}
			else {
				throw std::invalid_argument("Строка содержит нечисловые символы.");
			}
		}
		removeZeros();
	}

	BigInt(const int& num) {
		std::string strnum = std::to_string(num);
		while (strnum[0] == '-') {
			negative_ = !negative_;
			strnum.erase(0, 1);
		}
		while (strnum[0] == '+') {
			strnum.erase(0, 1);
		}
		for (int i = strnum.length() - 1; i >= 0; --i) {
			if (std::isdigit(strnum[i])) {
				digits_.push_back(strnum[i] - '0');
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
		bool negative = false;
		if (negative_ && other.negative_) {
			negative = true;
		}
		else if (negative_) {
			BigInt thisCopy = *this;
			thisCopy.negative_ = false;
			BigInt result = other - thisCopy;
			return result;
		}
		else if (other.negative_) {
			BigInt otherCopy = other;
			otherCopy.negative_ = false;
			BigInt result = *this - otherCopy;
			return result;
		}

		BigInt result;
		result.digits_.clear();
		size_t max_len = std::max(digits_.size(), other.digits_.size());
		short carry = 0;

		for (size_t i = 0; i < max_len || carry != 0; ++i) {
			short sum = carry;
			if (i < digits_.size())
				sum += digits_[i];
			if (i < other.digits_.size())
				sum += other.digits_[i];

			result.digits_.push_back(sum % 10);
			carry = sum / 10;
		}

		result.removeZeros();
		result.negative_ = negative;
		return result;
	}

	BigInt& operator+=(const BigInt& other) {
		*this = *this + other;
		return *this;
	}

	BigInt operator-(const BigInt& other) const {
		if (*this == 0) {
			BigInt copyOther = other;
			copyOther.negative_ = true;
			return copyOther;
		}
		if (other == 0) {
			return *this;
		}
		bool negative = false;
		if (negative_ && other.negative_) {
			BigInt thisCopy = *this;
			BigInt otherCopy = other;
			thisCopy.negative_ = false;
			otherCopy.negative_ = false;
			BigInt result = otherCopy - thisCopy;
			return result;
		}
		else if (other.negative_) {
			BigInt otherCopy = other;
			otherCopy.negative_ = false;
			BigInt result = *this + otherCopy;
			return result;
		}
		else if (negative_) {
			BigInt thisCopy = *this;
			thisCopy.negative_ = false;
			BigInt result = thisCopy + other;
			result.negative_ = true;
			return result;
		}

		if (*this >= other) {
			BigInt result;
			result.digits_.clear();
			short carry = 0;

			for (size_t i = 0; i < digits_.size() || carry != 0; ++i) {
				short dgA = (i < digits_.size()) ? digits_[i] : 0;
				short dgB = (i < other.digits_.size()) ? other.digits_[i] : 0;
				short interval = dgA - dgB - carry;

				if (interval < 0) {
					interval += 10;
					carry = 1;
				}
				else { carry = 0; }

				result.digits_.push_back(interval);
			}
			result.removeZeros();
			result.negative_ = negative;
			return result;
		}
		else {
			BigInt result;
			result.digits_.clear();
			short carry = 0;

			for (size_t i = 0; i < other.digits_.size() || carry != 0; ++i) {
				short dgA = (i < digits_.size()) ? digits_[i] : 0;
				short dgB = (i < other.digits_.size()) ? other.digits_[i] : 0;

				short interval = dgB - dgA - carry;

				if (interval < 0) {
					interval += 10;
					carry = 1;
				}
				else {
					carry = 0;
				}

				result.digits_.push_back(interval);
			}

			result.removeZeros();
			result.negative_ = !negative;
			return result;
		}
	}

	BigInt& operator-=(const BigInt& other) {
		*this = *this - other;
		return *this;
	}

	BigInt operator*(const BigInt& other) const {
		if (*this == 0 || other == 0) {
			return BigInt(0);
		}
		if (*this == 1) {
			return other;
		}
		if (other == 1) {
			return *this;
		}
		bool negative = false;
		if (negative_) {
			negative = !negative;
		}
		if (other.negative_) {
			negative = !negative;
		}

		BigInt result;
		result.digits_.clear();
		for (size_t i = 0; i < other.digits_.size(); ++i) {
			BigInt interval;
			interval.digits_.clear();
			short carry = 0;
			for (int j = 0; j < digits_.size() || carry != 0; ++j) {
				short times = carry;
				if (j < digits_.size()) {
					times += other.digits_[i] * digits_[j];
				}
				interval.digits_.push_back(times % 10);
				carry = times / 10;
			}
			for (int k = 0; k < i; ++k) {
				interval.digits_.insert(interval.digits_.begin(), 0);
			}

			result += interval;
		}

		result.removeZeros();
		result.negative_ = negative;
		return result;
	}

	BigInt& operator*=(const BigInt& other) {
		*this = *this * other;
		return *this;
	}

	bool operator==(const BigInt& other) const {
		if (negative_ != other.negative_) {
			return false;
		}
		if (digits_.size() < other.digits_.size()) {
			return false;
		}
		else if (digits_.size() > other.digits_.size()) {
			return false;
		}

		for (int i = digits_.size() - 1; i >= 0; --i) {
			if (digits_[i] < other.digits_[i]) {
				return false;
			}
			else if (digits_[i] > other.digits_[i]) {
				return false;
			}
		}

		return true;
	}

	bool operator!=(const BigInt& other) const {
		return !(*this == other);
	}

	bool operator<(const BigInt& other) const {
		if (negative_ && !other.negative_) {
			return true;
		}
		if (!negative_ && other.negative_) {
			return false;
		}

		bool negative = (negative_ && other.negative_);

		if (!negative) {
			if (digits_.size() < other.digits_.size()) {
				return true;
			}
			else if (digits_.size() > other.digits_.size()) {
				return false;
			}

			for (int i = digits_.size() - 1; i >= 0; --i) {
				if (digits_[i] < other.digits_[i]) {
					return true;
				}
				else if (digits_[i] > other.digits_[i]) {
					return false;
				}
			}

			return false;
		}
		else {
			if (digits_.size() < other.digits_.size()) {
				return false;
			}
			else if (digits_.size() > other.digits_.size()) {
				return true;
			}

			for (int i = digits_.size() - 1; i >= 0; --i) {
				if (digits_[i] < other.digits_[i]) {
					return false;
				}
				else if (digits_[i] > other.digits_[i]) {
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
		std::cout << (negative_ ? "-" : "");
		for (int i = digits_.size() - 1; i >= 0; --i) {
			std::cout << digits_[i];
		}
		std::cout << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const BigInt& n) {
		if (n.negative_) {
			os << '-';
		}

		for (auto i = n.digits_.rbegin(); i != n.digits_.rend(); ++i) {
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
		catch (const std::exception& error) {
			throw std::invalid_argument("введено нечисловое значение.");
		}
		return os;
	}
};

void Menu() {
	std::cout << "Что хотите с ними сделать?" << std::endl;
	std::cout << "1. Сложить" << std::endl;
	std::cout << "2. Вычесть" << std::endl;
	std::cout << "3. Умножить" << std::endl;
	std::cout << "4. Сравнить (<)" << std::endl;
	std::cout << "5. Сравнить (>)" << std::endl;
	std::cout << "6. Сравнить (==)" << std::endl;
	std::cout << "7. Сравнить (!=)" << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	BigInt x;
	BigInt y;
	std::cout << "Введите два числа: ";
	try {
		std::cin >> x;
		std::cin >> y;
	}
	catch (std::invalid_argument& err) {
		std::cerr << "Ошибка: " << err.what() << std::endl;
		return -1;
	}
	while (true) {
		Menu();
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
}