/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 21, 2025 AND 8:44 PM
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

int read(char a[][COLMAX],int &rowDet) { //Outputs row and columns detected from input
    int maxLen=0;
    rowDet=0;
    
    while (cin >> a[rowDet]){ // read one char
        int len=0;
        while (a[rowDet][len++] != '\0' );
        if(len>maxLen) maxLen=len;
        rowDet++;
    }
    
    return maxLen-1;
}

void sort(char a[][COLMAX],int rowIn,int colIn,const char replace[],const char with[]) { //Sort by row using strcmp();
    bool swap=true;
    int redList=rowIn-1;
    
    do {
        swap = false;
        
        for(int i=0;i<redList;i++) {  //loop throough rows
            if (strcmp(a[i],a[i+1],replace,with)>0){ //swap the the 2 string
                char temp[COLMAX];
                strcpy(temp, a[i]);    //string swap
                strcpy(a[i], a[i+1]);
                strcpy(a[i+1], temp);
                swap=true;
            }
        }
        redList--;
    } while(swap);
}

void print(const char a[][COLMAX],int rowIn,int colIn) { //Print the sorted 2-D array
    for (int i=0; i<rowIn; i++) {
        cout<<a[i]<<endl;
    }
}

//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char a[],char b[],const char replace[],const char with[]) { //Replace sort order
    int i = 0;
    while (true) {
        char ra=(a[i]);    //Read raw chars
        char rb=(b[i]);

        for (int j=0; replace[j] != '\0' && with[j] != '\0'; ++j) {
            if (ra ==(replace[j])) {
                ra =(with[j]);          //swap the character
                break;
            }
        }
        for (int j=0; replace[j] != '\0' && with[j] != '\0'; ++j) {
            if (rb ==(replace[j])) {
                rb =(with[j]);          //swap the character
                break;
            }
        }
        if (ra < rb) return -1;  //Compare mapped chars
        if (ra > rb) return  1;
        ++i;
    }
}
