/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 18th, 2025, 7:36 PM
 * Purpose:  Ga9EdC11P11 structures
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>    //For using the string data type
#include <iomanip>   //format
using namespace std;

//User Libraries
struct Budget {
    float house;
    float utility;
    float househd;
    float trnsprt;
    float food;
    float medical;
    float insurnc;
    float entrtn;
    float cloth;
    float misc;
};
//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void expense(Budget &);
void report(const Budget &);
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    Budget actual;
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    expense(actual);
    report(actual);
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void expense(Budget &b) { //input for each expen
    cout<<"Enter housing cost for the month:$"<<endl;
    cin>>b.house;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cin>>b.utility;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin>>b.househd;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cin>>b.trnsprt;
    cout<<"Enter food cost for the month:$"<<endl;
    cin>>b.food;
    cout<<"Enter medical cost for the month:$"<< endl;
    cin>>b.medical;
    cout<<"Enter insurance cost for the month:$"<< endl;
    cin>>b.insurnc;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin>>b.entrtn;
    cout << "Enter clothing cost for the month:$"<< endl;
    cin>>b.cloth;
    cout<<"Enter miscellaneous cost for the month:$"<< endl;
    cin>>b.misc;
}

// Function to display report comparing actual vs budget
void report(const Budget &a) {
    // Standard monthly budget
    const Budget budget = {500.00,150.00,65.00,50.00,250.00,30.00,100.00,150.00,75.00,50.00};
    float diff, ttlDif = 0; //difference, total difference

    diff=a.house - budget.house;  //Housing
    if (diff>0) cout<<"Housing Over"<<endl;
    else if (diff<0) cout<<"Housing Under"<<endl;
    else cout<<"Housing Even"<<endl;
    ttlDif+=diff;

    diff=a.utility - budget.utility;  //Utilities
    if (diff>0) cout<<"Utilities Over"<<endl;
    else if (diff<0) cout<<"Utilities Under"<<endl;
    else cout<<"Utilities Even"<<endl;
    ttlDif+=diff;

    diff=a.househd - budget.househd;  //Household Expenses
    if (diff>0) cout<<"Household Expenses Over"<<endl;
    else if (diff<0) cout<<"Household Expenses Under"<<endl;
    else cout <<"Household Expenses Even"<<endl;
    ttlDif += diff;

    diff=a.trnsprt - budget.trnsprt;  //transportation
    if (diff>0) cout<<"Transportation Over"<<endl;
    else if (diff<0) cout<<"Transportation Under"<<endl;
    else cout<<"Transportation Even"<< endl;
    ttlDif+=diff;

    diff=a.food - budget.food;    //food
    if (diff>0) cout<<"Food Over"<<endl;
    else if (diff<0) cout<<"Food Under"<<endl;
    else cout<<"Food Even"<<endl;
    ttlDif+=diff;

    diff=a.medical - budget.medical;    //medical
    if (diff>0)cout<<"Medical Over"<<endl;
    else if (diff<0) cout<<"Medical Under"<<endl;
    else cout <<"Medical Even"<<endl;
    ttlDif+=diff;

    diff=a.insurnc - budget.insurnc;  //Insurance
    if (diff>0) cout<<"Insurance Over"<<endl;
    else if (diff<0) cout<<"Insurance Under"<< endl;
    else cout<<"Insurance Even"<<endl;
    ttlDif+=diff;

    diff= a.entrtn - budget.entrtn;     //entertainment
    if (diff>0) cout<<"Entertainment Over"<<endl;
    else if (diff<0) cout<<"Entertainment Under"<<endl;
    else cout <<"Entertainment Even"<< endl;
    ttlDif+=diff;

    diff=a.cloth - budget.cloth; //clothing
    if (diff>0) cout<<"Clothing Over"<<endl;
    else if (diff<0) cout<<"Clothing Under"<<endl;
    else cout<<"Clothing Even"<< endl;
    ttlDif+=diff;

    diff=a.misc - budget.misc;    //miscellaneous
    if (diff>0) cout<<"Miscellaneous Over"<<endl;
    else if (diff<0) cout<<"Miscellaneous Under"<<endl;
    else cout<<"Miscellaneous Even"<<endl;
    ttlDif+=diff;

    cout << fixed << setprecision(2);
    if (ttlDif > 0)
        cout<<"You were $" <<ttlDif<<" over budget";
    else if (ttlDif<0)
        cout<<"You were $" <<-ttlDif<<" under budget";
    else
        cout<<"You were even with your budget";
}
