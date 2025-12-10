#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace forlab {
	std::vector<std::string> getWords(const std::string& text, const std::string& exceptions);
}