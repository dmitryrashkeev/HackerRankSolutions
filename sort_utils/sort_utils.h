#ifndef __SORT_UTILS_H__
#define __SORT_UTILS_H__
#include <utility>
#include <functional>

template <typename T, typename U>
std::pair<T, U> operator+(std::pair<T, U> left, std::pair<T, U> right) {
	return { left.first + right.first, left.second + right.second };
}


template <typename T, typename C>
void swap(T& a, T& b, C& counter) {
	++counter;
	T c = a;
	a = b;
	b = c;
}

template <typename T, typename C>
bool compare(const T& left, const T& right, C& counter, std::function<bool(T,T)> f = std::greater<T>()) {
	++counter;
	if (f(left,right)) {
		return true;
	}
	else {
		return false;
	}
}


#endif