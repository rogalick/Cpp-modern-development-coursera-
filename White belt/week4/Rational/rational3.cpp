#include <iostream>
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


int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
