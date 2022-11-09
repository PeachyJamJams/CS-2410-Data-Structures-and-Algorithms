//
//  AccountClass.h
//  SandALab6
//
//  Created by Jet Todaro on 10/6/22.
//

#ifndef AccountClass_h
#define AccountClass_h

using namespace std;
class Account
{
private:
    int id;
    double balance;
    double annualInterestRate;
    
public:
    void setID(int x)
    {
        id = x;
    }
    void setBalance(double x)
    {
        balance = x;
    }
    void setAnnualInterestRate(double x)
    {
        annualInterestRate = x;
    }
    
    int getID()
    {return id;}
    double getBalance()
    {return balance;}
    double getAnnualInterestRate()
    {return annualInterestRate;}
    
    double getMonthlyInterestRate()
    {
        return annualInterestRate / 12;
    }
    void withdraw(double amount)
    {
        balance = balance - amount;
    }
    void deposit(double amount)
    {
        balance = balance + amount;
    }
    
    Account()
    {
        id = 0;
        balance = 0.0;
        annualInterestRate = 0.0;
    }
         
    };

int verificaton()
{
    int tempID;
    
    cout << "\nWelcome, before accessing ATM please enter your ID for verification: " << endl;
    cin >> tempID;
    
while (cin.fail() || tempID < 0 || tempID > accountNumber)
{
    cout << "Error, ID does not match" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> tempID;
}
    return tempID;
}

void menu(Account num[])
{
   int iDNumber = verificaton();
    double cashD,cashW;
    int choice;
    
    cout << left;
    cout << endl << "\nMenu" << endl;
    cout << "Check Balance: 1 " << endl;
    cout << "Withdraw: 2 " << endl;
    cout << "Deposit: 3" << endl;
    cout << "Exit: 4" << endl;
    cin >> choice;
    
    switch (choice)
    {
        case 1:
            cout << "Balance: " << num[iDNumber].getBalance() << endl;
            menu(num);
            
        case 2:
            cout << endl << "\nHow much would you like to withdraw: " <<  endl;
            cin >> cashW;
            while (cin.fail() || cashW > num[iDNumber].getBalance())
            {
                cout << "You do not have that much money lol" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cout << endl << "Re-Enter Withdraw Amount: " << endl;
                cin >> cashW;
            }
            num[iDNumber].withdraw(cashW);
            cout << "Balance: " << num[iDNumber].getBalance() << endl;
            menu(num);
            
        case 3:
            cout << endl << "\nHow much are you depositing: " << endl;
            cin >> cashD;
            while (cin.fail() || cashD < 1)
            {
                cout << "You can not depost a negative amount lol" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cout <<  endl << "Re-Enter Deposit Amount: " << endl;
                cin >> cashD;
            }
            num[iDNumber].deposit(cashD);
            cout << "Balance: " << num[iDNumber].getBalance() << endl;
            menu(num);
            
        case 4:
            menu(num);
            
        default:
            cout << "Error! Number 1-4 was not entered, try again." << endl;
            menu(num);
            break;
    }
}
#endif /* AccountClass_h */
