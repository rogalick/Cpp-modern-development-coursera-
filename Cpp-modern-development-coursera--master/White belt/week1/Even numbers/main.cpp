#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
   int a,b;
   cin >> a >> b;
   for (; a <= b; ++a){
       if (a%2 == 0){
           cout << a << " ";
       }
   }
}
