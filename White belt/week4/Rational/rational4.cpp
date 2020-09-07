#include <iostream>
#include <sstream>

using namespace std;
//  реализуйте операторы * и /

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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}