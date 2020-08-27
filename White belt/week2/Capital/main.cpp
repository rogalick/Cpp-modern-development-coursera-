#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void change_capital(map <string,string> &capital){
    string first,second;
    std::cin >> first >> second;
    if(capital[first].empty() == 1){
        capital[first] = second;
        cout << "Introduce new country " << first << " with capital " << second << endl;
    }
    else if(capital[first] == second) {
        cout << "Country " << first << " hasn't changed its capital" << endl;
    }
    else if(capital[first] != second){
        cout << "Country " << first << " has changed its capital from " << capital[first] << " to " << second << endl;
        capital[first].erase();
        capital[first] = second;
    }
}

void dump(const map <string,string> &capital){
    if (capital.size() == 0){
        cout << "There are no countries in the world";
    }
    else {
        for (auto iter : capital){
            cout << iter.first << "/" << iter.second << " ";
        }
    }
    cout << endl;
}

void about( map <string,string> &capital){
    string first;
    std::cin >> first;
    if (capital.count(first) == 0) {
       cout << "Country " <<first << " doesn't exist";
       capital.erase(first);
    }
    else
        cout << "Country " <<first << " has capital " << capital[first];
        std::cout << endl;
    
}

void rename(map <string,string> &capital){
    string old,newc;
    cin >> old;
    cin >> newc;
    if ( capital.count(old) == 0 || capital.count(newc) == 1  || old == newc){
        cout << "Incorrect rename, skip";
    }
    else {
       cout << "Country " << old <<" with capital " << capital[old] <<" has been renamed to " <<newc;
       capital[newc] = capital[old];
       capital.erase(old);
    }
    cout <<endl;
}
int main(int argc, char const *argv[]) {
    string command;
    int n;
    map <string,string> capital;

    std::cin >> n;
    for (int i = 0; i < n; ++i){
        std::cin >> command;
        if(command == "CHANGE_CAPITAL")
            change_capital(capital);
        else if(command == "RENAME" ) {
            rename(capital);
        }
        else if(command == "ABOUT") {
            about(capital);
        }
        else if(command == "DUMP") {
            dump(capital);
        }
    }
}