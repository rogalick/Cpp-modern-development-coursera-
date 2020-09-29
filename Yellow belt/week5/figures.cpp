#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <memory>
using namespace std;

class Figure {
public:
    Figure(const string& Name) :name(Name) {
    }
    virtual string Name() const = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
protected:
    const string name;
};
class Rect : public Figure {
public:
    Rect(double width, double height) : Figure("RECT"), width_(width), height_(height) {
    }
    string Name() const override {
        return name;
    }
    double Perimeter() override {
        return (width_ * 2) + (height_ * 2);
    }
    double Area() override {
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};

class Triangle : public Figure {
public:
    Triangle(const double& a, const double& b, const double& c) : Figure("TRIANGLE"), a_(a), b_(b), c_(c) {
    }
    string Name() const override {
        return name;
    }
    double Perimeter() override {
        return a_ + b_ + c_;
    }
    double Area() override {
        double p = (a_ + b_ + c_) / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

private:
    double a_;
    double b_;
    double c_;
};

class Circle : public Figure {
public:
    Circle(const double& radius_) : Figure("CIRCLE"), radius(radius_) {
    }
    string Name() const override {
        return name;
    }
    double Perimeter() override {
        return 2 * 3.14 * radius;
    }
    double Area() override {
        return 3.14 * (radius * radius);
    }

private:
    double radius;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string type;
    is >> type;
    if (type == "RECT") {
        double width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    }
    else if (type == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    else if (type == "CIRCLE") {
        double radius_;
        is >> radius_;
        return make_shared <Circle>(radius_);
    }
    return 0;
}
int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}


