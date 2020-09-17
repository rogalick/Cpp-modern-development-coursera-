#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
//���������� ��������� ������� Sqr, ������� �������� �� ������ ��� �����, �� � ��� �����������.
//������� ������ ���������� ����� ��������� ����������, ������������� ��� ��������� �������:

//��� vector �������� ����� �������� � �������;
//��� map � ������� ����� �������� ������ ��������, �� �� �����;
//��� pair � ������� ����� �������� ������ ������� ����.
using namespace std;

template <typename T> T Sqr(T d);
template <typename T> vector<T> Sqr(const vector<T>& v1);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m1);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p1);

template <typename T> T operator *(T a, T b) {
	return a * b;
}

template <typename T> T Sqr(T d) {
	return d * d;
}

template <typename T> vector<T> Sqr(const vector<T>& v1) {
	vector<T> result;

	for (const auto& i : v1) {
		result.push_back(Sqr(i));
	}
	return result;
}

template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m1) {
	map<Key, Value> result;
	for (const auto& [key, value] : m1) {
		result[key] = Sqr(value);
	}
	return result;
}

template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p1) {
	return make_pair(Sqr(p1.first), Sqr(p1.second));
}
