#include <stack>
#include <string>
#include <iostream>

bool braces_match(const char& c1, const char& c2) {
	if (c1 == '(' && c2 == ')') return true;
	if (c1 == '[' && c2 == ']') return true;
	if (c1 == '{' && c2 == '}') return true;
	return false;
}

bool is_balanced(std::string expr) {
	std::stack<char> bracket_stack;
	             
	for (const char& c : expr) {
		if (c == '(' || c == '{' || c == '[') {
			bracket_stack.push(c);
		}
		else if (!bracket_stack.empty() && braces_match(bracket_stack.top(), c)) {
			bracket_stack.pop();
		}  
		else return false;
	}
	if (bracket_stack.empty()) return true;
	return false;
}

int main() {
	unsigned int n;
	std::cin >> n;
	for (auto i = 0u; i < n; ++i) {
		std::string expr;
		std::cin >> expr;
		if (is_balanced(expr)) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}