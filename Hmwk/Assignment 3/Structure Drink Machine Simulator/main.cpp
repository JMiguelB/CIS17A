/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 22nd, 2025, 5:19 PM
 * Purpose:  Structure Drink Machine Simulator
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>    //For using the string data type
#include <iomanip>   //format
using namespace std;

//User Libraries
struct Drink {
    string name;  //Drink name
    int cost;     //cost in cents
    int qty;      //Number of drinks in machine
};

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void prntMnu(const Drink machine[], int);
int fndDrnk(const Drink machine[], int, const string&);
bool isNumber(const string&);
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    const int SIZE=5;
    Drink machine[SIZE]={{"Cola",75,20},{"Root Beer",75,20},{"Lemon-Lime",75,20},{"Grape Soda",80,20},{"Cream Soda",80,20}};
    float total=0;  //total in cents
    string choice;
    int cents;
    bool quit=false;
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    while (!quit) {
        prntMnu(machine, SIZE);   // display the machine menu
        getline(cin, choice);     // read the drink choice

        if (choice=="Quit") {
            quit=true;          // set flag
        } 
        else {
            int index=fndDrnk(machine,SIZE,choice);  // find matching drink

            if (index != -1 && machine[index].qty > 0) {    //Validate drink choice
                string monyStr;    //Read money input
                getline(cin, monyStr);

                //Input validation and purchase processing
                if (isNumber(monyStr)) {//If invalid drink or sold out, just loop again naturally
                    cents = stoi(monyStr);//converts string to integer
                    if (cents>=0 && cents<=100 && cents>=machine[index].cost) {
                        int change=cents-machine[index].cost; //Process purchase
                        machine[index].qty--;
                        total+=machine[index].cost;
                        cout<<change<<endl; //Output change in cents
                    }
                }
            }
        }
    }

    //Display Inputs/Outputs
    cout<<total<<endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}


// Function to print the machine menu
void prntMnu(const Drink machine[], int SIZE) { //Function to print the machine menu
    for (int i = 0; i < SIZE; i++) {
        cout <<left<<setw(11)<<machine[i].name<<machine[i].cost<<"  "<<machine[i].qty <<endl;
    }
    cout<<"Quit"<< endl;
}

// Function to find drink index by name
int fndDrnk(const Drink machine[], int SIZE, const string& name) {
    for (int i=0; i<SIZE; i++) {
        if (machine[i].name==name)
            return i;
    }
    return -1;
}

bool isNumber(const string& s) {    //Helper function to check if a string is a number
    for (char c:s) {
        if (c<'0' || c>'9') 
        return false;
    }
    return true;
}
