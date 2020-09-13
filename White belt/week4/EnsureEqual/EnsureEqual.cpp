#include <iostream>
using namespace std;
// �������� ������� void EnsureEqual(const string& left, const string& right);
// � ������, ���� ������ left �� ����� ������ right, ������� ������ ����������� ���������� runtime_error � �����������
//"<l> != <r>", ��� <l> � <r> - ������, ������� �������� � ���������� left � right ��������������. �������� ��������,
//��� ������ ����� ����������� � ������, ������� ���������� � ����������, ������ ���� ����� �� ������ �������.
//���� left == right, ������� ������ ��������� �����������.

void EnsureEqual(const string& left, const string& right) {
    string str;
    if (left != right) {
        str = left + " != " + right;
        throw runtime_error(str);
    }
}
