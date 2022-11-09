// Jeremiah Todaro
// 10.31.22
/*
 ab 1.
 // Write a program to demonstrate class called Room.   and one object
 // Room1, This program has 3 private members L (lenght), W (width), and H (hight), find volume of this room
 // Assigned values to the member of this class at the main.  Display volume to the screen
 Lab 2.
 //use previous program to demonstrate memebr access specifier (public, and private)
 Lab 3.
 Use previous program and defind your memebr funcion outside of the class.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Shape
{
private:
    double length,width,height;
public:
    double calculateArea(); //member function in class
 
    double calculatePerimeter(); //member function in class
 
   Shape(double l, double w, double h)
    {
        length = l;
        width = w;
        height = h;
    };
};
double Shape::calculateArea()
{
    return length * width * height;
}

double Shape::calculatePerimeter()
{
    return length + width + height;
}
int main() {
    Shape room1(20.1,30.3,40.4);
    Shape room2(44.44,55.55,66.66);
    
    cout << left;
    cout << "Volume of shape 1: " << room1.calculateArea() << " Feet" << endl;
    cout << "Perimeter of shape 1: " << room1.calculatePerimeter() << " Feet" << endl;

    
    return 0;
}
