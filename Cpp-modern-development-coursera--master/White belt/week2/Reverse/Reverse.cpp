#include <vector>
using namespace std;

void Reverse(vector<int>& v){
    for (int i = 0,j = v.size() - 1;i < v.size()/2; i++,j--)
    swap(v[i],v[j]);
}
