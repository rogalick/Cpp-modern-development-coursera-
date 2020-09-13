#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using isis = istream_iterator<string>;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
    Date(string date) {
        istringstream iss(date);
        iss >> year;
        iss.ignore();
        iss >> month;
        iss.ignore();
        iss >> day;
    }

    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int day;
    int month;
    int year;
};

bool operator==(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() == rhs.GetDay();
        }
        return false;
    }
    return false;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth())
            return lhs.GetDay() < rhs.GetDay();
        else
            return lhs.GetMonth() < rhs.GetMonth();
    }
    else
        return lhs.GetYear() < rhs.GetYear();
}

class Database {
public:

    void AddEvent(const Date& date, const string& event) {
        datemap[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (datemap.count(date) != 0) {
            std::set<string>::iterator it;
            it = datemap[date].find(event);
            if (it == datemap[date].end()) {
                cout << "Event not found" << endl;
                return 0;
            }
            else {
                datemap[date].erase(it);
                cout << "Deleted successfully" << endl;
            }
        }
        else {
            cout << "Event not found" << endl;
            return 0;
        }
        return 1;
    }
    int  DeleteDate(const Date& date) { //Удаление всех ивентов по определенной дате
        int i = 0;
        if (datemap.count(date) != 0) {
            for (const auto& iter : datemap.at(date))
                i++;
            datemap.erase(date);
            cout << "Deleted " << i << " events" << endl;
        }
        else {
            cout << "Deleted 0 events" << endl;
        }
        return 0;
    }

    void Print() const {
        for (auto iter : datemap) {
            for (const auto& it : iter.second) {
                cout << setw(4) << setfill('0') << iter.first.GetYear() << '-';
                cout << setw(2) << setfill('0') << iter.first.GetMonth() << '-';
                cout << setw(2) << setfill('0') << iter.first.GetDay() << ' ';
                cout << it << endl;
            }
        }
    }
    void Find(const Date& date) const {
        if (datemap.count(date) != 0) { // проверка существует ли данный ключ
            for (const auto& iter : datemap.at(date))
                cout << iter << endl;
        }
        /*else
            cout << "Event not found" << endl;*/
    }
    map <Date, set<string>> datemap;
};

bool dateValidate(const string& date) {
    istringstream iss(date);
    int year, month, day;
    char delim1, delim2;

    if (iss >> year >> delim1 >> month >> delim2 >> day &&
        delim1 == '-' && delim2 == '-' && iss.eof()) {
        if (month > 0 && month < 13) {
            if (day > 0 && day < 32)
                return true;
            else
                cout << "Day value is invalid: " << day << endl;
        }
        else
            cout << "Month value is invalid: " << month << endl;
    }
    else
        cout << "Wrong date format: " << date << endl;
    return false;
}
int main() {
    Database db;
    vector<string> v;
    istringstream iss;
    string command;

    while (getline(cin, command)) {
        iss.clear();
        v.clear();
        iss.str(command);
        copy(isis(iss), {}, inserter(v, v.end()));
        if (v.empty() == false) { // проверяем  не пустая ли строка
            if (v.front() == "Print")
                db.Print();
            else if (v.size() > 1) { // обробатываем запросы в вводе которой есть не только команда
                if (dateValidate(v[1])) {    // проверяем валидность даты
                    if (v.size() == 2) {
                        if (v.front() == "Del") {
                            Date date(v[1]);
                            db.DeleteDate(date);
                        }
                        else if (v.front() == "Find") {
                            Date date(v[1]);
                            db.Find(date);
                        }
                        else
                            cout << "Unknown command: " << v.front() << endl;
                    }
                    else if (v.size() == 3) {
                        if (v.front() == "Add") {
                            Date date(v[1]);
                            db.AddEvent(date, v[2]);
                        }
                        else if (v.front() == "Del") {
                            Date date(v[1]);
                            db.DeleteEvent(date, v[2]);
                        }
                        else
                            cout << "Unknown command: " << v.front() << endl;
                    }
                }
            }
            else {
                cout << "Unknown command: " << v.front() << endl;
            }
        }
    }

    return 0;
}