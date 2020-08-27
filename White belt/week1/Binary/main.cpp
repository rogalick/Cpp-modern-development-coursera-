#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    deque <int> b;
    int a;
    cin >> a;
    while(a != 0){
        b.push_front(a % 2);
        a = a/2;
    }
    for (int iter :b)
    cout << iter;
    
    return 0;
}
