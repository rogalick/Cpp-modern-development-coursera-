#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
//Напишите шаблонную функцию FindGreaterElements,
//принимающую множество elements объектов типа T и ещё один объект border типа T и возвращающую вектор
//из всех элементов множества, бо́льших border, в возрастающем порядке.

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    auto start = begin(s);
    auto space = find_if(start, end(s), [](const char& n) {
        return n == ' ';
        });
    result.push_back({ start, space });
    for (; space != end(s); ) {
        space++;
        start = space;
        space = find_if(start, end(s), [](const char& n) {
            return n == ' ';
            });
        result.push_back({ start, space });
    }
    return result;
}   



int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}