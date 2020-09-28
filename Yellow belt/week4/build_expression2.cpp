#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;


void addSymbols(deque<string>& result, char symbol, char prevsymbol) {
    if ((prevsymbol == '+' || prevsymbol == '-') && (symbol == '*' || symbol == '/')) {
        result.push_back(")");
        result.push_front("(");
    }
}


int main() {
    int number, n, number2;
    cin >> number >> n;
    char symbol = '*'; // для условия чтобы при первой итерации не было скобок
    char prevsymbol = '*';
    deque<string> result;
    if (n == 0)
        cout << number << endl;
    else {
        string str(3, ' ');
        result.push_back(to_string(number));
        for (int i = 0; i < n; ++i) {
            prevsymbol = symbol;
            cin >> symbol >> number2;
            addSymbols(result, symbol, prevsymbol);
            str[1] = symbol;
            result.push_back(str);
            result.push_back(to_string(number2));
        }
        for (const string& it : result)
            cout << it;
        cout << endl;
    }
}

