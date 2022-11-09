//Jeremiah Todaro
// 09.30.22
/*Use Lab 2, to use an array of structure movie.
 Create an input file (s) to enter information (title, year released, cost, time, ....) for this array of movies.  Read data from these files , store them in proper arrays , then display them on screen.
 you must use three functions and pass structure as an arqument, or primative arquments).  Functions are
 ReadmovieData
 FindProfitorLost
 DisplayResult
 Format the output in specific order (movie name, or time, or cost).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int R=4;

struct MovieData
{
  string title;    // Movie title
  string director; // Director
  int year;        // Year released
  int minute;      // Running time in minutes
  double cost;     // Movie Cost
  double firstRev; // Movie Revenue
} array[R];

void readfile(MovieData array[R]);

void displayMovie(MovieData array[R]);

//void profitLoss(MovieData array [R]);

int main() {
    //variables
    MovieData array[R]{};

    readfile(array);
    displayMovie(array);
    //profitLoss(array);

    cout << endl;
      
    return 0;
}
void readfile(MovieData array[R])
{
    fstream read;
    
    read.open ("Movie Title.txt");
    for (int i = 0; i < R; i++)
    {
        array[i].title = i+1;
        read >> array[i].title;
    }
    read.close();
    
    read.open ("Movie Directors.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].director;
    }
    read.close();
    
    read.open ("Movie Year.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].year;
    }
    read.close();
    
    read.open ("Movie Length.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].minute;
    }
    read.close();
    
    read.open ("Movie Cost.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].cost;
    }
    read.close();
    
    read.open ("Revenue.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].firstRev;
    }
    read.close();
};
// The displayMovie function displays the data in the  member variables of the MovieData structure passed  as an argument.
void displayMovie(MovieData array)
{
    for (int i = 0; i < R; i++)
    {
        
        cout << "\nTitle             : " << array.title;
        cout << "\nDirector          : " << array.director;
        cout << "\nReleased          : " << array.year;
        cout << "\nRunning Time      : " << array.minute << " minutes" << endl;
        cout << "Cost              : " << array.cost << endl;
        cout << "First year revenue: " << array.firstRev << endl;
         
    }
};

/*void profitLoss(MovieData array) //Function to calculate profit/loss of movie
{
    double pl;
    pl = array.firstRev - array.cost;
    
    if (pl > 0)
    {
        cout << "Movie Profit: " << pl << endl;
    }
    else
        cout << "Movie Loss: " << pl << endl;

};*/

