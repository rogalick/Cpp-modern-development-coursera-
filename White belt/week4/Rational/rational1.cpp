#include <iostream>
#include <algorithm>
using namespace std;
//В первой части Вам надо реализовать класс Rational, который представляет собой рациональное число вида p/q,
//где p — целое, а q — натуральное и диапазоны возможных значений p, q таковы, что могут быть представлены типом int
//Список требований, предъявляемых к реализации интерфейса класса Rational:

//Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
//При конструировании объека класса Rational с параметрами p и q должно выполняться сокращение дроби p / q(здесь вам может пригодиться решение задачи «Наибольший общий делитель»).
//Если дробь p / q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель и положительный знаменатель.
//Если дробь p / q положительная, то объект Rational(p, q) должен иметь положительные числитель и знаменатель(обратите внимание на случай Rational(-2, -3)).
//Если числитель дроби равен нулю, то знаменатель должен быть равен 1.



class Rational {
public:
    Rational() {
        numerator_m = 0;
        denominator_m = 1;
    }

    Rational(int numerator, int denominator) {
        int nod = 0;
        nod = NOD(numerator, denominator);
        if (numerator < 0 && denominator < 0) {
            nod = -nod;
        }
        else if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        numerator_m = numerator / nod;
        denominator_m = denominator / nod;
    }

    int Numerator() const {
        return numerator_m;
    }

    int Denominator() const {
        return denominator_m;
    }

private:
    int NOD(int a, int b) {
        int minNum;
        a = abs(a);
        b = abs(b);
        while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            }
            else {
                b = b % a;
            }
        }
        return a + b;
    }
    int numerator_m;
    int denominator_m;
    // Добавьте поля
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }
    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }
    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}