#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//���� ��������� ������ ������� ���������� ����� input.txt
//� ���������� ��� �� ����� ��� ���������.
//�������������, ��� ���������� ����� input.txt ������������� ��������� ������.
int main() {
	ifstream input("input.txt");
	string line;
	while (getline(input, line)) {
		cout << line << endl;
	}
}
