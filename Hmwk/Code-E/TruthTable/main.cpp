/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 11th, 2025, 8:19 PM
 * Purpose:  to tell the Truth
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    bool x,y;

    //Display Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y  !(X||Y) !X&&!Y"<<endl;
	
    while(cin>>x>>y) {
        cout<<(x?'T':'F')<<setw(2)
	    <<(y?'T':'F')<<setw(3)
        <<(!x?'T':'F')<<setw(3)
	    <<(!y?'T':'F')<<setw(4)
        <<(x&&y?'T':'F')<<setw(5)
        <<(x||y?'T':'F')<<setw(4)
        <<(x^y?'T':'F')<<setw(5)
        <<(x^y^x?'T':'F')<<setw(6)
        <<(x^y^y?'T':'F')<<setw(8)
        <<(!(x&&y)?'T':'F')<<setw(7)
        <<(!x||!y?'T':'F')<<setw(9)
        <<(!(x||y)?'T':'F')<<setw(7)
        <<(!x&&!y?'T':'F')<<endl;
    }
        
    cout<<endl;
    //Exit the program
    return 0;
}
