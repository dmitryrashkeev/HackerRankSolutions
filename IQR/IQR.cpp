#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


int main()
{
	int N;
	double Q1, Q2, Q3;
	std::cin >> N;
	std::vector<int> data(N);
	for (auto& x : data)
	{
		std::cin >> x;
	}
	std::sort(data.begin(), data.end());
#ifdef _DEBUG
	for (auto x : data)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
#endif
	if (N % 2 == 1)
	{
		Q2 = data[N / 2];
		
		if ((N / 2) % 2 == 1)
		{
			Q1 = data[(N / 2) / 2];
			Q3 = data[1+ (N / 2) + (N / 2) / 2];
		}
		else
		{
			Q1 = (data[(N / 2) / 2] + data[(N / 2 - 1) / 2]) / 2.0;
			Q3 = (data[1 + (N / 2) + (N / 2) / 2] + data[(N / 2) + (N / 2) / 2]) / 2.0;
		}


	}
	else
	{
		Q2 = (data[N / 2] + data[N / 2 - 1]) / 2.0;
		if ((N / 2) % 2 == 1)
		{
			Q1 = data[(N / 2) / 2];
			Q3 = data[(N / 2) + (N / 2) / 2];
		}
		else
		{
			Q1 = (data[(N / 2) / 2] + data[(N / 2 - 1) / 2]) / 2.0;
			Q3 = (data[(N / 2) + (N / 2) / 2] + data[(N / 2) + (N / 2) / 2 - 1]) / 2.0;
		}
	}
	std::cout << Q1 << " " << Q2 << " " << Q3 << std::endl;

	return 0;
}
