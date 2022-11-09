// Jeremiah Todaro
// 10.27.22
/*
 (The Account class) Design a class name Account that contains :

 After LAB 6 is done , we like to use the Account class created above to simulate an ATM machine.  Create 10 accounts in an array with id 0 ...9
 and initial balance $100.  The system prompts the user to enter an id , if the id is entered incorrectly, ask the user to enter a correct one.  Once an id is accepted , the mail menu is displayed (look at sample below) .
  
 You can enter a choice
 1 for viewing the current Balance
 2 for withdrawing money
 3 for depositing money
 4 for exiting the main menu.
  
 Once you exit the system will prompt for an id again .  So once the system starts it will not stop.
  
 Sample menu
  
 Enter an id :   4      ENTER
 Main Menu
 1. Check Balance
 2. Withdraw
 3. Deposit
 4. Exit
 Enter a Choice   ENTER
 The Balance is 100.00
 */
/*
            UML
===============================
           ACCOUNT
===============================
 - Id int
 - Balance Double
 - AnnualInterestrate Double
================================
 + setID()
 + setBalance()
 + setAnnualInterestRate()
 + getID()
 + getBalance()
 + getAnnualInterestRate()
 + getMonthlyInterestRate
 + withdraw()
 + deposit()
 */
const int accountNumber = 10;

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include "AccountClass.h"

int main() {
    Account account[accountNumber]; // Creating array of objects using constant
    
    for (int i = 0; i < accountNumber; i++) // For loop to set objects' variables
    {
        account[i].setID(i);
        account[i].setBalance(100);
        account[i].setAnnualInterestRate(.025);
    }
    menu(account); // Calling Main Function
    
    return 0;
}



/*HEADER CONTENTS BELOW
 ----------------------------------------------------------------------
 #ifndef AccountClass_h
 #define AccountClass_h

 using namespace std;
 class Account // Definiton of Class
 {
 private: // Private members
     int id;
     double balance;
     double annualInterestRate;
     
 public: // Public functions with constructor, 3 set functions, 3 get functions, and 2 functions for withdraw and deposit
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
     
     Account() //Constructor
     {
         id = 0;
         balance = 0.0;
         annualInterestRate = 0.0;
     }
          
     };

 int verificaton() // Function to verify ID
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

 void menu(Account num[]) Menufunction with array object as parameter
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
     
     switch (choice) //switch for each different menu choice
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
 #endif  AccountClass_h 
 */

