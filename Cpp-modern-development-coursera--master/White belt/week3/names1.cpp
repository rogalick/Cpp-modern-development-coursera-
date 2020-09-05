#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;




class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        data_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        data_last_name[year] = last_name;
    }
    string GetFullName(int year) {
        string fname, lname;

        for (const auto& y : data_name) {
            if (y.first > year)
                break;
            if (y.second.empty() == false)
                fname = y.second;
        }

        for (const auto& y : data_last_name) {
            if (y.first > year)
                break;
            if (y.second.empty() == false)
                lname = y.second;
        }

        if (fname.empty() == false && lname.empty() == false)
            return fname + " " + lname;
        else if (fname.empty() == false)
            return fname + " with unknown last name";
        else if (lname.empty() == false)
            return lname + " with unknown first name";
        return { "Incognito" };
    }
private:
    map<int, string> data_name;
    map<int, string> data_last_name;
};