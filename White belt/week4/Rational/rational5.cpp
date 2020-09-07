#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
class Rational {
public:
    Rational() {
        numerator_m = 0;
        denominator_m = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0 || numerator == 0) {
            numerator_m = 0;
            denominator_m = 1;
        }
        else {
            numerator_m = numerator / gcd(numerator, denominator);
            denominator_m = denominator / gcd(numerator, denominator);
            if (denominator_m < 0 && numerator_m < 0) {
                numerator_m *= -1;
                denominator_m *= -1;
            }
        }
    }

    int Numerator() const {
        return numerator_m;
    }

    int Denominator() const {
        return denominator_m;
    }
    void update(int numerator, int denominator) {
        if (denominator == 0 || numerator == 0) {
            numerator_m = 0;
            denominator_m = 1;
        }
        else {
            numerator_m = numerator / gcd(numerator, denominator);
            denominator_m = denominator / gcd(numerator, denominator);
            if (denominator_m < 0 && numerator_m < 0) {
                numerator_m *= -1;
                denominator_m *= -1;
            }
        }
    }

private:
    int numerator_m;
    int denominator_m;

};
bool operator == (const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator())
        if (lhs.Denominator() == rhs.Denominator())
            return true;
    return false;
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    int num1, num2, dum = 0;
    num1 = lhs.Numerator() * rhs.Denominator();
    num2 = rhs.Numerator() * lhs.Denominator();
    dum = lhs.Denominator() * rhs.Denominator();
    Rational obj(num1 + num2, dum);
    return obj;
}


Rational operator - (const Rational& lhs, const Rational& rhs) {
    int num1, num2, dum = 0;
    num1 = lhs.Numerator() * rhs.Denominator();
    num2 = rhs.Numerator() * lhs.Denominator();
    dum = lhs.Denominator() * rhs.Denominator();
    Rational obj(num1 - num2, dum);
    return obj;
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    int num, dum = 0;
    num = lhs.Numerator() * rhs.Denominator();
    dum = lhs.Denominator() * rhs.Numerator();
    Rational obj(num, dum);
    return obj;
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    int num, dum = 0;
    num = lhs.Numerator() * rhs.Numerator();
    dum = lhs.Denominator() * rhs.Denominator();
    Rational obj(num, dum);
    return obj;
}
std::ostream& operator<< (std::ostream& out, const Rational& num) {
    return out << num.Numerator() << '/' << num.Denominator();
}


istream& operator >> (istream& s, Rational& rat) {
    int num1, num2 = 0;
    char delim;
    s >> num1 >> delim >> num2;
    if (delim == '/')
        rat.update(num1, num2);
    return s;
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    return ((double)lhs.Numerator() / lhs.Denominator() < ((double)rhs.Numerator() / rhs.Denominator()));
}

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
