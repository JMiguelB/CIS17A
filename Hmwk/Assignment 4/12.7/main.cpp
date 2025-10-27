/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 24th, 2025, 8:24 PM
 * Purpose: Sentence Filter
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <fstream>   //for file input/output
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    string infileN, ofileN; //input file name and out file name
    ifstream inFile;
    ofstream outFile;
    bool start=true;
    char ch;

    //Initialize Variables
    cout<<"Enter the name of the input file: "<<endl;
    cin>>infileN;
    cout<<"Enter the name of the output file: "<<endl;
    cin>>ofileN;
    //Map/Process the Inputs -> Outputs
    inFile.open(infileN); //open file
    outFile.open(ofileN);

    if (!inFile) { //validtion
        cout << "Error: could not open input file.\n";
        return 1;
    }
    if (!outFile) {
        cout << "Error: could not open output file.\n";
        return 1;
    }

    while (inFile.get(ch)) { //Capitalize by ascii code
        if (start) { //first letter
            if (ch>='a' && ch<='z') {
                ch=ch-32;  //convert lowercase to uppercase
                start=false;
            } else if (ch>='A' && ch<='Z') { //if already capital no change
                start=false;
            }
        } else { //after the first letter
            if (!start && (ch>='A' && ch<='Z')) {
                ch=ch+32;  //convert uppercase to lowercase
            }
        }

        outFile.put(ch);  //write character to output file

        // Check if end of sentence
        if (ch=='.') {
            start=true;
        }
    }

    //Display Inputs/Outputs

    inFile.close(); //Close files
    outFile.close();
    //Clean up memory and files
    cout<<"file has been processed"<<endl;
    //Exit the Program
    return 0;
}