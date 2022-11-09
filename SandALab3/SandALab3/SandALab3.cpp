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
}array[R];

void readfile(MovieData array[R]);

void displayMovie(MovieData array[R]);

void profitLoss(MovieData array [R],int i);

int main() {
    //variables
    MovieData array[R];

    readfile(array);
    displayMovie(array);

    cout << endl;
      
    return 0;
}
void readfile(MovieData array[R])
{
    ifstream read;
    
    read.open ("MovieTitle.txt");
    for (int i = 0; i < R; i++)
    {
        getline(read,array[i].title);
    }
    read.close();
    
    read.open ("MovieDirectors.txt");
    for (int i = 0; i < R; i++)
    {
        getline(read,array[i].director);
    }
    read.close();
    
    read.open ("MovieYear.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].year;
    }
    read.close();
    
    read.open ("MovieLength.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].minute;
    }
    read.close();
    
    read.open ("MovieCost.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].cost;
    }
    read.close();
    
    read.open ("MovieRevenue.txt");
    for (int i = 0; i < R; i++)
    {
        read >> array[i].firstRev;
    }
    read.close();
};
// The displayMovie function displays the data in the  member variables of the MovieData structure passed  as an argument.
void displayMovie(MovieData array[R])
{
    for (int i = 0; i < R; i++)
    {
        
        cout << "\nTitle             : " << array[i].title;
        cout << "\nDirector          : " << array[i].director;
        cout << "\nReleased          : " << array[i].year;
        cout << "\nRunning Time      : " << array[i].minute << " minutes" << endl;
        cout << "Cost              : " << array[i].cost << endl;
        cout << "First year revenue: " << array[i].firstRev << endl;
        profitLoss(array,i);
    }
};

void profitLoss(MovieData array[R], int i) //Function to calculate profit/loss of movie
{
    double pl;
    pl = array[i].firstRev - array[i].cost;
    
    if (pl > 0)
    {
        cout << "Movie Profit: " << pl << endl;
    }
    else
        cout << "Movie Loss: " << pl << endl;

};

