/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 12th, 2025, 6:27 PM
 * Purpose:  Binary search names 8.7
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>   //String Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void mrkSrt(string[], int);             //sort string
int binSrch(string[], int, string &);   //Binary searh
void prntAry(string [], int, int);      //Display
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    const int NUM_NMS = 20;
    //Initialize Variables
    string names[NUM_NMS] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                               "Looney, Joe", "Wolfe, Bill", "James, Jean",
                               "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                               "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };
    //Map/Process the Inputs -> Outputs
    cout<<"Given names:"<<endl;
    prntAry(names,NUM_NMS,1);   //display not sorted
    cout<<endl;

    mrkSrt(names,NUM_NMS);      //sort
    cout<<"Sorted names:"<<endl;
    prntAry(names,NUM_NMS,1);   //display sorted
    cout<<endl;
    
    cout<<"Enter the Exact name (include ',' 'space') : ";
    string target;
    getline(cin, target);             //to include spaces and coma
    //cin>>target;

    //Display Inputs/Outputs
    int indx=binSrch(names,NUM_NMS,target);
    if (indx != -1) cout<<target<<" was Found at index "<<indx<<endl;
    else cout<<target<<" was not found"<<endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void mrkSrt(string a[], int n) {
    for(int i=0; i<n-1; i++) {          //sort
        for(int j=i+1; j<n;j++){      //finding smallest 
            if(a[i]>a[j]){              //swapping arrays
                string temp= a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}   

int binSrch(string a[], int n, string &val) {   
    int high=n-1,low=0;
    do{
        int mid=(low+high)/2;                   //binary search starts middle
        if(val==a[mid]){                        //if found
            return mid;
        }else if(val<a[mid]){                   //if not found goes to other half
            high=mid-1;
        }else{                                  //if not found goes to other half
            low=mid+1;
        }
    }while (low<=high);
    return -1;
}

void prntAry(string a[], int n, int perLine) {  //display names

    for(int i=0; i<n ;i++){
        cout<<a[i]<<" ";
        //cout<<" | ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}