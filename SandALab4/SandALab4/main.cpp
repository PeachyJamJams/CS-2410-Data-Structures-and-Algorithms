//Jeremiah Todaro
// 09.30.22
/*
 Convert movie program  to array of objects, then make a 5 minuts code review in class n your conversion

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int R=4;

class MovieData
{
private:
    string title = "";    // Movie title
    string director = ""; // Director
    int year = 0;        // Year released
    int minute = 0;    // Running time in minutes
    double cost = 0.0;    // Movie Cost
    double firstRev = 0.0; // Movie Revenue
public:
    void displayMovie();

    void profitLoss();
    //Giving private variables temp place holders in order to store them properly
    void gettitle(string tempTitle){
        title = tempTitle;
    }
    void getdirector(string tempDirector){
        director = tempDirector;
    }
    void getyear(int tempYear){
        year = tempYear;
    }
    void getlength(int tempMinute){
        minute = tempMinute;
    }
    void getcost(double tempCost){
        cost = tempCost;
    }
    void getrev(double tempFirstRev){
        firstRev = tempFirstRev;
    }
};
void readall(MovieData array[R])
{
    for (int i = 0; i < R; i++)
        array[i].displayMovie(); // Display Movie 1

}


void read(MovieData array[R]) // Passsing the class array as an argument
{
    fstream juicy;
    
    juicy.open ("MovieTitle.txt"); //opening the file
    for (int i = 0; i < R; i++) // for loop to read file in correct way
    {
        string tempTitle; // temp value for  loop
        getline(juicy,tempTitle); // read and assign a title for temp value
        array[i].gettitle(tempTitle); // store temp value into array and start loop over again
    }
    juicy.close();
    
    juicy.open ("MovieDirectors.txt");
    for (int i = 0; i < R; i++)
    {
        string tempDirector;
        getline(juicy,tempDirector);
        array[i].getdirector(tempDirector);
    }
    juicy.close();
    
    juicy.open ("MovieYear.txt");
    for (int i = 0; i < R; i++)
    {
        int tempYear;
        juicy >> tempYear;
        array[i].getyear(tempYear);
    }
    juicy.close();
    
    juicy.open ("MovieLength.txt");
    for (int i = 0; i < R; i++)
    {
        int tempMinute;
        juicy >> tempMinute;
        array[i].getlength(tempMinute);
    }
    juicy.close();
    
    juicy.open ("MovieCost.txt");
    for (int i = 0; i < R; i++)
    {
        double tempCost;
        juicy >> tempCost;
        array[i].getcost(tempCost);
    }
    juicy.close();
    
    juicy.open ("MovieRevenue.txt");
    for (int i = 0; i < R; i++)
    {
        double tempFirstRev;
        juicy >> tempFirstRev;
        array[i].getrev(tempFirstRev);
    }
    juicy.close();
}

int main() {
    //variables
    MovieData array[R]; // Establishing the objects which is an array in this case
    
    read(array);
    readall(array);

    cout << endl;
      
    return 0;
}

// The displayMovie function displays the data of the private members in class MovieData.
void MovieData :: displayMovie()
{
        
        cout << "\nTitle             : " << title;
        cout << "\nDirector          : " << director;
        cout << "\nReleased          : " << year;
        cout << "\nRunning Time      : " << minute << " minutes" << endl;
        cout << "Cost              : " << cost << endl;
        cout << "First year revenue: " << firstRev << endl;
        profitLoss();

};

void MovieData :: profitLoss() //Function to calculate profit/loss of movie
{
    double pl;
    pl = firstRev - cost;
    
    if (pl > 0)
    {
        cout << "Movie Profit: " << pl << endl;
    }
    else
        cout << "Movie Loss: " << pl << endl;

};
