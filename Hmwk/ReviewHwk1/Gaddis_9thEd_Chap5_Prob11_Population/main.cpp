/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 10th, 2025, 11:11 PM
 * Purpose:  Predict size Population
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions
const float PERCENT=1e2f; // Conversion to a %
//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int days;
    float start, incrse;
    //Initialize Variables
    cout << "Enter starting size of a population of organism: ";
    cin>>start;
    while(start<2) {                  //Input validation
        cout<<"Invalid number"<<endl;
        cin>>start;
    }

    cout << "Enter average daily population increase (%): ";
    cin>>incrse;
    while(incrse<0) {                 //Input validation
        cout<<"Invalid number"<<endl;
        cin>>incrse;
    }

    cout << "Enter number of days to multiply: ";
    cin>>days;
    while(days<1) {                   //Input validation
        cout<<"Invalid number"<<endl;
        cin>>days;
    }
    //Map/Process the Inputs -> Outputs
    cout<<fixed<<setprecision(2);
    cout<<"\nDays"<<"\tPopulation"<<endl;

    for (int i=1; i <= days; i++) {   //loop increase
        cout<<i<<"\t"<<start<<endl;
        start*=(1+incrse/PERCENT);    //update population calculation
    }
    //Display Inputs/Outputs
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}