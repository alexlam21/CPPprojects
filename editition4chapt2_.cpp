#include <iostream>
using namespace std;

int main()
{
    int celcius = 100;
    int fahrenheit = ((9/5.0) * celcius) + 32;

    while (celcius != fahrenheit)
    {
        --celcius;
        fahrenheit = ((9.0/5.0) * celcius) + 32; 
    }

    cout << celcius << " degrees celcius is the same in fahrenheit" << endl;
}