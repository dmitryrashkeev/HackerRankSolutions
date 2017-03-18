#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>
#include <random>
#include "../sort_utils/sort_utils.h"


template <typename Iter>
std::pair<int, int> quick_sort(Iter begin, Iter end) {
	if (end <= begin + 1) return { 0,0 };
	int numSwaps = 0;
	int numComps = 0;
	auto i = begin;
	auto j = end - 1;

	//select median of min, max, and middle to discourage the function going O(n^2)
	auto pivot = std::max(std::min(*i, *j), std::min(std::max(*i, *j), *(i+std::distance(i,j)/2)));

	while (i <= j) {

		while (compare<decltype(*i)>(*i, pivot, numComps,std::less<decltype(*i)>()) && i < end-1) {
			++i;
		}
		while (compare<decltype(*i)>(*j, pivot, numComps, std::greater<decltype(*i)>()) && j > begin ) {
			--j;
		}
		if (i <= j) {
			if(i != j) swap(*i, *j, numSwaps);	
			++i;
			--j;
		}
			
	}
	auto out = std::make_pair(numSwaps, numComps);

	auto left_sort = std::async(std::launch::async, quick_sort<Iter>, begin, j + 1);
	auto right_sort = std::async(std::launch::async, quick_sort<Iter>, i, end);
	out = out + left_sort.get() + right_sort.get();

	return out;

	
}


int main() {
	int n,m;
	std::cin >> n;
	std::vector<int> a;
	a.reserve(n);
	//for (auto i = 0; i < n; ++i) {
	//	std::cin >> m;
	//	a.push_back(m);
	//}
	std::random_device rd;
	std::uniform_int_distribution<int> distribution(0, 100);
	std::default_random_engine generator(rd());
	for (auto i = 0; i < n; ++i) {
		a.push_back(distribution(generator));
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
