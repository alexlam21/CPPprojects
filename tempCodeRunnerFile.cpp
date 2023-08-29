#include <iostream>
#include <cstdlib>
using namespace std;
// objects of this class are partially filled arrays of type double
class PFArrayD
{
   public:
   
   PFArrayD();
   PFArrayD(int capacityValue);
   PFArrayD(const PFArrayD& pfaObj); //copy constructor
   
   void addElement(double element);
   // pre: the array is not full
   // post: the element is added
   bool full() const { return (capacity == used); }
   int getCapacity() const { return capacity; }
   int getNumbersUsed() const { return used; }
   void emptyArray() { used = 0; }
   double& operator [] (int index);
   PFArrayD& operator = (const PFArrayD& rtSide);
   
   ~PFArrayD();

   private:
   
   double* a; //for an array of doubles
   int capacity;
   int used;
};

void testPFArrayD();

int main()
{
   cout << "This program tests the PFArray class.\n";
   char ans;
   do 
   {
      testPFArrayD();
      cout << "Test again?(y/n): ";
      cin >> ans;
   }while(ans == 'y' || ans == 'Y');

   return 0;
}

PFArrayD::PFArrayD():capacity(50), used(0)
{
   a = new double[capacity];
}
PFArrayD::PFArrayD(int capacityValue):capacity(capacityValue), used(0)
{
   a = new double[capacity];
}
PFArrayD::PFArrayD(const PFArrayD& pfaObj):
capacity(pfaObj.getCapacity()), used(pfaObj.getNumbersUsed())
{
   a = new double[capacity];
   for (int i = 0; i < used; i++)
      a[i] = pfaObj.a[i];
}
void PFArrayD::addElement(double element)
{
   if (used >= capacity)
   {
      cout << "ERROR: Array has too many elements!" << endl;
      exit(0);
   }

   a[used] = element;
   used++;
}
double& PFArrayD::operator [](int index)
{
   if (index >= used)
   {
      cout << "ERROR: Illegal index!" << endl;
      exit(0);
   }
   return a[index];
}
PFArrayD& PFArrayD::operator =(const PFArrayD& rtSide)
{
   if (capacity != rtSide.capacity)
   {
      delete [] a;
      a = new double[rtSide.capacity];
   }

   capacity = rtSide.capacity;
   used = rtSide.used;
   for (int i = 0; i < used; i++)
   {
      a[i] = rtSide.a[i];
   }

   return *this;
}
PFArrayD::~PFArrayD()
{
   delete [] a;
}
void testPFArrayD()
{
   int cap;
   cout << "Enter capacity of this super array: "; 
   cin >> cap;
   
   PFArrayD temp(cap);
   
   cout << "Enter up to " << cap << " nonnegative numbers. \n"; 
   cout << "Place a negative number at the end. \n";
   double next;
   cin >> next;
   
   while ( (next >= 0) && (!temp.full()) )
   {
      temp.addElement(next);
      cin >> next;
   }

   cout << "You entered the following "
        << temp.getNumbersUsed() << " numbers: \n" ;
   
   int index;
   int count = temp.getNumbersUsed();
   for (index = 0; index < count; index++)
   {
      cout << temp[index] << " ";
      
   }

   cout << endl;
   cout << "(plus a sentinel value.)\n";
}