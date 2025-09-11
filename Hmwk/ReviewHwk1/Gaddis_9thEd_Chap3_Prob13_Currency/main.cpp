/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 9th, 2025, 9:06 PM
 * Purpose:  Convert US dollar to yen and euros
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions
const float YENPRDL   = 147.43; //Yen per dollar as of 10 Sept.
const float EUROSPDL = 0.85;  //Euros per dollar as of 10 Sept.
//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    float usd, yen, euros;
    //Initialize Variables
    cout<<"Currency Converter"<<endl;
    cout<<"Input US dollars: ";
    cin>>usd;
    //Map/Process the Inputs -> Outputs
    yen=usd*YENPRDL;
    euros=usd*EUROSPDL;
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<usd<<" USD = "<<yen<<" Yen"<<endl;
    cout<<usd<<" USD = "<<euros<<" Euros"<<endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}
