// Jeremiah Todaro
//  09.30.22
//  Conver Convert  Student Record Program to use class and objectsusing concepts of (OOP)

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int R=20; //Global Constant

class StudentData //Establishing the class with variables
{
private:
    string studentFName;
    string studentLName;
    int testScores;
    char letterGrade;
    
public:
    void printData();
    
    void highestScore();
    
    void highestStudents();
    
    void getGrade();
    
    void setFName(string tempFName){
        studentFName = tempFName;
    }
    void setLName(string tempLName){
        studentLName = tempLName;
    }
    void setTestScores(int tempTestScores){
        testScores = tempTestScores;
    }
    void setLetterGrade(char tempLetterGrade){
        letterGrade = tempLetterGrade;
    }
};

StudentData sClass[R];

void read(StudentData sClass[R]) //read function to read text file
{
    fstream strike;
    
    strike.open("ClassData.txt");
    
    for (int i = 0; i < R; i++)
     
    {
        string tempFName;
        string tempLName;
        int tempTestScores;
        
        strike >> tempFName;
        sClass[i].setFName(tempFName);
        strike >> tempLName;
        sClass[i].setLName(tempLName);
        strike >> tempTestScores;
        sClass[i].setTestScores(tempTestScores);
        sClass[i].getGrade();
    }
    sClass[R].highestScore();
    sClass[R].highestStudents();
    strike.close();

}
void StudentData::getGrade() //this function assigns a letter grade to each student based off score
{
for (int i = 0; i < R; i++)
{
    {
        
        if (testScores >= 0 &&testScores < 60)
            letterGrade = 'F';
        
        else if (testScores >= 60 &&testScores < 70)
           letterGrade = 'D';
        
        else if (testScores >= 70 &&testScores < 80)
           letterGrade = 'C';
        
        else if (testScores >= 80 &&testScores < 90)
           letterGrade = 'B';
        
        else if (testScores >= 90 &&testScores <= 100)
            letterGrade = 'A';
    
    }
}
}
void swapstu (StudentData &x, StudentData &y) //this function is needed for the selection sort method in order to swap
{
    StudentData z;
    z=x;
    x=y;
    y=z;
}
void StudentData::highestScore() //this function uses the selection sort method to sort students based off grade
{
    int i,j;
    for(i=0; i<R-1; i++)
    {
        for (j=i+1; j<R; j++)
            if (sClass[j].testScores<sClass[i].testScores)
        {
            swapstu(sClass[j],sClass[i]);
        }
    }
    cout << endl << "The highest scoring student is:  ";
    cout << endl << sClass[R-1].studentLName << ", " << sClass[R-1].studentFName << endl;
    cout << "Test Score: " << sClass[R-1].testScores << endl;
    cout << "Letter Grade: " << sClass[R-1].letterGrade << endl;
    cout << "---------------";
}
void StudentData::highestStudents() //this function prints finds and prints the highest grades students
{
    cout << "\nStudents with highest scores: ";

    for (int i=0; i < R; i++)
    {
        if (sClass[i].testScores > 95)
        {
            cout << left;
            cout << endl << sClass[i].studentLName << ", " << sClass[i].studentFName << endl;
            cout << "Test Score: " << sClass[i].testScores << endl;
            cout << "Letter Grade: " << sClass[i].letterGrade << endl;
        }
    }
    cout << "------------";
}
void StudentData::printData() //this function prints the variables
{
    cout << left;
    cout << "\n" << studentLName << ", " << studentFName;
    cout << "\nTest Score: " << testScores;
    cout << "\nLetter Grade: " << letterGrade << endl;
}
void printStudents() //this function outputs all elements according to the print data function, in this case all students with their values through an array
{
    for (int i=0; i<R; i++)
    {
        sClass[i].printData();
    }
}
int main() {
        
    read(sClass);
    printStudents();
    
    return 0;
}
