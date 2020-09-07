#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//В файле input.txt записаны вещественные числа, по одному на строчку. На стандартный вывод напечатайте эти числа в том же порядке,
//по одному на строке, но сделайте так, чтобы у каждого из них было ровно три знака после десятичной точки.
int main(){
	ifstream input("input.txt");
	string line;
	double num;
	cout << fixed << setprecision(3);
	while (getline(input, line)) {
		num = atof(line.c_str());
		cout << num << endl;
	}
}
