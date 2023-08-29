#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void hidePrize(int&, int&, int&, int&);
int contestantSelectDoor();
int revealGoatDoor(int, int, int, int);
void playMontyHall(double&, double&, double&, double&);

int main() 
{
    double win = 0;
    double lose = 0;
    double sWin = 0;
    double sLose = 0;
    
    srand(time(NULL));
    for(int i = 1; i <=10000; i++)
    {
        playMontyHall(win, lose, sWin, sLose);
    }
    
    cout << "Probability of winning without switching door selection: " 
         << win / (win+lose) << endl 
         << "Probability of winning with switching door selection: "
         << sWin / (sWin + sLose) << endl;

    return 0;
}

void hidePrize(int& door1, int& door2, int& door3, int& prizeDoor)
{
    door1 = door2 = door3 = prizeDoor = 0;
    
    int doorNumberToReceivePrize = rand() % 3 + 1;
    prizeDoor = doorNumberToReceivePrize;
    
    switch(doorNumberToReceivePrize)
    {
        case 1:
            door1 = 1;
            break;
        case 2:
            door2 = 1;
            break;
        case 3:
            door3 = 1;
            break;
        default:
            cout << "Something went wrong in door selection!\n";
    }
    
    return;
}

int contestantSelectDoor()
{
    return rand() % 3 + 1;
}

int revealGoatDoor(int door1, int door2, int door3, int selectedDoor)
{
    int goatDoor1, goatDoor2 = 0;
    
    
    if(door1 == 1)
    {
        goatDoor1 = 2;
        goatDoor2 = 3;
    }
    else if(door2 == 1)
    {
        goatDoor1 = 1;
        goatDoor2 = 3;
    }
    else if(door3 == 1)
    {
        goatDoor1 = 1;
        goatDoor2 = 2;
    }
    
    if(goatDoor1 == selectedDoor)
        return goatDoor2;
    else if (goatDoor2 == selectedDoor)
        return goatDoor1;
    else
    {
        int choiceMaker = rand() % 2;
        
        if(choiceMaker)
            return goatDoor1;
        else
            return goatDoor2;
    }
}
void playMontyHall(double& win, double& lose, double& switchWin, double& switchLose)
{
   
    int door1, door2, door3 = 0, selectedDoor, revealedGoatDoor, prizeDoor;
    
    hidePrize(door1, door2, door3, prizeDoor);
    //cout << "Door 1: " << door1 << endl
    //     << "Door 2: " << door2 << endl
    //     << "Door 3: " << door3 << endl;
    
    selectedDoor = contestantSelectDoor();
    //cout << endl << "Contestant selected Door: " << selectedDoor << endl;
    
    revealedGoatDoor = revealGoatDoor(door1, door2, door3, selectedDoor);
   //cout << "A goat is behind Door: " << revealedGoatDoor << endl;
   
    
    int remainingDoor = 6 - selectedDoor - revealedGoatDoor;
    
    //cout << "The door that remains is door " << remainingDoor << endl;
    
    //counting the wins and losses of the two strategies.
    if(selectedDoor == prizeDoor)
    {
        ++win;
        ++switchLose;
    }
    else
    {
        ++lose;
        ++switchWin;
    }
    
    return;
}