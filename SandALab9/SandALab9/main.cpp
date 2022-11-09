// Jeremiah Todaro
//  Select one program (Encapsulation, Inheritance, polymorphsm, and virtual function) .  Then submit them as one lab assignment
// 11.30.22

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const double STATETAX = .0625;

// Inheritace Type2: Multiple
// Polymorphism Type: Runtime
// Virtual Function: Pure Virtual Function
// Encapsulaton: Example is in 1st class

//=================
class Base1
{
public:
    double taxDeduct;
    double salary;
    string fName = "Jerry ";
    
    double ask()
    {
        cout << "Enter your salary: " << endl;
        cin >> salary;
        while(cin.fail() || salary < 0)
        {
            cout << "Error input not valid try again" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> salary;
        }
        return salary;
    }
    void taxDeduction()
    {
        ask();
        double tempSalary = salary;
        taxDeduct = tempSalary * STATETAX;
        cout << "Your state tax deduction from your salary is: " <<  taxDeduct << endl;
    }
};
//===================
class Base2
{
public:
    double bonus;
    double taxDeduct;
    string lName = "Springer";
    
    double ask2()
    {
        cout << "Enter your bonus: " << endl;
        cin >> bonus;
        while(cin.fail() || bonus < 0)
        {
            cout << "Error input not valid, program ending..." << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> bonus;
        }
        return bonus;
    }
    void taxDeductBonus()
    {
        ask2();
        taxDeduct = bonus * STATETAX;
        cout << "Your state tax deduction from your bonus is: " << taxDeduct << endl;
    }
};
//====================
class Base3
{
public:
    virtual void playdough() = 0;
};
//====================
class InheritanceClass : public Base1, public Base2 // Inheritance Example
{
public:
    void sum()
    {
        
        cout << "Name: " << (fName + lName) << endl;
    }
};
//===================
class InheritanceClass2 : public Base3
{
public:
    void playdough()
    {
        cout << "Current sales goal: " << "70000" << endl;
    }
};
//===================
int main() {
    //Polymorhphism
    Base1 y = Base1();
    y.taxDeduction();
    InheritanceClass z = InheritanceClass();
    z.taxDeductBonus();

    
    //Inheritance
    InheritanceClass x;
    x.sum();

    //Virtual Function
    Base3 *aptr;
    InheritanceClass2 a;
    aptr = &a;
    aptr->playdough();

    return 0;
}
