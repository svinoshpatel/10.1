#include <iostream>

using namespace std;

class Shape {
public:
    virtual double Calc_Area() const = 0;
};



class Circle : public Shape {
private:
    double R;
public:
    Circle(double);
    double Calc_Area() const override;
};

const double PI = 3.14159265;

Circle::Circle(double r) : R(r) {}

double Circle::Calc_Area() const {
    return PI * R * R;
}



class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double, double);
    double Calc_Area() const override;
};

Triangle::Triangle(double b, double h) : base(b), height(h) {}

double Triangle::Calc_Area() const {
    return 0.5 * base * height;
}



int main() {
    Shape *s;

    Circle c(5);
    Triangle t(3, 8);

    s = &c;
    cout << "s->Calc_Area() = " << s->Calc_Area() << endl;

    s = &t;
    cout << "s->Calc_Area() = " << s->Calc_Area() << endl;

    return 0;
}
