#include <iostream>
using namespace std;

int main()
{
    const double PAYINC = 0.076;
    double previous_salary;
    cout << "Enter the previous annual salary: ";
    cin >> previous_salary;

    double new_salary;
    new_salary = previous_salary + (previous_salary * PAYINC);
    cout << "The new salary is " << new_salary << endl;

    double retro_pay;
    retro_pay = ((new_salary - previous_salary)/12) * 6;
    cout << "The new retroactive pay due the employee is " << retro_pay << endl;

    double new_monthly_salary; 
    new_monthly_salary = new_salary/12;
    cout << "The new monthly salary is " << new_monthly_salary << endl;

    return 0;
}