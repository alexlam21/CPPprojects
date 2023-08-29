#include <iostream>
#include <cmath>
using namespace std;

const double GRAVITY = 6.673e-8;
double findForce (double mass1, double mass2, double distance);

double returnMyNumber(double& input);

int main()
{
     double m1,m2,d;
    // cout << "Input mass 1 in grams" << endl;
    // cin >> m1;
    // cout << "Input mass 2  in grams" << endl;
    // cin >> m2;
    // cout << "Input distance in cm" << endl;
    // cin >> d;
    // cout << "The gravitational force is equal to = " << findForce(m1,m2,d) << "dynes" << endl;
    
    cout << "Enter a number ";
    cin >> m1;
    cout << returnMyNumber(m1) << endl;
    cout << "My original number is still " << m1 << endl;
    return 0;

}
double findForce (double mass1, double mass2, double distance)
{
    
    return (GRAVITY * mass1 * mass2)/ pow(distance,2);
}
double returnMyNumber(double& input)
{
    input = input + 1;
    return input;
}