/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 10th, 2025, 9:04 PM
 * Purpose:  Converting Celsius to Fahrenheit
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    float cel, fah;
    //Initialize Variables
    cout<<"Input Degrees Celsius to convert to Degrees Fahrenheit."<<endl;
    cin>>cel;
    //Map/Process the Inputs -> Outputs
    fah= 9/5.0f*cel+32; //formula converts Celsius to Fahrenheit
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"Degrees Fahrenheit = " <<fah<<" degrees"<<endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

