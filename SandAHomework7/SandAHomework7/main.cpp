//  Jeremiah Todaro
//  11.30.22
/*
 Use Recursive function concepts to rewrite
 a. factorial function
 b. fibonacci sequence(theorm)
 c. Tower of Hanoi
 */


#include <iostream>
#include <iomanip>
using namespace std;

class RecursiveMethods //Using classes so I can implement what I have learned
{
public: //All class functions establishes here along with their supplemental functions for rescursive method
    void factorialFunction (int x);
    int factorial(int x);
    void fibonacciFunction(int y);
    int fibonacci(int y);
    void hanoiFunction(int z);
    int hanoi(int z,char p1,char p2,char p3);
};

int main() {
    RecursiveMethods papa; //class object verified here
    
    papa.factorialFunction(0);
    papa.fibonacciFunction(0);
    papa.hanoiFunction(0);
    
    return 0;
}
//================================================================FUNCTION DEFINITIONS===========================================================================
void RecursiveMethods::factorialFunction(int x)
{
    cout << "Enter a positive integer: " << endl;
    cin >> x;
    while (cin.fail()||x < 0)
    {
        cout << "You did not enter a positive integer, try again" << endl;
        cin.clear();
        cin.ignore(256,'n');
        cin >> x;
    }
    cout << "Factorial of " << x << " = " << factorial(x) << endl;
}
int RecursiveMethods::factorial(int x)
{
    if(x > 1)
        return x * factorial(x -1);
    else
    return 1;
}
void RecursiveMethods::fibonacciFunction(int y)
{
    int i = 0;
    cout << "Enter the number of terms in the series: " << endl;
    cin >> y;
    
    while (cin.fail()||y < 0)
    {
        cout << "You did not enter a positive integer, try again" << endl;
        cin.clear();
        cin.ignore(256,'n');
        cin >> y;
    }
    cout << "Fibonacci Series: " << endl;
    
    while(i < y)
    {
        cout << " " << fibonacci(i);
        i++;
    }
    
}
int RecursiveMethods::fibonacci(int y)
{
    if (y==1||y==0)
    {
        return y;
    }
    else
    {
        return (fibonacci(y-1) + fibonacci(y-2));
    }
}
void RecursiveMethods::hanoiFunction(int z)
{
    cout << endl << "Enter number of disks: " << endl;
    cin >> z;
    
    while (cin.fail()||z < 0)
    {
        cout << "You did not enter a positive integer, try again" << endl;
        cin.clear();
        cin.ignore(256,'n');
        cin >> z;
    }
    
    cout << "The steps for " << z << " disk(s) are: " << endl << hanoi(z,'A','B','C');
}
int RecursiveMethods::hanoi(int z,char p1,char p2,char p3)
{
    if(z==1)
    {
        cout << "Move disk " << z << " from " << p1 << " to " << p3 << endl;
        return 0;
    }
    
    hanoi(z-1,p1,p2,p3);
    cout << "Move disk " << z << " from " << p1 << " to " << p2 << endl;
    hanoi(z-1,p3,p2,p1);
    return 0;
}
