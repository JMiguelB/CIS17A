/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 11th, 2025, 1:00 PM
 * Purpose:  Celcius Temperature converter table
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>   //Formatting library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
float celsius(float);   
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    cout<<"Fahrenheit to Celsius Table (0-20)"<<endl;
    cout<<"Fahrenheit"<<"\t"<<"Celsius"<<endl;
    for (int i=0;i <= 20;i++) {       //loop 0-20
        cout<<setw(5)<<i;
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"\t\t"<<celsius(i)<<endl;
    }
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

float celsius(float fah) {      //functiion 
    return (5/9.0f)*(fah-32);              //celsius to fahrenheit calculation
}