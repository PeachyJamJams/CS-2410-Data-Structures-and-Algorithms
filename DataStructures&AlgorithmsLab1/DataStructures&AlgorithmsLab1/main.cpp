//Jeremiah Todaro
//August 31st 2022
/* Submit this program This is a Review for CS 1410    MAL-C8-P13
 Write a program to calculate students' average test scores and their grades. You may assume the following input data:
 Johnson   Marieta     85   83  77   91  76
 Aniston     Saboly      80   90   95   93  48
 Cooper     Mancini    81   91   90   83  58
 Gupta       Piota        70   50   85   73  68
 Blair          Coviani    60   90   75   53  98
  
 Use three arrays: a  one-dimensional string array to store the students' names, a (parallel)  two-dimensional integer array to store the test scores, and  one-dimensional double array to store average grades  for each student.
 Your program must contain at least the following functions: a function to  read and store  data (student's grade)  into two arrays, a function to  calculate the average test score and, and a function to  output the results. Have your program also output the class average.
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

const int R=5, C=5; //Constants to establish array boundaries

void readFile(int array[R][C],string namearray[R],char arrayg[R]) //function to open and read file
{
    fstream read;
    read.open ("numbers.txt"); //functions to open and read file
    
    for (int h = 0; h < R; h++) //for loop in order to read array correctly
    {
        
        for (int w = 0; w < C; w++)
        {
            read >> array[h][w];
        }
    }
    read.close();
    read.open ("names.txt");
        
        for (int w = 0; w < C; w++)
        {
            getline(read,namearray[w]);
        }
    
    read.close();
}
void calculateSum(int array[R][C],int sum[R]) // function to get sum of rows
{
    for (int a = 0; a < R; a++) //Nested for loop to calculate row sums correctly
    {
        unsigned int temp_row = 0;
        for (int b = 0; b < C; b++)
        {
            temp_row += array[a][b];
        }
        
        sum[a] = temp_row;
    }
    
}
void calculateAvg(int array[R][C],int sum[R] ,float avg[R], char arrayg[R]) //function to get average of rows
{
    
    for (int a = 0; a < R; a++) //nested ror loops with varaibles in order to get sum and divide it in ordet to get the calculated average of array
    {
        float temp_avg = 0.0;
        float temp_sum = 0.0;
        for (int b = 0; b < C; b++)
        {
            temp_sum += array[a][b];
            temp_avg = temp_sum / C;
            avg[a] = temp_avg;
        }
        if (temp_avg > 0 &&temp_avg < 60)
        {
            arrayg[a] = 'F';
        }
        else if (temp_avg >= 60 &&temp_avg < 70)
        {
            arrayg[a] = 'D';
            
        }
        else if (temp_avg >= 70 &&temp_avg < 80)
        {
            arrayg[a] = 'C';
        }
        else if (temp_avg >= 80 &&temp_avg < 90)
        {
            arrayg[a] = 'B';
        }
        else if (temp_avg >= 90 &&temp_avg < 100)
        {
            arrayg[a] = 'A';
        }
        }
}
void sortName(int array[R][C],string namearray[R],int sum[] ,float avg[R],char arrayg[R])
 {
 int r,c,j;
  for(r=0; r < R; r++)
  {
   for(j=0; j < R-1; j++)
   {
       if (namearray[j] > namearray[j+1])
       {
           string temp_name=namearray[j];
           namearray[j]=namearray[j+1];
           namearray[j+1]=temp_name;
 
           int temp_total;
           temp_total=sum[j];
           sum[j]=sum[j+1];
           sum[j+1]=temp_total;
 
           float tempp_avg;
           tempp_avg=avg[j];
           avg[j]=avg[j+1];
           avg[j+1]=tempp_avg;
 
           char temp_grade;
           temp_grade=arrayg[j];
           arrayg[j]=arrayg[j+1];
           arrayg[j+1]=temp_grade;
 
           for (c=0; c < C; c++)
           {
               int grade = array[j][c];
               array[j][c] = array[j+1][c];
               array[j+1][c] = grade;
           }
       }
  }
    
 }
}
void display(int array [R][C],string namearray[R],float avg[R],char arrayg[R])  //function to display array and calculate data (sum & average)
{
    cout<< left;
    const int namew = 16;
    for (int a = 0; a < R; a++) //nested for loop in order to display the array correctly
    {
        cout << setw(namew)<< namearray[a];

        for (int b = 0; b < C; b++)
        {
            cout << array[a][b] << ' ';
        }
        //cout << sum[a] << ' ';
        cout << fixed << setprecision(2) << avg[a] << ' ';
        cout << arrayg[a] << ' ';
        cout  << endl;
    }
}
void calculateClassAvg(int array[R][C],float avg[R],float& cavg)
{
    float classAvg = 0.0;
    for (int  a = 0; a < R; a++)
    {
        classAvg += avg[a];
    }
    classAvg = classAvg / R;
    cout << "Class Average: " << classAvg << endl;
    
}
int main()
{
    //variables
    int array[5][5]{};
    string namearray [R];
    int sum[R];
    char arrayg[R];
    float avg[R];
    float cavg;
    
    readFile(array, namearray, arrayg);
    calculateSum(array, sum);
    calculateAvg(array ,sum, avg, arrayg);
    
    cout << "Array contents:\n";
    sortName(array,namearray,sum,avg,arrayg);
    display(array,namearray,avg,arrayg);
    calculateClassAvg(array,avg,cavg);


    cout << endl;
    
    return 0;
}
