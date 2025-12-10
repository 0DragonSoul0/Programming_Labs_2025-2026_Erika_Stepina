#include "func_3.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace forlab{
	void outUntilN(const std::vector<std::string>& words, size_t& N) {
		std::ofstream out("C:\\C++ programming\\Lab_8_Stepina_Erika_variant_10\\Lab_8_Stepina_Erika_variant_10\\output_1.txt");
		N = std::min(words.size(), N);
		if (out.is_open()) {
			for (size_t i = 0; i < N; ++i) {
				std::cout << i + 1 << ": " << words[i] << std::endl;
				out << i + 1 << ": " << words[i] << std::endl;
			}
		}
		std::cout << "Найденные слова были записаны в текстовый файл." << std::endl;
	}
}