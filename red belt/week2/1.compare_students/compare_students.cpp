#include <iostream>
#include <vector>
#include "profile.h"

using namespace std;

#include <map>
#include <string>

struct Student {
    string first_name;
    string last_name;
    map<string, double> marks;
    double rating;

    bool operator < (const Student& other) const {
        return GetName() < other.GetName();
    }

    bool Less(const Student& other) const {
        return rating > other.rating;
    }

    string GetName() const {
        return first_name + " " + last_name;
    }
};

#include "test_runner.h"

#include <algorithm>

using namespace std;

//Оптимизируйте эту функцию
bool Compare(const Student &first,const  Student &second) {
    return first.rating > second.rating;
}

void TestComparison() {
    Student newbie{
      "Ivan", "Ivanov", {
        {"c++", 1.0},
        {"algorithms", 3.0}
      },
      2.0
    };

    Student cpp_expert{
      "Petr", "Petrov", {
        {"c++", 9.5},
        {"algorithms", 6.0}
      },
      7.75
    };

    Student guru{
      "Sidor", "Sidorov", {
        {"c++", 10.0},
        {"algorithms", 10.0}
      },
      10.0
    };
    ASSERT(Compare(guru, newbie));
    ASSERT(Compare(guru, cpp_expert));
    ASSERT(!Compare(newbie, cpp_expert));
}

void TestSorting() {
    vector<Student> students{
      {"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
      {"Semen", "Semenov", {{"maths", 4.}}, 4.},
      {"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
      {"Petr", "Petrov", {{"maths", 3.}}, 3.},
      {"Alexander", "Alexandrov", {{"maths", 1.}}, 1.}
    };
    sort(students.begin(), students.end(), Compare);
    ASSERT(is_sorted(students.begin(), students.end(),
        [](Student first, Student second) {
            return first.Less(second);
        })
    );
}

int main() {
    LOG_DURATION("full programm");
    TestRunner tr;
    RUN_TEST(tr, TestComparison);
    RUN_TEST(tr, TestSorting);
    return 0;
}