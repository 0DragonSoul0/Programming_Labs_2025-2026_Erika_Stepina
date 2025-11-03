#include <iostream>
#include <locale.h>
#include <cmath>

int main() {
	setlocale(LC_ALL, "Russian");
	//1 пункт.
	const size_t limit_n = 10000;
	int a1[limit_n];
	size_t size_n;
	std::cout << "Введите желаемое кол-во элементов последовательности:" << std::endl;
	std::cin >> size_n;
	if (limit_n < size_n) {
		size_n = limit_n;
		std::cout << "Слишком большое значение, последовательность усечена до " << limit_n << "элементов" << std::endl;
	}
	for (size_t n = 1; n < size_n + 1; ++n) {
		std::cout << "Введите элемент a[" << n << "]:" << std::endl;
		std::cin >> a1[n];
	}
	std::cout << "Изначальная последовательность:" << std::endl;
	for (int n = 1; n < size_n + 1; ++n) {
		std::cout << a1[n] << " ";
	}
	std::cout << std::endl;
	for (int n = 1; n < size_n + 1; ++n) {
		for (int m = n + 1; m < size_n + 1; ++m) {
			if (a1[n] == a1[m]) {
				for (int n1 = 1; n1 < size_n + 1; ++n1) {
					int last_digit_1 = abs(a1[n1]) % 10;
					int last_digit_2 = abs(a1[n1 + 1]) % 10;
					if (last_digit_1 <= last_digit_2) {
						int tmp = a1[n1];
						a1[n1] = a1[n1 + 1];
						a1[n1 + 1] = tmp;
					}
				}
			}
		}
	}
	std::cout << "Изменённая последовательность:" << std::endl;
	for (int n = 1; n < size_n + 1; ++n) {
		std::cout << a1[n] << " ";
	}
	std::cout << std::endl;
	//2 пункт.
	const size_t limit_n2 = 1000;
	int a2[limit_n2];
	size_t size_n2;
	std::cout << "Введите желаемое кол-во элементов последовательности:" << std::endl;
	std::cin >> size_n2;
	if (limit_n2 < size_n2) {
		size_n2 = limit_n2;
		std::cout << "Слишком большое значение, последовательность усечена до " << limit_n2 << "элементов" << std::endl;
	}
	for (size_t n = 1; n < size_n2 + 1; ++n) {
		std::cout << "Введите элемент a[" << n << "]:" << std::endl;
		std::cin >> a2[n];
	}
	std::cout << "Изначальная последовательность:" << std::endl;
	for (int n = 1; n < size_n2 + 1; ++n) {
		std::cout << a2[n] << " ";
	}
	std::cout << std::endl;
	for (int n = 1; n < size_n2 + 1; ++n) {
		int first_digit_1;
		int first_digit_2;
		int tmp1 = a2[n];
		int tmp2 = a2[n + 1];
		while (tmp1 != 0) {
			tmp1 = tmp1 / 10;
		}
		first_digit_1 = tmp1;
		while (tmp2 != 0) {
			tmp2 = tmp2 / 10;
		}
		first_digit_2 = tmp2;
		if (first_digit_1 > first_digit_2) {
			int tmp3 = a2[n];
			a2[n] = a2[n + 1];
			a1[n + 1] = tmp3;
		}
		else if (first_digit_1 == first_digit_2) {
			int pr1 = 1;
			int pr2 = 1;
			int tmp4 = a2[n];
			int tmp5 = a2[n + 1];
			while (tmp4 != 0) {
				int a = tmp4 % 10;
				pr1 = pr1 * a;
				tmp4 = tmp4 / 10;
			}
			while (tmp5 != 0) {
				int a1 = tmp5 % 10;
				pr2 = pr2 * a1;
				tmp5 = tmp5 / 10;
			}
			if (pr1 > pr2) {
				int tmp6 = a2[n];
				a2[n] = a2[n + 1];
				a1[n + 1] = tmp6;
			}
			else if (pr1 == pr2) {
				if (a2[n] > a2[n + 1]) {
					int tmp7 = a2[n];
					a2[n] = a2[n + 1];
					a1[n + 1] = tmp7;
				}
			}
		}
	}
	std::cout << "Изменённая последовательность:" << std::endl;
	for (int n = 1; n < size_n2 + 1; ++n) {
		std::cout << a2[n] << " ";
	}
	std::cout << std::endl;
	//3 пункт.
	const size_t limit1 = 100;
	const size_t limit2 = 100;
	int a[limit1][limit2];
	size_t size1;
	size_t size2;
	std::cout << "Введите желаемое кол-во строк матрицы:" << std::endl;
	std::cin >> size1;
	if (limit1 < size1) {
		size1 = limit1;
		std::cout << "Слишком большое значение, матрица усечена до " << limit1 << "строк" << std::endl;
	}
	std::cout << "Введите желаемое кол-во столбцов матрицы:" << std::endl;
	std::cin >> size2;
	if (limit2 < size2) {
		size2 = limit2;
		std::cout << "Слишком большое значение, матрица усечена до " << limit2 << "столбцов" << std::endl;
	}
	for (size_t i = 1; i < size1 + 1; ++i) {
		for (size_t j = 1; j < size2 + 1; ++j) {
			std::cout << "Введите элемент a[" << i << "][" << j << "]:" << std::endl;
			std::cin >> a[i][j];
		}
	}
	std::cout << "Изначальная матрица:" << std::endl;
	for (int i = 1; i < size1 + 1; ++i) {
		for (int j = 1; j < size2 + 1; ++j) {
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	int min_sum_of_elements = 32767;
	int max_j = 0;
	for (int j = 1; j < size2 + 1; ++j) {
		int sum_of_elements = 0;
		for (int i = 1; i < size1 + 1; ++i) {
			sum_of_elements += a[i][j];
		}
		if (min_sum_of_elements > sum_of_elements) {
			min_sum_of_elements = sum_of_elements;
			max_j = j;
		}
	}
	for (int j1 = 1; j1 < size2 + 1; ++j1) {
		int sm_elements = 0;
		for (int i1 = 1; i1 < size1 + 1; ++i1) {
			sm_elements += a[i1][j1];
		}
		if (sm_elements == min_sum_of_elements) {
			for (int i2 = 1; i2 < size1 + 1; ++i2) {
				a[i2][max_j] = a[i2][max_j] + 3;
			}
		}
	}
	std::cout << "Изменённая матрица:" << std::endl;
	for (int i = 1; i < size1 + 1; ++i) {
		for (int j = 1; j < size2 + 1; ++j) {
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}