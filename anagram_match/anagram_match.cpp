#include <map>
#include <iostream>
#include <string>
#include <cmath>

inline void fill_map(const std::string& str, std::map<char, int>& map) {
	for (const char& c : str) {
			++map[c];
	}
}

int number_needed(std::string a, std::string b) {
	std::map<char, int> amap, bmap;
	int running_sum = 0;
	fill_map(a, amap);
	fill_map(b, bmap);
	for (const char& c : "abcdefghijklmnopqrstuvwxyz") {
		running_sum += std::abs(amap[c] - bmap[c]);
	}
	return running_sum;
}

int main() {
	std::string a;
	std::cin >> a;
	std::string b;
	std::cin >> b;
	std::cout << number_needed(a, b) << std::endl;
	return 0;
}
