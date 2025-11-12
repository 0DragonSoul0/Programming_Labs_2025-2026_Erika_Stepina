#include <iostream>
#include <cmath>
#include <locale.h>
#include "prime.hpp"
#include "matrix_input.hpp"
#include "matrix_output.hpp"

int main() {
	setlocale(LC_ALL, "Russian");
	/*const size_t limit = 100;
	int a[limit][limit];
	size_t size;
	std::cout << "Введите желаемое кол-во строк и столбцов матрицы (i = j): " << std::endl;
	std::cin >> size;
	if (limit < size) {
		size = limit;
		std::cout << "Слишком большое значение, матрица усечена до " << limit << "строк и столбцов" << std::endl;
	}
	int* a1 = &a[size][size];
	int** a2 = &a1;*/
	int size;
	std::cout << "Введите желаемое кол-во строк и столбцов матрицы (i = j): " << std::endl;
	std::cin >> size;
	int a[100][100];
	forlab::matrixInput(a, size);
			/*std::cout << "Введите элемент a[" << i << "][" << j << "]:" << std::endl;
			std::cin >> a[i][j];*/
	std::cout << "Изначальная матрица:" << std::endl;
	forlab::matrixOutput(a, size);
			//std::cout << a[i][j] << " ";
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
	std::cout << "Изменённая матрица:" << std::endl;
	forlab::matrixOutput(a, size);
			//std::cout << a[i][j] << " ";
	return 0;
}