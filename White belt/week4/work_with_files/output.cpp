#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt.
//Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.
int main() {
	ifstream input("input.txt");
	string line;
	ofstream output("output.txt");
	while (getline(input, line)) {
		output << line << endl;
	}
}
