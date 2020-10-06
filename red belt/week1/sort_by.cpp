#include "airline_ticket.h"
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

#define SORT_BY(field) [](const AirlineTicket &lhs, const AirlineTicket &rhs) { return lhs.field < rhs.field; }

bool operator<(const Date& lhs, const Date& rhs) {
    int a1 = (14 - lhs.month) / 12;
    int a2 = (14 - rhs.month) / 12;
    int y1 = lhs.year + 4800 - a1;
    int y2 = rhs.year + 4800 - a2;
    int m1 = lhs.month + (12 * a1) - 3;
    int m2 = rhs.month + (12 * a2) - 3;

    return (lhs.day + ((153 * m1 + 2) / 5) + (y1 * 365) + (y1 / 4) - (y1 / 100) + (y1 / 400))
        < (rhs.day + ((153 * m2 + 2) / 5) + (y2 * 365) + (y2 / 4) - (y2 / 100) + (y2 / 400));
}

bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}

ostream& operator<<(ostream& os, const Date& date) {
    os << date.year << "." << date.month << "." << date.day;
    return os;
}

bool operator<(const Time& lhs, const Time& rhs) {
    return (lhs.hours * 60 + lhs.minutes) < (rhs.hours * 60 + rhs.minutes);
}

bool operator==(const Time& lhs, const Time& rhs) {
    return lhs.minutes == rhs.minutes && lhs.hours == rhs.hours;
}

ostream& operator<<(ostream& os, const Time& time) {
    os << time.minutes << ":" << time.minutes;
    return os;
}

