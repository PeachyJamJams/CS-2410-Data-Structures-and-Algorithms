// Jeremiah Todaro
// 10.31.22
/*
 Use Program 5 and
 Now in a particular factory , a team leader is an hourly paid production worker who leas a small team.  In addition to hourly pay, team leaders earn a fixed  monthly  bonus.  Team leaders are required to attend a minimum number of hours of training per year.
 Design a   TeamLeader class that extends   ProductionWorker class  you designed in part 1 of this assignment.   The    TeamLeader  class should have member variable for the monthly bonus amount, the required number of training hours, and the number of training hours that the team leader has attended.
 Write one or more constructors and the appropriate accessor and mutator functions for the class.  Demonstrate the class by writing a program that uses a   TeamLeader object.
 */

//const int CENSUS = 25;

#include "Classes Definition.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


int main() {
    ProductionWorker employee;
    employee.display();
    TeamLeader leader;
    leader.teamLeaderDisplay();
    return 0;
}
//=====================================================================HEADER FILE CONTENTS BELOW================================================================
/*
 #include <stdio.h>
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <regex>
 #include <vector>

 using namespace std;
 regex pattern ("[A-Za-z]+");

 class Employee
 {
 private:
     string eName;
     int eNum;
     int eHD;
 public:
     void setEName(string employeeName)
     {eName = employeeName;}
     void setENum(int employeeNumber)
     {eNum = employeeNumber;}
     void setEHD(int hireDate)
     {eHD = hireDate;}
     string getEname()
     {return eName;}
     int getENum()
     {return eNum;}
     int getEHD()
     {return eHD;}
     void employeeData()
     {eName = ""; eNum = 0; eHD = 0;}
     string askName();
     int askNum();
     int askHireDate();
 };
     
 class ProductionWorker : public Employee
 {
     private:
     int shift;
     double hourRate;
     public:
     void setShift(int shiftNumber)
     {shift = shiftNumber;}
     void setHourRate(double tempHourRate)
     {hourRate = tempHourRate;}
     int getShift()
     {return shift;}
     double getHourRate()
     {return hourRate;}
     void employeeData2()
     {shift = 0; hourRate = 0;}
     int askShift();
     double askHourRate();
     void display();
 };
 class TeamLeader : public ProductionWorker
 {
 private:
     int bonus;
     int trainingHours;
     int trainingHoursAttended;
 public:
     void setBonus(int leaderBonus)
     {bonus = leaderBonus;}
     void setTrainingHours(int requiredHours)
     {trainingHours = requiredHours;}
     void setTrainingHoursAttended(int hoursCompleted)
     {trainingHoursAttended = hoursCompleted;}
     int getBonus()
     {return bonus;}
     int getTrainingHours()
     {return trainingHours;}
     int getTrainingHoursAttended()
     {return trainingHoursAttended;}
     int askBonus();
     int askTrainingHours();
     int askTrainingHoursAttended();
     int hoursRemaining();
     int question();
     void teamLeaderDisplay();
 };
 //===================================================================FUNCTION DEFINITIONS========================================================================
 string Employee::askName()
 {
     string tName;
     cout << "Welcome, please enter employee name: " << endl;
     getline(cin, tName);
     while (cin.fail())
     {
         cout << "Please enter a valid name, try again." << endl;
         cin.clear();
         cin.ignore(256,'\n');
         cin >> tName;
     }
     return tName;
 }

 int Employee::askNum()
 {
     int tID;
     cout << "Enter employee ID " << endl;
     cin >> tID;
         
     while (cin.fail() || tID < 1 || tID > 5000)
     {
         cout << "Error, enter a valid employee ID: " << endl;
         cin.clear();
         cin.ignore(256,'\n');
         cin >> tID;
     }
     return tID;
 }

 int Employee::askHireDate()
 {
     int tHireDate;
     cout << "Enter date in MMDDYYYY (no spaces) format: " << endl;
     cin >> tHireDate;
     while (cin.fail() || tHireDate < 0 || tHireDate > 12312022) //How to make this better???
     {
         cout << "The date entered is not valid, try again." << endl;
         cin.clear();
         cin.ignore(256,'\n');
         cin >> tHireDate;
     }
     return tHireDate;
 }
 //===============================================================================================================================================================
 int ProductionWorker::askShift()
 {
     int tShift;
     cout << "Select which shift you will be working\n 1) For day shift\n 2) For night shift " << endl;
     cin >> tShift;
     while(cin.fail() || tShift > 2 || tShift < 1)
     {
         cout << "Invalid number, try again." << endl;
         cin.clear();
         cin.ignore(256,'\n');
         cin >> tShift;
     }
     if (tShift == 1 || 2)
     {
         return tShift;
     }
 }

 double ProductionWorker::askHourRate()
 {
     double tHourRate;
     cout << "Enter employees hourly wage: " << endl;
     cin >> tHourRate;
     while(cin.fail() || tHourRate < 7.5)
     {
         cout << "Invalid try again." << endl;
         cin.clear();
         cin.ignore(256,'\n');
         cin >> tHourRate;
     }
     return tHourRate;
 }
 void ProductionWorker::display()
 {
     string name;
     int employeeNumber, employeeHireDate, employeeShift;
     double employeeHourRate;
     
     name = askName();
     setEName(name);
     employeeNumber = askNum();
     setENum(employeeNumber);
     employeeHireDate = askHireDate();
     setEHD(employeeHireDate);
     employeeShift = askShift();
     setShift(employeeShift);
     employeeHourRate = askHourRate();
     setHourRate(employeeHourRate);
     
     cout << "================================================" << endl;
     cout << "=================EMPLOYEE DATA==================" << endl;
     cout << left;
     cout << "\nEmployee Name: " << getEname() << endl;
     cout << "\nEmployee Number: " << getENum() << endl;
     cout << "\nEmployee Hire Date: " << getEHD() << endl;
     if (getShift() == 1)
     {cout << "\nEmployee Shift: Day " << endl;}
     else if (getShift() == 2)
     {cout << "\nEmployee Shift: Night" << endl;}
     cout << "\nEmployee Wage: " << getHourRate() << endl;
 }
 //===============================================================================================================================================================
 int TeamLeader::askBonus()
 {
     int tBone;
     cout << "Enter team leader bonus:" << endl;
     cin >> tBone;
     while(cin.fail() || tBone > 30000 || tBone < 1)
     {
         cout << "Invalid bonus, try again." << endl;
         cin.clear();
         cin.ignore(256,'\n');
         cin >> tBone;
     }
     return tBone;
 }
 int TeamLeader::askTrainingHours()
 {
     int tHours;
     cout << "Enter amount of hours required for team leader: " << endl;
     cin >> tHours;
     while(cin.fail() || tHours > 100 || tHours < 0)
     {
         cout << "Invalid. Do not assign over 100 hours, against company hours." << endl;
         cin.clear();
         cin.ignore(256,'\n');
         cin >> tHours;
     }
     return tHours;
 }
 int TeamLeader::askTrainingHoursAttended()
 {
     int tHoursAttended;
     cout << "Enter amount of hours team leader has attended: " << endl; //FIX
     cin >> tHoursAttended;
     while(cin.fail() || tHoursAttended > 100 || tHoursAttended < 0 || tHoursAttended > trainingHours)
     {
         cout << "Invalid. Over 100 hours or Over hours required." << endl;
         cin.clear();
         cin.ignore(256,'\n');
         cin >> tHoursAttended;
     }
     return tHoursAttended;
 }
 void TeamLeader::teamLeaderDisplay()
 {
     int theBonus, requiredHours, hoursAttended, decision;

     cout << endl << "Is employee a team leader? 1 for yes, 2 for no." << endl;
     cin >> decision;
     if (decision == 1)
     {
         theBonus = askBonus();
         setBonus(theBonus);
         requiredHours = askTrainingHours();
         setTrainingHours(requiredHours);
         hoursAttended = askTrainingHoursAttended();
         setTrainingHoursAttended(hoursAttended);
         cout << "===================================================" << endl;
         cout << "=================TEAM LEADER DATA==================" << endl;
         cout << left;
         cout << "Team Leader Bonus: " << getBonus() << endl;
         cout << "Team Leader Hours Required: " << getTrainingHours() << endl;
         cout << "Hours Attended: " << getTrainingHoursAttended() << endl;
     }
     else if (decision == 2)
     {
         cout << "Have a great day" << endl;
         exit(1);
     }
 }
 #endif
 */
