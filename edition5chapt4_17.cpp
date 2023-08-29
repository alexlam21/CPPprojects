#include <iostream>
using namespace std;

void sort(int& a, int& b, int& c);
void swap(int& a, int& b);


int main ()
{
    //need the variable to be initialized!!!
    int a, b, c;

    cout << "input the 1st number" << endl;
    cin >> a;
    cout << "input the 2nd number" << endl;
    cin >> b;
    cout << "input the 3rd number" << endl;
    cin >> c;

    // now call the function with the values that were given.
    sort(a, b, c);

    cout << "The sorted values are: " << a << ", " << b << ", " << c << endl;
    return 0;
}
void sort(int& a, int& b, int& c)
{
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
}
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}