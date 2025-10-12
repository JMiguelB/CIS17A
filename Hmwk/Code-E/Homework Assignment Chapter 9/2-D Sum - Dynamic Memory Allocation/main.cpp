/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 4th, 2025, 12:20 AM
 * Purpose:  2-D Sum - Dynamic Memory Allocation
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int rows, cols;
    int **array;
    //Initialize Variables
    array = getData(rows, cols);
    //Map/Process the Inputs -> Outputs
    prntDat(array, rows, cols);
    //Display Inputs/Outputs
    cout << sum(array, rows, cols);
    //Clean up memory and files
    destroy(array, rows);
    //Exit the Program
    return 0;
}

int **getData(int &rows,int &cols)  {
    cin>>rows>>cols; //inputs rows and data
    int **array=new int*[rows]; //create the array of row using ponters
    for(int i=0; i<rows;i++) {   //for each row and read the data
        array[i] = new int[cols];
        for(int j = 0; j < cols; j++) {
            cin >> array[i][j];
        }
    }
    return array;
}

void prntDat(const int* const *a,int rows,int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << a[i][j];
            if (j < cols - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void destroy(int **a,int rows) {  
    for(int row=0;row<rows;row++){ //Delete each of the column arrays
        delete []a[row];
    }
    delete []a; 
}

int sum(const int * const *a, int rows,int cols) {
    int total = 0;
    for(int i = 0; i < rows; i++) { 
        for(int j = 0; j < cols; j++) {
            total += a[i][j]; //sum of all elements in the 2D array
        }
    }
    return total;
}
