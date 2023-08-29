#include <iostream>
using namespace std;


class CounterType
{
    public:
    void setCount(int count);
    // Pre-condition: count must be non-negative or else value will be ignored!
    // Post-condition: Sets the counter to the input;
    void incrementCount();
    // Post-condition: Increments the counter by one.
    void decrementCount();
    // Post-condition: Decrements the counter by one unless the counter is already at zero!
    int getCount();
    // Post-condition: Returns the current value of the counter.
    void showCount();
    // Post-condition: Displays the current value of the counter.

    private:
    int counter;
};

int main()
{
    CounterType Iphones, laptop, desktop;
    Iphones.setCount(2);
    laptop.setCount(3);
    desktop.setCount(0);

    cout << "The number of Iphones I have is " << Iphones.getCount() << endl;
    Iphones.showCount();
    cout << "Then I broke one and the count is ";
    Iphones.decrementCount();
    cout << Iphones.getCount() << endl;

    cout << "I have no desktop so the count is " << desktop.getCount() << endl;
    desktop.decrementCount();
    cout<< "losing one means that the count is " << desktop.getCount() << endl;

    return 0;
}

void CounterType::setCount(int count)
{
    if(count >= 0)
        counter = count;
    else
    {
        cout << "The count cannot be negative! Count automatically set to 0!";
        counter = 0;
    }
    return;
}
void CounterType::incrementCount()
{
    ++counter;
    return;
}
void CounterType::decrementCount()
{
    if(counter == 0)
        return;
    --counter;
    return;
}
int CounterType::getCount()
{
    return counter;
}
void CounterType::showCount()
{
    cout << "The current value of the counter is " << counter << endl;
    return;
}