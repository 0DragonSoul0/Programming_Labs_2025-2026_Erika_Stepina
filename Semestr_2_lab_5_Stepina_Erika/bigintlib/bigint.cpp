#include <iostream>
#include "bigint.h"

BigInt::BigInt() {
    digits = {0};
    neg = false;
}

BigInt::BigInt(std::string num) {
    while (num[0] == '-') {
        neg = !neg;
        num.erase(0, 1);
    }
    while (num[0] == '+') {
        num.erase(0, 1);
    }
    for (int i = num.length() - 1; i >= 0; --i) {
        if (std::isdigit(num[i])) {
            digits.push_back(num[i] - '0');
        }
        else {
            throw std::invalid_argument("Строка содержит нечисловые символы.");
        }
    }
    removeZeros();
}

BigInt::BigInt(const int& num) {
    std::string strnum = std::to_string(num);
    while (strnum[0] == '-') {
        neg = !neg;
        strnum.erase(0, 1);
    }
    while (strnum[0] == '+') {
        strnum.erase(0, 1);
    }
    for (int i = strnum.length() - 1; i >= 0; --i) {
        if (std::isdigit(strnum[i])) {
            digits.push_back(strnum[i] - '0');
        }
        else {
            throw std::invalid_argument("Строка содержит нечисловые символы.");
        }
    }
    removeZeros();
}

BigInt BigInt::operator+(const BigInt& other) const {
    if (*this == 0) {
        return other;
    }
    if (other == 0) {
        return *this;
    }
    bool negative = false;
    if (neg && other.neg) {
        negative = true;
    }
    else if (neg) {
        BigInt thisCopy = *this;
        thisCopy.neg = false;
        BigInt result = other - thisCopy;
        return result;
    }
    else if (other.neg) {
        BigInt otherCopy = other;
        otherCopy.neg = false;
        BigInt result = *this - otherCopy;
        return result;
    }

    BigInt result;
    result.digits.clear();
    size_t max_len = std::max(digits.size(), other.digits.size());
    short carry = 0;

    for (size_t i = 0; i < max_len || carry != 0; ++i) {
        short sum = carry;
        if (i < digits.size())
            sum += digits[i];
        if (i < other.digits.size())
            sum += other.digits[i];

        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }

    result.removeZeros();
    result.neg = negative;
    return result;
}

BigInt& BigInt::operator+=(const BigInt& other) {
    *this = *this + other;
    return *this;
}

BigInt BigInt::operator-(const BigInt& other) const {
    if (*this == 0) {
        BigInt copyOther = other;
        copyOther.neg = true;
        return copyOther;
    }
    if (other == 0) {
        return *this;
    }
    bool negative = false;
    if (neg && other.neg) {
        BigInt thisCopy = *this;
        BigInt otherCopy = other;
        thisCopy.neg = false;
        otherCopy.neg = false;
        BigInt result = otherCopy - thisCopy;
        return result;
    }
    else if (other.neg) {
        BigInt otherCopy = other;
        otherCopy.neg = false;
        BigInt result = *this + otherCopy;
        return result;
    }
    else if (neg) {
        BigInt thisCopy = *this;
        thisCopy.neg = false;
        BigInt result = thisCopy + other;
        result.neg = true;
        return result;
    }

    if (*this >= other) {
        BigInt result;
        result.digits.clear();
        short carry = 0;

        for (size_t i = 0; i < digits.size() || carry != 0; ++i) {
            short dgA = (i < digits.size()) ? digits[i] : 0;
            short dgB = (i < other.digits.size()) ? other.digits[i] : 0;
            short interval = dgA - dgB - carry;

            if (interval < 0) {
                interval += 10;
                carry = 1;
            }
            else { carry = 0; }

            result.digits.push_back(interval);
        }
        result.removeZeros();
        result.neg = negative;
        return result;
    }
    else {
        BigInt result;
        result.digits.clear();
        short carry = 0;

        for (size_t i = 0; i < other.digits.size() || carry != 0; ++i) {
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
        result.neg = !negative;
        return result;
    }
}

BigInt& BigInt::operator-=(const BigInt& other) {
    *this = *this - other;
    return *this;
}

BigInt BigInt::operator*(const BigInt& other) const {
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
    if (neg) {
        negative = !negative;
    }
    if (other.neg) {
        negative = !negative;
    }

    BigInt result;
    result.digits.clear();
    for (size_t i = 0; i < other.digits.size(); ++i) {
        BigInt interval;
        interval.digits.clear();
        short carry = 0;
        for (int j = 0; j < digits.size() || carry != 0; ++j) {
            short times = carry;
            if (j < digits.size()) {
                times += other.digits[i] * digits[j];
            }
            interval.digits.push_back(times % 10);
            carry = times / 10;
        }
        for (int k = 0; k < i; ++k) {
            interval.digits.insert(interval.digits.begin(), 0);
        }

        result += interval;
    }

    result.removeZeros();
    result.neg = negative;
    return result;
}

BigInt& BigInt::operator*=(const BigInt& other) {
    *this = *this * other;
    return *this;
}

bool BigInt::operator==(const BigInt& other) const {
    if (neg != other.neg) {
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

bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}

bool BigInt::operator<(const BigInt& other) const {
    if (neg && !other.neg) {
        return true;
    }
    if (!neg && other.neg) {
        return false;
    }

    bool negative = (neg && other.neg);

    if (!negative) {
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

bool BigInt::operator>(const BigInt& other) const {
    return (other < *this);
}

bool BigInt::operator>=(const BigInt& other) const {
    return !(*this < other);
}

bool BigInt::operator<=(const BigInt& other) const {
    return !(*this > other);
}

void BigInt::printInfo() const {
    std::cout << (neg ? "-" : "");
    for (int i = digits.size() - 1; i >= 0; --i) {
        std::cout << digits[i];
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const BigInt& n) {
    if (n.neg) {
        os << '-';
    }

    for (auto i = n.digits.rbegin(); i != n.digits.rend(); ++i) {
        os << *i;
    }
    return os;
}

std::istream& operator>>(std::istream& os, BigInt& n) {
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
