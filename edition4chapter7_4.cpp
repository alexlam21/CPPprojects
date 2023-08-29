#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class HotDogStand
{
    public:
    HotDogStand(int idNum, int amountSold);
    void justSold();
    int getAmountSold() const;
    static int getTotalAmountSold();

    private:
    int ID;
    int hotDogsSold;
    static int totalHotDogsSold;
};

int HotDogStand:: totalHotDogsSold  = 0;

int main()
{
    srand(time(NULL));
    int numberOfCustomers = 1000, customerPick;
    HotDogStand ChiliDogStand(1,0), RegularDogStand(2,0), NewYorkDogStand(3,0);

    cout << "Welcome to the Hot Dog Stand House!\n1000 customers came in and made their choices!" << endl;
    
    for(int i = 0 ; i < numberOfCustomers; i++)
    {
        customerPick = rand() % 3 + 1;

        switch (customerPick)
        {
        case 1:
            ChiliDogStand.justSold();
            break;
        case 2:
            RegularDogStand.justSold();
            break;
        case 3:
            NewYorkDogStand.justSold();
            break;
        default:
            cout << "An error occurred in customerPick!" << endl;
            exit(1);
            break;
        }
    } 

    cout << "What a great day for business!" << endl
         << "The Chili Dog Stand sold: " << ChiliDogStand.getAmountSold() << endl
         << "The Regular Dog Stand sold: " << RegularDogStand.getAmountSold() << endl
         << "The NewYork Dog Stand sold: " << NewYorkDogStand.getAmountSold() << endl
         << "The total amount of hot dogs sold today is: " << HotDogStand::getTotalAmountSold() << endl;

    return 0;
}

HotDogStand::HotDogStand(int idNum, int amountSold) : ID(idNum), hotDogsSold(amountSold)
{}

void HotDogStand::justSold()
{
    ++hotDogsSold;
    ++totalHotDogsSold;
    return;
}
int HotDogStand::getAmountSold() const
{
    return hotDogsSold;
}
int HotDogStand::getTotalAmountSold()
{
    return totalHotDogsSold;
}