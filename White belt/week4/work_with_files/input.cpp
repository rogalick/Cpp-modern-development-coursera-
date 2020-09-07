#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//Ваша программа должна считать содержимое файла input.txt
//и напечатать его на экран без изменений.
//Гарантируется, что содержимое файла input.txt заканчивается переводом строки.
int main() {
	ifstream input("input.txt");
	string line;
	while (getline(input, line)) {
		cout << line << endl;
	}
}
