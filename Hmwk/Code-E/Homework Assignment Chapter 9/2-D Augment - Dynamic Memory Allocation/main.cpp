/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 10th, 2025, 9:43 PM
 * Purpose:  2-D Augment - Dynamic Memory Allocation
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void prntDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int rows, cols;
    int **array;
    int **augArry;
    
    //Initialize Variables
    array=getData(rows, cols);
    augArry=augment(array,rows,cols);
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    prntDat(array,rows,cols);
    cout<<endl;
    prntDat(augArry,rows+1,cols+1);
    //Clean up memory and files
    destroy(array,rows);
    destroy(augArry,rows+1);
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
    for(int i = 0; i < rows;i++) {
        for(int j = 0; j < cols; j++) {
            cout << a[i][j];
            if (j < cols - 1) {
                cout << " ";
            }
        }
         if (i<rows-1){
            cout<<endl;
        }
    }
}

int **augment(const int * const *a,int rows,int cols) {
    int augRows=rows+1;
    int augCols=cols+1;
    int **augArry=new int *[augRows];
    for (int i=0;i<augRows;i++) {
        augArry[i]=new int[augCols];
    }
    for (int i=0;i<augRows;i++) {
        for (int j=0;j<augCols;j++){
            if (i==0||j==0){
                augArry[i][j]=0;
            }else{
                augArry[i][j]=a[i-1][j-1];
            }
        }
    }
    return augArry;
}

void destroy(int **a,int rows) {  
    for(int i=0;i<rows;i++){ //Delete each of the column arrays
        delete []a[i];
    }
    delete []a; 
}
