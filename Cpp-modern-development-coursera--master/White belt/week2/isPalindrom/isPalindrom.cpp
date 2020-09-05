#include <string>

using namespace std;

bool IsPalindrom (string str){
        for(int i = 0,j = str.size() - 1; i < str.size();i++,j--)
            if(str[i] != str[j])
                return false;
    return true;
}

