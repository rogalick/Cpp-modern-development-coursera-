#include "airline_ticket.h"
#include <map>
#include <iostream>
using namespace std;

#define UPDATE_FIELD(ticket, field, values) \
 {                                          \
        auto it = values.find(#field);      \
        if (it != values.end()) {           \
            istringstream is(it->second);   \
            is >> ticket.field;             \
        }                                   \
    }  

bool operator==(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Time& lhs, const Time& rhs) {
    return tie(lhs.hours, lhs.minutes) == tie(rhs.hours, rhs.minutes);
}

ostream& operator<<(ostream& os, const Date& date) {
    os << date.year << "." << date.month << "." << date.day;
    return os;
}

istream& operator>>(istream& is, Date& date) {
    is >> date.year;
    is.ignore();
    is >> date.month;
    is.ignore();
    is >> date.day;
    return is;
}

ostream& operator<<(ostream& os, const Time& time) {
    os << time.minutes << ":" << time.minutes;
    return os;
}

istream& operator>>(istream& is, Time& time) {
    is >> time.hours;
    is.ignore();
    is >> time.minutes;
    return is;
}

