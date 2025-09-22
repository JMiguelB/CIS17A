/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:
 * Author: J Miguel Belarmino
 * Date: Sept 10, 2025
 * Purpose: Output Format
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float a, b, c, d;
    
    //Initialize or input data here
    cin>> a >> b >> c >> d;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    cout<< setw(9) << a << setw(10)<<fixed<<setprecision(1)<< a <<setw(10)<<setprecision(2) <<a<< endl;
    cout<< setw(9) <<setprecision(0)<< b << setw(10)<<fixed<<setprecision(1)<< b <<setw(10)<<setprecision(2) <<b<< endl;
    cout<< setw(9) <<setprecision(0)<< c << setw(10)<<fixed<<setprecision(1)<< c <<setw(10)<<setprecision(2) <<c<< endl;
    cout<< setw(9) <<setprecision(0)<< d << setw(10)<<fixed<<setprecision(1)<< d <<setw(10)<<setprecision(2) <<d;
    //Format and display outputs here
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}

