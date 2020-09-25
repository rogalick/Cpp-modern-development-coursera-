#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers,
//выполняющую поиск первого отрицательного числа в нём и выводящую в стандартный вывод все числа,
//расположенные левее найденного, в обратном порядке. Если вектор не содержит отрицательных чисел,
//выведите все числа в обратном порядке.
void PrintVectorPart(const vector<int>& numbers) {
	auto start = find_if(begin(numbers), end(numbers), [](const int& n) {
		return n < 0;
		});
	while (start != begin(numbers)) {
		start--;
		cout << *start << " ";
	}
}


int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}