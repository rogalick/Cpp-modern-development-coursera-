#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix) {
    return { lower_bound(range_begin,range_end,string(1,prefix)),
            upper_bound(range_begin,range_end,string(1,prefix + 1)) };

}
//Напишите функцию FindStartsWith :

//принимающую отсортированный набор строк в виде итераторов range_begin, range_end и один символ prefix;
//возвращающую диапазон строк, начинающихся с символа prefix, в виде пары итераторов.


int main() {
    const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

    const auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
        (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
        (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}
