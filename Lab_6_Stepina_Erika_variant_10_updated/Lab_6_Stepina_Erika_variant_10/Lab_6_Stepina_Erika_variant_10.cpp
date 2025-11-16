#include <iostream>
#include <cmath>
#include <locale.h>
#include "prime.hpp"
#include "matrix_input.hpp"
#include "matrix_output.hpp"
#include "task_solution.hpp"

int main() {
	setlocale(LC_ALL, "Russian");
	int size;
	std::cout << "Введите желаемое кол-во строк и столбцов матрицы (i = j): " << std::endl;
	std::cin >> size;
	int a[100][100];
	forlab::matrixInput(a, size);
	std::cout << "Изначальная матрица:" << std::endl;
	forlab::matrixOutput(a, size);
	forlab::taskSolution(a, size);
	std::cout << "Изменённая матрица:" << std::endl;
	forlab::matrixOutput(a, size);
	return 0;
}