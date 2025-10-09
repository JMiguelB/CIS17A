/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 24th, 2025, 1:14 PM
 * Purpose:  Template to be used for all
 *           future Hmwk, Labs, Exams, Projects
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void fillAray(int [], int);
void prntAry(const int [],int, int);
void markSrt(int [],int);
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variables
    const int SIZE=100;
    int array[SIZE], size;

    //Initialize Variables
    cout<<"This program sorts random arrays"<<endl;
    do{
       cout<<"What size of aaray do you want? Choose 2-100 "<<endl;
       cin>>size; 
    } while (size>SIZE||size<2);
    
    fillAray(array,size);
    prntAry(array,size,10);
    //Map/Process the Inputs -> Outputs
    markSrt(array,size);

    //Display Inputs/Outputs
    prntAry(array,size,10);

    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void markSrt(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void prntAry(const int a[],int n, int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
       cout<<a[i]<<" ";
       if(i%perLine==(perLine-1))cout<<endl;
    }
}

void fillAray(int a[], int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//{10,99}
    }
}