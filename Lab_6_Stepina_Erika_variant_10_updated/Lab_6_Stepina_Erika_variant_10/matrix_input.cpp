#include "matrix_input.hpp"
#include <iostream>

namespace forlab {
	void matrixInput(int a[100][100], int size) {
		for (size_t i = 1; i < size + 1; ++i) {
			for (size_t j = 1; j < size + 1; ++j) {
				std::cout << "Введите элемент a[" << i << "][" << j << "]:" << std::endl;
				std::cin >> a[i][j];
			}
		}
	}
}