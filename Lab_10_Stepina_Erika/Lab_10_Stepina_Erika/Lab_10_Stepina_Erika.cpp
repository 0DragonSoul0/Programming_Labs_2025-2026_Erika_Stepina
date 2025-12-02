#include <iostream>
#include <locale.h>

void quicksort(int arr[], int left, int right)
{
	int i = left, j = right;
	int pivot = arr[left];

	while (i <= j)
	{
		while (arr[i] < pivot)
			++i;
		while (arr[j] > pivot)
			--j;
		if (i <= j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			++i;
			--j;
		}
	}
	if (left < j)
		quicksort(arr, left, j);
	if (i < right)
		quicksort(arr, i, right);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int size;
	std::cout << "Введите желаемое кол-во строк и столбцов матрицы (i = j): " << std::endl;
	std::cin >> size;
	int a[100];
	for (size_t n = 1; n < size + 1; ++n) {
		std::cout << "Введите элемент a[" << n << "]:" << std::endl;
		std::cin >> a[n];
	}
	std::cout << "Изначальная последовательность:" << std::endl;
	for (int n = 1; n < size + 1; ++n) {
		std::cout << a[n] << " ";
	}
	std::cout << std::endl;

	//1. Быстрая сортировка.

	/*int left = 0;
	int right = size;
	quicksort(a, left, right);*/

	//Суть сортировки: выбирается опорный элемент (pivot). элементы, меньшие него, идут влево, большие - вправо.
	//Сложность: O(n log n) - O(n^2).

	//2. Сортировка обменами.

	/*for (int k = 0; k < size; ++k) {
		for (int n = 0; n < size - k; ++n) {
			if (a[n] > a[n + 1]) {
				std::swap(a[n], a[n + 1]);
			}
		}
	}*/

	//Суть сортировки: сравниваем соседние элементы и меняем их местами.
	//Сложность: O(n) - O(n^2).

	//3. Сортировка выбором.

	/*for (int i = 0; i < size + 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < size + 1; ++j) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
			std::swap(a[i], a[minIndex]);
		}
	}*/

	//Суть сортировки: многократный поиск минимального элемента в неотсортированной части массива;
	// на каждом шаге выбираем минимальный элемент из оставшейся части массива и перемещаем в начало.
	//Сложность: O(n^2).

	std::cout << "Изменённая последовательность:" << std::endl;
	for (int n = 1; n < size + 1; ++n) {
		std::cout << a[n] << " ";
	}
	std::cout << std::endl;
	return 0;
}