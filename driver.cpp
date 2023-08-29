#include<iostream>
#include<string>
using namespace std;

class Point
{
    public:
    double getX(); //accessor functions
    double getY();
    void setX(double xValue); //mutator functions
    void setY(double yValue); //mutator functions
    void move(double xamount, double yamount);// post-condition: new x value is x + xamount; 
                                                //new y value is y + yamount.

    void rotate();
    
    private:
    double x;
    double y;
};

int main() {
    string myString;
    myString = "hello there! i am your string.";
    // Point myPoints[2];
    // double userinput, movex, movey;
    // cout << "Enter coordinates for two points." << endl;
    // for(int i = 0; i < 2; i++)
    // {
    //     cout << "Enter point " << i + 1 << "\'s x coordinate:";
    //     cin >> userinput;
    //     myPoints[i].setX(userinput);

    //     cout << "Enter point " << i + 1 << "\'s y coordinate:";
    //     cin >> userinput;
    //     myPoints[i].setY(userinput);
    // }

    // cout << "Move your point. Enter x and y amounts:";
    // cin >> movex >> movey;
    // myPoints[0].move(movex, movey);

    // cout << "That point is now at" << myPoints[0].getX() << "," << myPoints[0].getY() << endl;

    // cout << "I will rotate your 2nd point by 90 degrees.\n";

    // myPoints[1].rotate();
    // cout << "The new coordinates for your 2nd point are: " << myPoints[1].getX() 
    //      << "," << myPoints[1].getY() << endl;

    cout << myString << endl;
    cout << myString.at(0) << endl;
    cout << myString.find("i") << endl;
    return 0;
}
double Point::getX()
{
    return x;
}
void Point::setX(double xValue)
{
    x = xValue;
}
double Point::getY()
{
    return y;
}
void Point::setY(double yValue)//mutator function
{
    y = yValue;
}
void Point::move(double xamount, double yamount)
{
    x = x + xamount;
    y = y + yamount;
}
void Point::rotate()
{
    double temp;
    temp = x;
    x = y;
    y = -temp;
}