#include <vector>
#include <string>
using namespace std;

bool IsPalindrom (string str){
        for(int i = 0,j = str.size() - 1; i < str.size();i++,j--)
            if(str[i] != str[j])
                return false;
    return true;
}

vector<string> PalindromFilter(vector<string> words,int minLength){
    vector<string> newstr;
    for(string iter : words)
        if(iter.size() >= minLength)
            if(IsPalindrom(iter) == 1)
                newstr.push_back(iter);
    return newstr;
}

