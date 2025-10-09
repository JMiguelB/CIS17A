/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 28th, 2025, 11:24 PM
 * Purpose:  Augment a 1-D array by 1 Element,
 *           place 0 in the first element and
 *           copy the rest from the
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int *getData(int &);               // Read the array
int *augment(const int *,int);     // Augment and copy the original array
void prntAry(const int *,int);     // Print the array
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int n=0;
    int *arr = getData(n);
    //Initialize Variables
    prntAry(arr,n);                //print original
    cout<<endl;
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    int *aug = augment(arr,n);     //build augmented array (size n+1)
    prntAry(aug,n+1);              //print augmented
    //Clean up memory and files
    delete [] arr;
    delete [] aug;
    //Exit the Program
    return 0;
}

int *getData(int &n){
    cin >> n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    return a;
}

int *augment(const int *a,int n){
    int *b = new int[n+1];
    b[0] = 0;                    //first element is 0
    for(int i=0;i<n;i++){
        b[i+1] = a[i]; //shift original by 1
    } 
    return b;
}

void prntAry(const int *a,int n){
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
}