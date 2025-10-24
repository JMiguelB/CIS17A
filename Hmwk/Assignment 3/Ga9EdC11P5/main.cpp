/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 23th, 2025, 6:19 PM
 * Purpose:  Ga9EdC11P5 structures
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>   //Format
using namespace std;

//User Libraries
struct Weather {
    float rain;  //total rainfall
    float high;  //high temperature
    float low;   //low temperature
    float avg;   //average temperature
};
//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
enum Month {JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE};
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int N=6;
    Weather year[N];
    float totalRn=0,totalAg=0;
    int highest=-101,lowest=141; //extremes
    int hiAll=0,loAll=0;         //store high,low temps
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    for (Month m = JANUARY; m <= JUNE; m = static_cast<Month>(m + 1)) {
        cout<<"Enter the total rainfall for the month:"<<endl;
        cin>>year[m].rain;
        cout<<"Enter the high temp:"<<endl;
        cin>>year[m].high;
        cout<<"Enter the low temp:"<<endl;
        cin>>year[m].low;

        while (year[m].high < -100 || year[m].high > 140) //input validation
            cin >> year[m].high;
        while (year[m].low < -100 || year[m].low > 140)
            cin >> year[m].low;
        
        year[m].avg=(year[m].high+year[m].low)/2.0f; //average calculation
        totalRn+=year[m].rain;
        totalAg+=year[m].avg;
        if (year[m].high > highest) highest=year[m].high;
        if (year[m].low < lowest) lowest=year[m].low;
    }

    float avgRn=totalRn/N;
    float avgTemp=totalAg/N;
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2);
    cout<<"Average monthly rainfall:"<<avgRn<<endl;
    cout<<setprecision(0);
    cout<<"High Temp:"<<highest<<endl;
    cout<<"Low Temp:" <<lowest << endl;
    cout<<setprecision(1);
    cout<<"Average Temp:" <<avgTemp;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}