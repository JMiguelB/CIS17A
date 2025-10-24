/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 19th, 2025, 1:34 PM
 * Purpose:  Structure Weather Statistics
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>    //For using the string data type
#include <iomanip>   //format
using namespace std;

//User Libraries
struct Weather {
    string month;     //month
    float rainfall;  //Total rainfall
    int low;          //Low temperature 
    int high;         //high temperature 
    float avg;       //monthly average temperature
};
//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int N=12;
    Weather w[N];
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    for (int i=0; i<N ;++i) {
        cin >> w[i].month >> w[i].rainfall >> w[i].low >> w[i].high;
        while (w[i].low<-100 || w[i].low>140) {     //Input validation for temps
            cin>>w[i].low;
        }
        while (w[i].high<-100 || w[i].high>140) {
            cin>>w[i].high;
        }
        w[i].avg=(w[i].low + w[i].high)/2.0;
    }

    float tRain=0.0;
    float avg=0.0;
    int idxLow=0;   //index of lowest temperature
    int idxHigh=0;  //index of highest temperature

    for (int i=0; i<N; ++i) {
        tRain+=w[i].rainfall;
        avg+=w[i].avg;
        if (w[i].low<w[idxLow].low) idxLow=i;
        if (w[i].high>w[idxHigh].high) idxHigh=i;
    }

    float aMRain=tRain/N; //total rain/months
    float tempYr=avg/N;
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(1);
    cout<<"Average Rainfall " << aMRain << " inches/month" << '\n';
    cout<<setprecision(0);
    cout<<"Lowest  Temperature "<<w[idxLow].month<<"  "<< w[idxLow].low<<" Degrees Fahrenheit"<<endl;
    cout<<"Highest Temperature " << w[idxHigh].month << "  "<< w[idxHigh].high<< " Degrees Fahrenheit" <<endl;
    cout<<"Average Temperature for the year "<<tempYr<<" Degrees Fahrenheit"<<endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}
