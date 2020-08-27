#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string first;
    string second;
    cin >> n;
    for (int i = 0; i < n; ++i){
        map<char,int> map1;
        map<char,int> map2;
        cin >> first;
        cin >> second;
        if (first.size() == second.size()) {
            for (auto iter : first)
                ++map1[iter];
            for (auto iter : second)
                ++map2[iter];
        if (map1 == map2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        }
        else
        cout << "NO" << endl;
    }
    return 0;
}
