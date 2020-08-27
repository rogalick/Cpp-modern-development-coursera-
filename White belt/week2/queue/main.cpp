#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{   
    string command;
    int n,j,cont;
    cin >> n;
    vector<int> queue;
    for(int i = 0; i < n; i++){
        cont = 0;
        cin >> command;
        if (command != "WORRY_COUNT")
            cin >> j;
        else {
            for(auto it : queue)
                if (it == 1)
                    cont++;
            cout << cont << " ";
        }
        if (command == "COME")
            if (j > 0)
                for (int i = 0; i < j; i++) 
                    queue.push_back(0);
            else
            queue.resize(queue.size() + j);
        else if (command == "WORRY")
            queue[j] = 1;
        else if(command == "QUIET")
            queue[j] = 0;
        
    }
    return 0;
}
