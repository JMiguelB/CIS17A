/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 10th, 2025, 9:55 PM
 * Purpose:  Display Days in a month
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int month, year, days;
    bool leap;
    //Initialize Variables
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    //Map/Process the Inputs -> Outputs
    leap = (year%400==0) || 
           (year%100 != 0 && year%4 == 0); //leap year calculation
    
    if (month==2) {
        days=(leap ? 29:28);         // Feb true(29) or false(28) leap year 
        
    }else if(month==4 || month==6 ||
             month==9 || month==11) { //months with 30 days
        days=30;
        
    }else if(month>=1 && month<=12) { //rest of the months = 31 days
        days=31;
        
    } else { 
        cout<<"Invalid number";
        return 0;
    }
    
    //Display Inputs/Outputs
    cout<< days << " days" << endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

