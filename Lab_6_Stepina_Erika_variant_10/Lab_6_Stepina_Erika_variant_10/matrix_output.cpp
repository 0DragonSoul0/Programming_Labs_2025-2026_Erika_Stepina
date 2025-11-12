#include "matrix_output.hpp"
#include <iostream>

namespace forlab {
	void matrixOutput(int a[100][100], int size) {
		for (int i = 1; i < size + 1; ++i) {
			for (int j = 1; j < size + 1; ++j) {
				std::cout << a[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}