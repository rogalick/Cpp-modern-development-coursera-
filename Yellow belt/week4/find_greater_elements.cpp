#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

//Напишите шаблонную функцию FindGreaterElements,
//принимающую множество elements объектов типа T и ещё один объект border типа T и возвращающую вектор
//из всех элементов множества, бо́льших border, в возрастающем порядке.

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	vector<T> result;
	auto start = find_if(begin(elements), end(elements), [&border](const T& n) {
		return n > border;
		});
	while (start != end(elements)) {
		result.push_back(*start);
		start++;
	}
	return result;
}



int main() {
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
	return 0;
}