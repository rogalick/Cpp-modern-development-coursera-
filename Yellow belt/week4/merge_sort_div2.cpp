#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//Напишите шаблонную функцию MergeSort, принимающую два итератора шаблонного типа RandomIt и сортирующую заданный ими диапазон с помощью сортировки слиянием. Гарантируется, что:

//итераторы типа RandomIt аналогичны по функциональности итераторам вектора и строки, то есть их можно сравнивать с помощью операторов <, <= , > и >= , а также вычитать и складывать с числами;
//сортируемые объекты можно сравнивать с помощью оператора < .
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin > 1) {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        RandomIt middle = elements.begin() + (elements.end() - elements.begin()) / 2;

        MergeSort(elements.begin(), middle);
        MergeSort(middle, elements.end());
        merge(elements.begin(), middle, middle, elements.end(), range_begin);
    }
}
int main() {
    vector<int> v = { 6, 4, 7, 6, };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}