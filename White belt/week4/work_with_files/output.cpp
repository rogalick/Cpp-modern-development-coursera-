#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//����� �������� ��� ���������� ����� input.txt, �� �� ���� ��� �������� ��� � ���� output.txt.
//����� ��� �� �������������, ��� ���������� ����� input.txt ������������� ��������� ������.
int main() {
	ifstream input("input.txt");
	string line;
	ofstream output("output.txt");
	while (getline(input, line)) {
		output << line << endl;
	}
}
