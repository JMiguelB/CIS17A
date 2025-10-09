/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 28th, 2025, 3:24 PM
 * Purpose: Output the reverse sorted dynamic 
 *          array by first sorting from smallest
 *          to largest.
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int *getData(int &);               //Fill the array
int *sort(const int *,int);        //Sort smallest to largest
int *reverse(const int *,int);     //Sort in reverse order
void prntDat(const int *,int);     //Print the array
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int size;
    int *array = getData(size);
    int *sorted = sort(array,size);
    int *rev    = reverse(sorted,size);
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    prntDat(sorted,size);
    cout<<endl;
    //Display Inputs/Outputs
    prntDat(rev,size);

    //Clean up memory and files
    delete [] array;
    delete [] sorted;
    delete [] rev;
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

int *sort(const int *a,int n){
    int *b = new int[n];
    for(int i=0;i<n;i++) {
        b[i] = a[i];
    }
    // Bubble sort ascending
    bool swapped;
    do {
        swapped = false;
        for(int i=0;i<n-1;i++){
            if(b[i] > b[i+1]){
                int temp = b[i];
                b[i] = b[i+1];
                b[i+1] = temp;
                swapped = true;
            }
        }
    } while(swapped);

    return b;
}


int *reverse(const int *a,int n){
    int *b = new int[n];
    for(int i=0;i<n;i++){
        b[i] = a[n-1-i];
    }
    return b;
}

void prntDat(const int *a,int n){
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
}
