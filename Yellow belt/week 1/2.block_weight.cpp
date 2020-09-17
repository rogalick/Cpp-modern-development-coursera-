#include <iostream>
// Вычислите суммарную массу имеющих форму прямоугольного параллелепипеда
// блоков одинаковой плотности, но разного размера.
using namespace std;

int main() {
	unsigned int n = 0, plot = 0, w = 0, h = 0, d = 0;
	unsigned long long int sum = 0;

	cin >> n >> plot;
	for (int i = 0; i < n; ++i) {
		cin >> w >> h >> d;
		sum += (static_cast<unsigned long long>(w) * static_cast<unsigned long long>(h) * static_cast<unsigned long long>(d)) * plot;
	}
	cout << sum;
}