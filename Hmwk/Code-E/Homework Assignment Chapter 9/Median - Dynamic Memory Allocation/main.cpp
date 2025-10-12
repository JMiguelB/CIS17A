/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 27th, 2025, 8:05 PM
 * Purpose:  Median - Dynamic Memory Allocation
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int   *getData(int &);       //Return the array size and the array
void   prntDat(int *,int);   //Print the integer array
float *median(int *,int);    //Fill the median Array
void   prntMed(float *);     //Print the median Array
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int size;
    int *array;
    float *medArray;
    //Initialize Variables
    array=getData(size);
    medArray=median(array,size);
    
    //Map/Process the Inputs -> Outputs
    prntDat(array,size);
    //Display Inputs/Outputs
    prntMed(medArray);
    //Clean up memory and files
    delete [] array;
    delete [] medArray;
    //Exit the Program
    return 0;
}

int *getData(int &n){
    //Input array size
    cin >> n;
    //Allocate memory
    int *a = new int[n];
    //Fill array
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    return a;
}

void prntDat(int *a,int n){
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
    cout <<endl;
}

float *median(int *a,int n){
    //Sort copy to compute median
    int *tmp = new int[n];
    for(int i=0;i<n;i++) tmp[i]=a[i];
    for(int i=0;i<n-1;i++){
        int minPos=i;
        for(int j=i+1;j<n;j++){
            if(tmp[j]<tmp[minPos]) minPos=j;
        }
        int t=tmp[i]; tmp[i]=tmp[minPos]; tmp[minPos]=t;
    }

    float med=0.0f;
    if(n%2==1) med=tmp[n/2];
    else med=(tmp[n/2-1]+tmp[n/2])/2.0f;

    delete [] tmp;

    //Allocate float array of size n+2
    int fsz = n+2;
    float *f = new float[fsz];
    f[0]=fsz;    //store size
    f[1]=med;    //store median
    for(int i=0;i<n;i++){
        f[i+2]=a[i];
    }
    return f;
}

void prntMed(float *f){
    int fsz = static_cast<int>(f[0]);
    cout << fsz; // print size as integer
    cout << " " << fixed << setprecision(2) << f[1]; // median
    for(int i=2;i<fsz;i++){
        cout << " " << fixed << setprecision(2) << f[i];
    }
}
