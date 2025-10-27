/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 26th, 2025, 7:39 PM
 * Purpose:  Corporate Sales Data Output
 *           Structures
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <fstream>   //File Input/Output Library
#include <string>    //String Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Structure for division sales data
struct DivSales {
    string divName;    //Division name 
    int quarter;       //Quarterly
    float sales;      //Sales amount for the quarter
};

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    DivSales data[20]; //Array to store
    string divs[] = {"East","West","North","South"}; //Division names
    ofstream outFile; //Output file stream
    float amount;  //Sales amount input
    int idx=0;     //Array index counter
    
    //Initialize Variables
    outFile.open("sales_data.txt");  //Open output file 
    //Map/Process the Inputs -> Outputs
    cout<<"Corporate Sales Data Input"<<endl;

    for (int i=0; i<4; i++) { //Loop through each division
        cout<<"Enter sales data for "<<divs[i]<<" Division:"<<endl;
        // Loop through each quarter for current division
        for (int q=1; q<=4; q++) {
            do {
                cout<<"Quarter "<<q<<" sales: $";
                cin>>amount;
                if (amount<0) { //Input validation
                    cout<<"Invalid input, enter a positive number."<<endl;
                }
            } while (amount<0);

            data[idx].divName=divs[i];//store data in structure
            data[idx].quarter=q;
            data[idx].sales=amount;

            //Write to file
            outFile<<"Division: "<<data[idx].divName<<", Quarter: "<<data[idx].quarter<< ", Sales: $"<<data[idx].sales <<endl;

            idx++;  //Move to next
        }
        cout<<endl;
    }
    
    //Display Inputs/Outputs
    cout<<"Sales data has been written to sales_data.txt"<<endl;

    //Clean up memory and files
    outFile.close();  //Close the output file
    
    //Exit the Program
    return 0;
}
