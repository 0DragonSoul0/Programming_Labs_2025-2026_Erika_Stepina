#include "task_solution.hpp"
#include "prime.hpp"
#include <iostream>

namespace forlab {
	void taskSolution(int a[100][100], int size) {
		for (int j = 1; j < size + 1; ++j) {
			int sum_of_elements = 0;
			int cnt_prime_numbers = 0;
			for (int i = 1; i < size + 1; ++i) {
				if (forlab::isPrime(a[i][j]) == 1) {
					cnt_prime_numbers += 1;
				}
				else {
					cnt_prime_numbers += 0;
				}
				sum_of_elements += a[i][j];
			}
			if (cnt_prime_numbers == 0 and sum_of_elements == 0) {
				for (int k1 = size - 1; k1 > 0; --k1) {
					for (int i1 = 1; i1 < size + 1; ++i1) {
						for (int j1 = 1; j1 < size + 1; ++j1) {
							if (abs(a[i1][j1]) > abs(a[i1][j1 + 1])) {
								int tmp = a[i1][j1];
								a[i1][j1] = a[i1][j1 + 1];
								a[i1][j1 + 1] = tmp;
							}
						}
					}
				}
			}
		}
	}
}