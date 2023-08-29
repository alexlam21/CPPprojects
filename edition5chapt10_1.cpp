#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

typedef double* pointertodouble;

class TwoD
{
    public:
    TwoD();
    TwoD(unsigned int numberOfRows, unsigned int numberOfCols);
    TwoD(const TwoD& tDArray);
    ~TwoD();
    void addElement();
    double getElement(unsigned int row, unsigned int column) const;
    TwoD& operator=(const TwoD& rhs);
    friend TwoD operator + (const TwoD& augend, const TwoD& addend);
    //pre-condition: the two arguments are matrices of the same size
    //otherwise the program ends.
    //post condition returns matrix whose entries are the sum of the entries
    //of the two arguments.
    friend ostream& operator << (ostream& Cout, const TwoD& matrix);

    private:
    unsigned int maxRows;
    unsigned int maxCols;
    pointertodouble *t;
};

int main()
{
    srand(time(NULL));

    TwoD a, b(3,3);
    TwoD c(b); //explicit call to copy contructor


    cout <<"The scalar value is " <<  scalar << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
   
    cout << "a has been set to:\n" << a << endl;
    cout << "b has been set to:\n" << b << endl;
    cout << "c has been set to b:\n" << c << endl;

    cout << "b+c = :\n" << b+c << endl;
    return 0;
}

TwoD::TwoD(): maxRows(2), maxCols(2)
{
    t = new pointertodouble[maxRows];

    for (unsigned int i = 0; i < maxRows; i++)
        t[i] = new double[maxCols];
    //fill array with random decimals
    for(unsigned int i = 0; i < maxRows; i++)
        for (unsigned int j = 0; j < maxCols; j++)
            t[i][j] = rand() / static_cast<double>(rand());
}
TwoD::TwoD(unsigned int numberOfRows, unsigned int numberOfCols):
maxRows(numberOfRows), maxCols(numberOfCols)
{
    t = new pointertodouble[maxRows];

    for (unsigned int i = 0; i < maxRows; i++)
        t[i] = new double[maxCols];
    //fill array with random decimals
    for(unsigned int i = 0; i < maxRows; i++)
        for (unsigned int j = 0; j < maxCols; j++)
            t[i][j] = rand() / static_cast<double>(rand());
}
// copy constructor
TwoD::TwoD(const TwoD& tDArray)
: maxRows(tDArray.maxRows), maxCols(tDArray.maxCols)
{
    t = new pointertodouble[maxRows]; //create array of pointers.

    for (int i = 0; i < maxRows; i++)
        t[i] = new double[maxCols];//create array of double for each pointer.
// copy individual values into the array of the object receiving data.
    for (int i = 0; i < maxRows; i++)
        for (int j = 0; j < maxCols; j++)
            t[i][j] = tDArray.t[i][j];
}
// end copy constructor
// start destructor
TwoD::~TwoD()
{
    for (unsigned int i = 0; i < maxRows; i++)
        delete [] t[i];
    delete [] t;
}
// end destructor
void TwoD::addElement()
{
    unsigned int rowPosition, colPosition;
    double value;
    bool inserted = false;

    do
    {
        cout << "Choose row (0 to " << maxRows - 1 << ") :";
        cin >> rowPosition;

        cout << "Choose column (0 to " << maxCols - 1 << ") :";
        cin >> colPosition;

        if (rowPosition >= maxRows || colPosition >= maxCols)
        {
            cout << "INVALID MATRIX POSITION: [" 
                 << rowPosition << "," << colPosition << "]\n";
            continue;
        }

        cout << "Enter the value to be inserted in position [" 
             << rowPosition << "," << colPosition << "] :";
        cin >> value;
        t[rowPosition][colPosition] = value;
        
        inserted = true;
        cout << "Value has been inserted.\n";
    } while (!inserted);
}
double TwoD::getElement(unsigned int row, unsigned int col) const
{
    return t[row][col];
}
TwoD& TwoD::operator = (const TwoD& rhs)
{
    if (this != &rhs)
    {
        for (unsigned int i = 0; i < maxRows; i++)
            delete [] t[i];
        delete [] t;

        maxRows = rhs.maxRows;
        maxCols = rhs.maxCols;
    
        t = new pointertodouble[maxRows];
        for (unsigned int i = 0; i < maxRows; i++)
            t[i] = new double[maxCols];
        
        for(unsigned int i = 0; i < maxRows; i++) 
            for (unsigned int j = 0; j < maxCols; j++)
                t[i][j] = rhs.t[i][j];
        
        return *this;
    }
    return *this;
}
TwoD operator + (const TwoD& augend, const TwoD& addend)
{
    //Because it is required to contain a destructor no object that
    //one can make here will survive at the end of the function call.

    //Therefore it is required that the return type is a deep copy of the
    //local object created here. Return by value is critical!
    if( (augend.maxRows != addend.maxRows) 
        && (augend.maxCols != addend.maxCols) );
    {
        cout << "Warning! Sum is undefined for matrices of different dimensions!\n";
        exit(0);
    }

    TwoD sum(augend);

    for(unsigned int i = 0; i < sum.maxRows; i++)
        for(unsigned int j = 0; j < sum.maxCols; j++)
            sum.t[i][j] = augend.t[i][j] + addend.t[i][j];
    return(sum);
}
ostream& operator << (ostream& Cout, const TwoD& matrix)