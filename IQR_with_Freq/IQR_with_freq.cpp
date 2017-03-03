#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

int main()
{
	int N = 0;
	int M = 0;
	double Q1, Q2, Q3;
	std::cin >> N;
	std::vector<int> input_data(N);
	std::vector<int> freq(N);
	for (auto& x : input_data)
	{
		std::cin >> x;
	}
	for (auto& f : freq)
	{
		std::cin >> f;
		M += f;
	}
	std::vector<int> data(M);
	auto data_iter = data.begin();
	for (auto i = 0u; i < N; ++i)
	{
		for (auto j = 0u; j < freq[i]; ++j)
		{
			(*data_iter) = input_data[i];
			++data_iter;
		}
	}
	std::sort(data.begin(), data.end());
#ifdef _DEBUG
	for (auto x : data)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
#endif
	if (M % 2 == 1)
	{
		Q2 = data[M / 2];

		if ((M / 2) % 2 == 1)
		{
			Q1 = data[(M / 2) / 2];
			Q3 = data[1 + (M / 2) + (M / 2) / 2];
		}
		else
		{
			Q1 = (data[(M / 2) / 2] + data[(M / 2 - 1) / 2]) / 2.0;
			Q3 = (data[1 + (M / 2) + (M / 2) / 2] + data[(M / 2) + (M / 2) / 2]) / 2.0;
		}


	}
	else
	{
		Q2 = (data[M / 2] + data[M / 2 - 1]) / 2.0;
		if ((M / 2) % 2 == 1)
		{
			Q1 = data[(M / 2) / 2];
			Q3 = data[(M / 2) + (M / 2) / 2];
		}
		else
		{
			Q1 = (data[(M / 2) / 2] + data[(M / 2 - 1) / 2]) / 2.0;
			Q3 = (data[(M / 2) + (M / 2) / 2] + data[(M / 2) + (M / 2) / 2 - 1]) / 2.0;
		}
	}
	std::cout << std::fixed << std::setprecision(1) << Q3 - Q1 << std::endl;
#ifdef _DEBUG
	system("pause");
#endif

	return 0;
}
