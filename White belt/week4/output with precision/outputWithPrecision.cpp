#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//� ����� input.txt �������� ������������ �����, �� ������ �� �������. �� ����������� ����� ����������� ��� ����� � ��� �� �������,
//�� ������ �� ������, �� �������� ���, ����� � ������� �� ��� ���� ����� ��� ����� ����� ���������� �����.
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
