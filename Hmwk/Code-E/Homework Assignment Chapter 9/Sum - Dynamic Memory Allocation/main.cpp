/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 28th, 2025, 5:42 PM
 * Purpose:  Create a parallel array that 
 *           represents the successive sum 
 *           of preceding members in the array.
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int *getData(int &);             // Return the array size and the array from the inputs
int *sumAry(const int *,int);    // Return the array with successive sums (inclusive)
void prntAry(const int *,int);   // Print the array
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int n=0;
    int *arr = getData(n);
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    prntAry(arr,n);              // original
    cout<<endl;
    int *sum = sumAry(arr,n);    // inclusive prefix sum
    prntAry(sum,n);              // print sums
    //Display Inputs/Outputs
    
    //Clean up memory and files
    delete [] arr;
    delete [] sum;
    //Exit the Program
    return 0;
}

int *getData(int &n){
    cin >> n;
    int *a = new int[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    
    return a;
}

int *sumAry(const int *a,int n){
    int *out = new int[n];
    int running = 0;
    for(int i=0;i<n;i++){
        running += a[i];       // include current element
        out[i] = running;      // store inclusive sum
    }
    return out;
}

void prntAry(const int *a,int n){
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
}