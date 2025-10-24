/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on OCt 20th, 2025, 8:24 PM
 * Purpose:  Structures Movie Data
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>    //For using the string data type
using namespace std;

//User Libraries
struct Movies {
    string title;
    string director;
    int year;
    int length;
};
//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void displayMovie(Movies &);
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)."<<endl;
    int n;
    cin >> n;
    cin.ignore(); //clear newline before getline
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    Movies movie;
    for (int i=0; i<n; i++) {
        getline(cin,movie.title);
        getline(cin,movie.director);
        cin>>movie.year;
        cin>>movie.length;
        cin.ignore(); //clear newline
        cout<<endl;
        displayMovie(movie);
    }
    //Display Inputs/Outputs
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void displayMovie(Movies &m) { //Function to display movie info
    cout<<"Title:     "<<m.title<<endl;
    cout<<"Director:  "<<m.director<< endl;
    cout<<"Year:      "<<m.year<<endl;
    cout<<"Length:    "<<m.length<<endl;
}
