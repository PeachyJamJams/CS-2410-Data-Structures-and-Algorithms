//Jeremiah Todaro
// 09.30.22
/*
 Program 2 - Structure  MAL-C9-P2
 Write a program that reads students' names followed by their test scores. The program should output each student's name followed by the test scores and the relevant grade. It should also find and print the highest test score and the name of the students having the highest test score.
 Student data should be stored in a   struct variable of type   studentType, which has four components:   studentFName and   studentLName of type   string,   testScore of type   int (  testScore is between   0 and   100), and   grade of type   char. Suppose that the class has 20 students. Use an array of 20 components of type   studentType.
 Your program must contain at least the following functions:
 a. A function to read the students' data into the array.
 b. A function to assign the relevant grade to each student.
 c. A function to find the highest test score.
 d. A function to print the names of the students having the highest test score.
 Your program must output each student's name in this form: last name followed by a comma, followed by a space, followed by the first name; the name must be left justified. Moreover, other than declaring the variables and opening the input and output files, the function   main should only be a collection of function calls.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int R = 20;

struct Student
{
    string studentFName;
    string studentLName;
    int testScore;
    char studentGrade;
};

void readData(Student d[])
{
fstream read;
    
read.open("StudentNames.txt");
    for (int i = 0; i < R; i++)
    {
        read >> d[i].studentFName;
        read >> d[i].studentLName;
        read >> d[i].testScore;
    }
    read.close();
}
void getGrade(Student d[])
{
    
    for (int i = 0; i < R; i++)
    {
        double temp_avg = d[i].testScore;
   
        if (temp_avg >= 0 &&temp_avg < 60)
            d[i].studentGrade = 'F';
        else if (temp_avg >= 60 &&temp_avg < 70)
            d[i].studentGrade = 'D';
        else if (temp_avg >= 70 &&temp_avg < 80)
            d[i].studentGrade = 'C';
        else if (temp_avg >= 80 &&temp_avg < 90)
            d[i].studentGrade = 'B';
        else if (temp_avg >= 90 &&temp_avg <= 100)
            d[i].studentGrade = 'A';
    }
}
void swapstu (Student &x, Student &y)
{
    Student z;
    
    z = x;
    x = y;
    y = z;
}

void highestScore(Student d[])
{
    int i,j,min_index;
    for (i = 0; i < R - 1; i++)
    {
        for (j = i + 1; j < R; j++)
            if (d[j].testScore < d[i].testScore)
            {
                swapstu(d[j],d[i]);
            }
    }
    cout << "---------------";
    cout << left << endl << "Highest Score Belongs to: ";
    cout << endl << d[R-1].studentLName << ", " << d[i].studentFName;
    cout << " Test Score: " << d[R-1].testScore << endl;
    cout << endl << "Letter Grade: " <<d[R-1].studentGrade << endl;
    cout << "---------------\n";
}
void printAll(Student d[])
{
    for (int i = 0; i < R; i++)
    {
        cout << left;
        cout << endl << d[i].studentLName << ", " << d[i].studentFName;
        cout << " Test Score: " << d[i].testScore << endl;
        cout << endl << "Letter Grade: " <<d[i].studentGrade << endl;
    }
}
void printgoodies (Student d[])
{
    cout << "Highest Students: " << endl;
    for (int i = 0; i < R; i++)
    {
        if (d[i].testScore > 95)
        {
            cout << left;
            cout << endl << d[i].studentLName << ", " << d[i].studentFName;
            cout << " Test Score: " << d[i].testScore << endl;
            cout << endl << "Letter Grade: " <<d[i].studentGrade << endl;
        }
    }
}

int main() {
    Student d[R];
    
    readData(d);
    getGrade(d);
    printAll(d);
    highestScore(d);
    printgoodies(d);
    
    return 0;
}
