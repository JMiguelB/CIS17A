/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 25th, 2025, 4:54 PM
 * Purpose:  Arrays/File funxtion
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <fstream>   //for file input/output
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void wrtArry(ofstream &, int [], int); //writes array to text file
void readAry(ifstream &, int [], int);   //reads array from text file
void print(int arr[], int size);
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    const int SIZE=10;
    int numbers[SIZE];
    //Initialize Variables
    for (int i=0; i<SIZE; i++) { //fill array
        numbers[i]=i+1;
    }

    //Map/Process the Inputs -> Outputs
    ofstream outFile("arryPos.txt"); //put array in text file
    if (!outFile) {
        cout<<"cannot open output file"<<endl;
        return 1;
    }
    wrtArry(outFile, numbers, SIZE);
    outFile.close();

    ifstream inFile("number.txt"); //Read array from text file
    if (!inFile) {
        cout<<"cannot open input file"<<endl;
        return 1;
    }
    readAry(inFile, numbers, SIZE);
    inFile.close();

    // Display array contents
    
    //Display Inputs/Outputs
    cout<<"Numbers read from file: ";
    print(numbers, SIZE);
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void wrtArry(ofstream &out, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        out<<arr[i]<<" "; //write numbers separated by spaces
    }
    out<<endl;
}

void readAry(ifstream &in, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        in >> arr[i]; //read numbers back
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
