/*
 Jeremiah Todaro
 09.08.22
 Create a text file (int, string, or double) then read tit in an array or vector , use linear & binary search function i gave you on (9/8/2022)
 implement it in a c++ program that reads data and loook for a target in the array.  upload it for grading
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int R = 9;

void readFile(int array[R])
{
    fstream read;
    read.open("junk.txt");
    for (int h=0; h<R; h++)
    {
        read >> array[R];
    }
}

int lSearch(int array[R],int target, int n)
{
    for (int i=0; i<n; i++)
   {
       if(array[i]==target)
           return i;
   }
return -1;

}
 int bSearch(int array[R],int x,int low,int high)
 {
     while (low <= high)
     {
     int mid = low + (high - low) / 2;
 
     if(array[mid] == x)
         return mid;
     else if(array[mid]<x)
         low=mid+1;
     else
         high=mid -1;
 
     }
 return -1;
 }

int main() {

    int array[] = {50,90,30,70,90,31,45,78,79};
    int x = 50;
    int target = 31;
    int n = sizeof (array[R])/sizeof(array[R]);
    
    int result = lSearch(array,target,n);
    (result=-1);
    
    int resultt = bSearch(array,x,0,n-1);
    if (resultt == -1)
        cout << "not found ";
    else
        cout << "found at index: " << resultt << endl;
    
    (result == -1) ? cout << "Element not found " : cout << "Element found at index: " << result;
    return 0;
}
