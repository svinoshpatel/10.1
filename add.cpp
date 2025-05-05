#include <iostream>

using namespace std;

class Employee {
public:
    virtual double Get_Salary() const = 0;
};



class Manager : public Employee {
private:
    double baseSalary, bonus;
public:
    Manager(double base, double bonus);
    double Get_Salary() const override;
};

Manager::Manager(double base, double bon) : baseSalary(base), bonus(bon) {}

double Manager::Get_Salary() const {
    return baseSalary + bonus;
}



class Worker : public Employee {
private:
    double hoursWorked, hourlyRate;
public:
    Worker(double hours, double rate);
    double Get_Salary() const override;
};

Worker::Worker(double hours, double rate) : hoursWorked(hours), hourlyRate(rate) {}

double Worker::Get_Salary() const {
    return hoursWorked * hourlyRate;
}



int main() {
    Employee *e;

    Manager m(3000, 1200);
    Worker w(160, 20);

    e = &m;
    cout << "Manager salary: " << e->Get_Salary() << endl;

    e = &w;
    cout << "Worker salary: " << e->Get_Salary() << endl;

    return 0;
}
