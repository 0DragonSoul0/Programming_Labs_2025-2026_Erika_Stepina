#include <iostream>
#include <cmath>
#include <locale.h>

//вариант 10
int main() {
	setlocale(LC_ALL, "Russian");
	//1 пункт.
	//const int NMax = 5;
	int sum_of_elements = 0;
	unsigned int min_element = pow(10, 10);
	int min_element_index = 0;
	//int a[NMax];
	//std::cin >> a[0];
	//std::cin >> a[1];
	//std::cin >> a[2];
	//std::cin >> a[3];
	//std::cin >> a[4];
	//вариант создания массива через size_t (для того, чтобы пользователь сам задал желаемое кол-во элементов)
	const size_t limit = 40000;
	int a[limit];
	size_t size;
	std::cout << "Введите желаемое количество элементов последовательности:" << std::endl;
	std::cin >> size;
	if (limit < size) {
		size = limit;
		std::cout << "Слишком большое значение, последовательность усечена до " << limit << "элементов" << std::endl;
	}
	std::cout << "Введите элементы последовательности:" << std::endl;
	for (size_t j = 0; j < size; ++j) {
		std::cin >> a[j];
	}
	for (int i = 0; i < size; ++i) {
		if (a[i] % 10 != 1) {
			sum_of_elements += a[i];
			if (a[i] < min_element) {
				min_element = a[i];
				min_element_index = i + 1;
			}
		}
	}
	std::cout << "Сумма чисел, не заканчивающихся цифрой 1: " << sum_of_elements << std::endl;
	std::cout << "Наименьшее из таких чисел: " << min_element << std::endl;
	std::cout << "Номер этого числа в последовательности: " << min_element_index << std::endl;

	//2 пункт.
	std::cout << "Введите число:" << std::endl;
	int number;
	std::cin >> number;
	int least_frequently = 0;
	unsigned int min_cnt = pow(10, 10);
	for(int d = 0; d < 10; ++d) {
		int cnt = 0;
		int tmp = number;
		while(tmp > 0) {
			int digit = tmp % 10;
			if(digit == d) {
				++cnt;
			}
			tmp /= 10;
		}
		if (cnt >= 1) {
			if (min_cnt > cnt) {
				min_cnt = cnt;
				least_frequently = d;
			}
		}
	}
	std::cout << least_frequently << std::endl;
	return 0;
}