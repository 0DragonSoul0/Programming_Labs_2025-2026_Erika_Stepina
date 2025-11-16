#include "prime.hpp"
#include <cmath>

namespace forlab {
	bool isPrime(int x) {
		if (x <= 1) {
			return false;
		}
		for (int d = 2; d <= sqrt(x); ++d) {
			if (x % d == 0) {
				return false;
			}
		}
		return true;
	}
}