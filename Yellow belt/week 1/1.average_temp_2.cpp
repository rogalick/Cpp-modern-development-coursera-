#include <iomanip>
#include <iostream>
#include <vector>
// ���� �������� �����������, ������������� � ������� N ������ ������ ����. ������� ������ ���� (� ��������� � ����)
// �� ��������� ����������� ���� �������� ��������������� �� ��� N ����.
using namespace std;

int main() {
	int n, k;
	long int averag = 0;
	vector <int> temp;
	vector <int> nums;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		temp.push_back(k);
		averag += k;
	}
	averag = averag / static_cast<int>(temp.size());
	int i = 0;
	for (int a : temp) {
		if (a > averag)
			nums.push_back(i);
		++i;
	}
	cout << nums.size() << endl;

	for (int a : nums) {
		cout << a << " ";
	}
}