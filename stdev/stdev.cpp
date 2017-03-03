#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>


int main()
{
	int N;
	std::cin >> N;
	std::vector<int> data(N);
	double summation = 0;
	double mean = 0;
	double stdev = 0;
	for (auto& x : data)
	{
		std::cin >> x;
		summation += x;
	}
	mean = summation / N;

	summation = 0;
	for (auto& x : data)
	{
		summation += (x - mean)*(x - mean);
	}
	std::cout << std::sqrt(summation / N) << std::endl;

#ifdef _DEBUG
	system("pause");
#endif

	return 0;
}