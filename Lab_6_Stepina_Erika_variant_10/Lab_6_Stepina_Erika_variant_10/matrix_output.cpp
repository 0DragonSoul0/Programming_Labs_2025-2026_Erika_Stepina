#include "matrix_output.hpp"
#include <iostream>

namespace forlab {
	int matrixOutput(int** a, int i, int j) {
		std::cout << a[i][j] << " ";
	}
}