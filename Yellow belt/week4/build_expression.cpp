#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;


void addSymbols(deque<string>& result) {
    result.push_back(") ");
    result.push_front("(");
}


int main() {
    int number, n;
    cin >> number >> n;
    string line;
    deque<string> result;
    string buffer;
    if (n == 0)
        cout << number << endl;
    else {
        result.push_back(to_string(number));
        getline(cin, buffer);
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            addSymbols(result);
            result.push_back(line);
        }
        for (const string& it : result)
            cout << it;
        cout << endl;
    }
}

