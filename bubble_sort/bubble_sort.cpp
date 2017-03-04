#include <iostream>
#include <vector>
#include <iterator>


template <typename T>
void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template <typename Iter>
int bubble_sort(Iter begin, Iter end) {
	int numSwaps = 0, prevNumSwaps = 0;
	auto endpoint = end - 1;

	do {
		prevNumSwaps = numSwaps;
		for (auto j = begin; j != endpoint; ++j) {

			if (*j > *(j + 1)) {
				swap(*j, *(j + 1));
				++numSwaps;
			}
		}
	} while (numSwaps > prevNumSwaps);

	for (auto i = begin; i < end; ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return numSwaps;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	auto swaps = bubble_sort(a.begin(),a.end());
	std::cout << "Array is sorted in " << swaps << " swaps." << std::endl;
	std::cout << "First Element: " << a[0] << std::endl;
	std::cout << "Last Element: " << *(a.end()-1) << std::endl;

	return 0;
}
