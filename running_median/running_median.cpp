#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
#include <functional>


int main() {
	int n, m;
	std::cin >> n;
	std::priority_queue<int> lower; // top should be largest member; Lower contains median if the heap is unbalanced;
	std::priority_queue<int, std::vector<int>, std::greater<int>> upper; // top should be smallest member
	std::cout << std::fixed;
	std::cout << std::setprecision(1);

	for (auto i = 0u; i < n; ++i) {
		std::cin >> m;
		if (lower.empty() || m <= lower.top()) {
			lower.push(m);
		}
		else {
			upper.push(m);
		}
		if (lower.size() % 2 == upper.size() % 2) {
			//if both are even or both are odd, we can have a balanced heap
			while (int(lower.size() - upper.size()) > 0) {
				upper.push(lower.top());
				lower.pop();
			}
			while (int(upper.size() - lower.size()) > 0) {
				lower.push(upper.top());
				upper.pop();
			}
			std::cout << float(upper.top() + lower.top()) / 2 << std::endl;
		}
		else {
			while (int(lower.size() - upper.size()) > 1) {

				upper.push(lower.top());
				lower.pop();
			}
			while (int(lower.size() - upper.size()) < 1) {
				lower.push(upper.top());
				upper.pop();
			}
			std::cout << float(lower.top()) << std::endl;
		}


	}
	return 0;
}
