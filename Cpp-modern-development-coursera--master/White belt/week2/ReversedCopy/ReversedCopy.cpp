#include <vector>
using namespace std;

vector <int> Reversed(const vector<int>& v){
    vector <int> newvector;
    for (int i = v.size() - 1; i >= 0 ; i--)
        newvector.push_back(v[i]);
    return newvector;
}