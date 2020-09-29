#include <iostream>
#include <string>
#include <vector>

using namespace std;

class human {
public:
    human(string name_, string type_) : Name(name_), type(type_) {

    }
    ~human() = default;

    virtual void Walk(string destination) {
        cout << type << " " << Name << " walks to: " << destination << endl;
    }


public:
    const string Name;
    const string type;

};
class Student : public human {
public:

    Student(string name, string favouriteSong) : human(name, "Student"), FavouriteSong(favouriteSong) {
    }

    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }
    void SingSong() {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void Walk(string destination) override {
        human::Walk(destination);
        SingSong();
    }

public:
    const string FavouriteSong;
};


class Teacher : public human {
public:

    Teacher(string name, string subject) : human(name, "Teacher") {
        Subject = subject;
    }

    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    void Walk(string destination) override {
        human::Walk(destination);
    }

public:
    string Subject;
};


class Policeman : public human {
public:
    Policeman(string name) : human(name, "Policeman") {
    }

    void Check(human& h) {
        cout << "Policeman: " << Name << " checks " << h.type << ". " << h.type << "'s name is: " << h.Name << endl;
    }

    void Walk(string destination) override {
        human::Walk(destination);
    }

};


void VisitPlaces(human& h, vector<string> places) {
    for (auto p : places) {
        h.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}
