/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 12th, 2025, 12:34 AM
 * Purpose: Convert the char array using sstream 
 *          library to a float and output the results
 *          Dynamic version
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <sstream>  //stringstream
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int strSize(const char* str);   //Returns the size of a C-String
void plusEql(char *, const char*, int=20); //Concatenates two C-Strings if there is enough space
void strCopy(char* dest,const char* src);   //Copies a C-String
float str2Flt(stringstream &ss,const char* src); //Converts a C-String to a float using stringstream
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables 
    //dynamic memory
    char *str1=new char[strSize("1234")];
    char *str2=new char[strSize(".567")];
    
    //Initialize Variables
    strCopy(str1, "1234");
    strCopy(str2, ".567");
    //Map/Process the Inputs -> Outputs
    int comSize=strSize("1234")+strSize(".567"); //counting size for the new string
    char *newStr=new char[comSize]; //dynamic memory for the new combine string

    strCopy(newStr,str1);//copy to the string1 to new string
    plusEql(newStr,str2,comSize);//adding the string function to become the new string

    stringstream ss;
    float result= str2Flt(ss,newStr);//convert string to float
    //Display Inputs/Outputs
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<newStr<<endl;
    cout<<result<<endl;
    //Clean up memory and files
    delete []str1;
    delete []str2;
    delete []newStr;
    //Exit the Program
    return 0;
}

int strSize(const char* str) {
    int size=0;
    while(str[size]!='\0') { //counts till it hit the null terminator
        size++; //move to the next
    }
    return size;
}

void plusEql(char *dest, const char *src, int size) {
    int lenDest=strSize(dest);
    int lenSrc=strSize(src);

    if ((lenDest+lenSrc)<=size){ //check if theres room
        strCopy(dest+lenDest,src);  //combine the second word to the end of the first word
    }
}

void strCopy(char* dest,const char* src) {
    int i=0;
    while (src[i]!='\0') {//counts till it hit the null terminator
        dest[i]=src[i];//Copy the char from source to destination
        i++; //move to the next
    }
    dest[i]='\0'; //to know end of the end of new string
}

float str2Flt(stringstream &ss,const char* src) {
    float result;
    ss << src;  //Type the text into the calculator
    ss >> result;   //Get the number out
    
    return result;
}
