#include<iostream>
#include<string>
void writevertical(int n);
void drawNasterisks(int n);
void writeverticalrev(int n);
void upton(int n);
void fromn(int n);
double power(int x, int n);
int mystery(int n);

int main()
{
    using std::cout;
    using std::cin;
    std::string s = "hello world!";
    cout << s.substr(1) << std::endl;
    cout << power(2,-3);
    
    return 0;
}

void writevertical(int n)
{
    using std::cout;
    using std::endl;
    if (n < 10)
        cout << n << endl;
    else
    {
        writevertical(n/10);
        cout << n % 10 << endl;
    }
}

void drawNasterisks(int n)
{
    using std::cout;
    if(n == 1)
        cout << "*";
    else
    {
        drawNasterisks(n-1);
        cout << "*";
    }
}

void writeverticalrev(int n)
{
    if (n < 10)
        std::cout << n << std::endl;
    else
    {
        std::cout << n % 10 << std::endl;
        writeverticalrev(n/10);                             
    }
}

void upton(int n)
{
    if (n == 0)
    {
        return;
    }   
    else if (n == 1)
        std::cout << n << ", ";
    else
    {
        upton(n - 1);
        std::cout << n << ", ";
    }
}

void fromn(int n)
{
    if (n == 1)
        std::cout << n << ", ";
    else
    {
        std::cout << n << ", ";
        fromn(n - 1);
    }
    
}

double power(int x, int n)
{
    if (n == 0)
        return 1;
    if (n > 0)
        return (power(x, n - 1) * x);
    else
        return (1/(power(x,abs(n)-1) * x));
}

int mystery(int n)
{
    if (n <= 1)
        return 1;
    else
        return ( mystery(n - 1) + n);
}