#include <iostream>
#include <vector>
#include <utility>



template <typename T, typename C>
void swap(T& a, T& b, C& counter) {
	++counter;
	T c = a;
	a = b;
	b = c;
}

template <typename T, typename C>
bool compare(const T& a, const T& b, C& counter) {
	++counter;
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

template <typename Iter>
std::pair<int, int> bubble_sort(Iter begin, Iter end) {
	int numSwaps = 0, prevNumSwaps = 0;
	int numComps = 0;
	auto endpoint = end - 1;

	do {
		prevNumSwaps = numSwaps;
		for (auto j = begin; j != endpoint; ++j) {

			if (compare(*j, *(j+1), numComps)) {
				swap(*j, *(j + 1), numSwaps);
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
