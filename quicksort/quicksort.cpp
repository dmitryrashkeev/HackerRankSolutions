#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
#include <algorithm>
#include <typeinfo>
#include "../sort_utils/sort_utils.h"


template <typename Iter>
std::pair<int, int> quick_sort(Iter begin, Iter end) {
	if (end == begin + 1) return { 0,0 };
	int numSwaps = 0;
	int numComps = 0;
	auto i = begin;
	auto j = end - 1;

	//select median of min, max, and middle to discourage the function going O(n^2)
	auto pivot = std::max(std::min(*i, *j), std::min(std::max(*i, *j), *(i+std::distance(i,j)/2)));

	while (i <= j) {

		while (compare<decltype(*i)>(*i, pivot, numComps,std::less_equal<decltype(*i)>())&& i < end-1) {
			++i;
		}
		while (compare<decltype(*i)>(*j, pivot, numComps, std::greater<decltype(*i)>()) && j>begin) {
			--j;
		}
		if (i <= j) {
			if(i != j) swap(*i, *j, numSwaps);	
			++i;
			--j;
		}
			
	}
	auto out = std::make_pair(numSwaps, numComps);
	if (begin < j)
		out = out + quick_sort(begin, j + 1);
	if (i < end-1)
		out = out + quick_sort(i, end);
	return out;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	auto result = quick_sort(a.begin(), a.end());
	std::cout << "Array is sorted in " << result.first << " swaps with " << result.second << " comparisons" << std::endl;
	std::cout << "Array contents: ";
	for (const auto& i : a) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
