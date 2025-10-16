/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 12th, 2025, 10:18 PM
 * Purpose: Convert the char array using sstream 
 *          library to a float and output the results
 *          Static version
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <sstream>  //stringstream
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    string str1 = "1234";
    string str2 = ".567";

    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    cout<<str1<<endl;
    cout<<str2<<endl;

    str1+=str2; //add both string together

    float result=stof(str1); //convert string to float
    //Display Inputs/Outputs
    cout<<result<<endl;
    //Clean up memory and files

    //Exit the Program
    return 0;
}

