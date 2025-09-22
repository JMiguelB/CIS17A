/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 20, 2025 3:20 PM
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

void read(int a[],int size) { //read int into ana array
    for (int i=0; i<size; i++) {
        cin>>a[i];      //input given
        cout<<"a["<<i<<"]"<<a[i]<<endl;
    }
}

int  stat(const int a[],int size,int &max,int &min) {
    int sum=a[0];
    max=a[0];
    min=a[0];
    
    for (int i=1;i<size;i++) {                         
        sum+=a[i];                 //add to sum
        if (max<a[i])max=a[i];     //changes max if its greater     
        if (min>a[i])min=a[i];     //changes min if its greater    
    }
    return sum;                    //Return the sum
}

void print(const int a[],int size,int sum,int max,int min) {
    cout <<"Min  = "<< min << endl;
    cout <<"Max  = "<< max << endl;
    cout <<"Sum  = "<< sum << endl;
}
