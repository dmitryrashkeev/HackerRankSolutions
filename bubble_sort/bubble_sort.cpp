#include <iostream>
#include <vector>
#include <utility>
#include "../sort_utils/sort_utils.h"

template <typename Iter>
std::pair<int, int> bubble_sort(Iter begin, Iter end) {
	int numSwaps = 0, prevNumSwaps = 0;
	int numComps = 0;
	auto endpoint = end - 1;

	do {
		prevNumSwaps = numSwaps;
		for (auto i = begin; i != endpoint; ++i) {

			if (compare(*i, *(i + 1), numComps)) {
				swap(*i, *(i + 1), numSwaps);
			}
		}
	} while (numSwaps > prevNumSwaps);

	return std::make_pair(numSwaps, numComps);
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	auto result = bubble_sort(a.begin(),a.end());
	std::cout << "Array is sorted in " << result.first << " swaps with " << result.second << " comparisons" << std::endl;
	std::cout << "Array contents: ";
	for (const auto& i : a) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
