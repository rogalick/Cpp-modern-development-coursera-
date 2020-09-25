#include <iostream>
#include <map>
#include <exception>
//���������� ��������� ������� GetRefStrict, ������� �� ���� ���������: map � �������� ����� k.
//���� ������� �� ����� k � ��������� �����������,
//�� ������� ������ ������� ���������� runtime_error, ����� ������� ������ �� ������� � ���������.
using namespace std;
template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k) {
	if (m.count(k) == 1) {
		return m[k];
	}
	else {
		throw runtime_error("K isn`t exist\n");
	}
}
