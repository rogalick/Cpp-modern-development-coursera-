#include <iostream>

using namespace std;

class Animal {
public:
    Animal(string name_) :Name(name_) {
    }
    const string Name;
};


class Dog : public Animal {
public:
    Dog(string name_) :Animal(name_) {

    }
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};