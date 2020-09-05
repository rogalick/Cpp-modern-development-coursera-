#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
   string str;
   cin >> str;
   int count = 0;
   for(int i = 0; i < str.size(); i++){
        if(str[i] == 'f' && count == 1)
            cout << i << endl;
       if (str[i] == 'f')
            count++;
   }
   if (count == 0)
        cout << -2 << endl;
    if (count == 1)
        cout << -1 << endl;
}
