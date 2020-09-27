#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//Напишите шаблонную функцию RemoveDuplicates, принимающую по ссылке вектор elements объектов типа T
//и удаляющую из него все дубликаты элементов. Порядок оставшихся элементов может быть любым.
//Гарантируется, что объекты типа T можно сравнивать с помощью операторов == , != , < и >.
template <typename T>
void RemoveDuplicates(vector<T>& elements) {
    sort(begin(elements), end(elements));
    elements.erase(std::unique(begin(elements), end(elements)), end(elements));
}