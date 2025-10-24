/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 18th, 2025, 5:15 PM
 * Purpose: Ga9EdC11P3 structures
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>    //For using the string data type
#include <iomanip>   //format
using namespace std;

//User Libraries
struct Divisn {
    string name;
    float q1, q2, q3, q4;  //quarterly sales
    float total;           //total annual sales
    float average;         //average quarterly sales
};
//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    Divisn north, west, east, south;
    //Initialize Variables
    north.name ="North";
    west.name  ="West";
    east.name  ="East";
    south.name ="South";
    //Initialize Variables
    Divisn divisns[4] = {north, west, east, south};
    //Map/Process the Inputs -> Outputs
    for (int i=0; i<4; i++) {
        cout<<divisns[i].name<<endl;
        cout<<"Enter first-quarter sales:"<<endl;
        cin>>divisns[i].q1;
        cout<<"Enter second-quarter sales:"<<endl;
        cin>> divisns[i].q2;
        cout<<"Enter third-quarter sales:"<<endl;
        cin>>divisns[i].q3;
        cout<<"Enter fourth-quarter sales:"<<endl;
        cin>>divisns[i].q4;
        // Calculate total and average
        divisns[i].total=divisns[i].q1+divisns[i].q2+divisns[i].q3+divisns[i].q4;
        divisns[i].average=divisns[i].total/4.0f;

        cout<<fixed<<setprecision(2);
        cout<<"Total Annual sales:$"<<divisns[i].total<<endl;
        if (i==3)
            cout<<"Average Quarterly Sales:$"<< divisns[i].average;
        else
            cout<<"Average Quarterly Sales:$"<<divisns[i].average<< endl;
    }
    
    //Display Inputs/Outputs
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}