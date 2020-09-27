#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin > 1) {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        vector<typename RandomIt::value_type> buffer;

        RandomIt middle = elements.begin() + ((elements.end() - elements.begin()) / 3);
        RandomIt middle2 = middle + ((elements.end() - elements.begin()) / 3);

        MergeSort(elements.begin(), middle);
        MergeSort(middle, middle2);
        MergeSort(middle2, elements.end());

        merge(elements.begin(), middle, middle, middle2, back_inserter(buffer));
        merge(buffer.begin(), buffer.end(), middle2, elements.end(), range_begin);
    }
}

int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}