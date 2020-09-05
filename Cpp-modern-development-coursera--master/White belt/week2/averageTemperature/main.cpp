#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int count,n,a,sum = 0;
    cin >> n;
    vector<int> days(n);
    for (int i = 0; i < n; i++){
        cin >> a;
        days[i] = a;
        sum += a;
    }
    sum /=n;
    for (int iter : days)
        if (iter > sum)
            count++;
    cout << count << endl;
    for (int j = 0; j < days.size();j++) {
        if (days[j] > sum)
            cout << j  << " ";
        
    }
    
    return 0;
}
