#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    double n,a,b,x,y;
    cin >> n >> a >> b >> x >> y;
    if (n <= a)
        cout << n << endl;
    else if(n <= b){
        cout << n - (n/100)*x << endl;
    }
    else{
        cout << n - (n/100)*y << endl;
    }
    
    

    return 0;
}

