#include "matrix_input.hpp"
#include <iostream>

namespace forlab {
	int matrixInput(int** a, size_t i, size_t j) {
		std::cout << "Введите элемент a[" << i << "][" << j << "]:" << std::endl;
		std::cin >> a[i][j];
	}
}