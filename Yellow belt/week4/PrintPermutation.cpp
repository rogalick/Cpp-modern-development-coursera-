#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Дано целое положительное число N, не превышающее 9.
//Выведите все перестановки чисел от 1 до N в обратном лексикографическом порядке (см. пример).

int main() {
    int n;
    cin >> n;
    std::vector< int > v;
    for (; n > 0; n--) {
        v.push_back(n);
    }
    do
    {
        for (int i = 0; i < v.size(); i += 1)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    } while (std::prev_permutation(v.begin(), v.end()));
    return 0;
}