/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Seot 20, 2025 3:57 PM
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd) {
    int size, val;
    cout<<"Input the number of integers to input."<<endl;
    cin>>size;
    cout<<"Input each number."<<endl;
    
    for (int i=0;i<size;i++) {
        cin>>val;
        if(val % 2==0) {
            even.push_back(val);    //add to even vector if divisible by 2
        } else {
            odd.push_back(val); //add to odd vector if not div by 2
        }
    }
}

void copy(vector<int> even, vector<int> odd,int a[][COLMAX]) {  //copy values
    int rows=max(even.size(), odd.size());

    for(int i=0;i<rows;i++) {  //copy even val to columns
        a[i][0] = (i < even.size()) ? even[i] : 0; //even goes to column 0
        a[i][1] = (i < odd.size()) ? odd[i] : 0;   //odd goes to column 1
    }
}

void prntVec(vector<int> even, vector<int> odd,int n) {   //int n is the format
    cout<<"    Vector      Even       Odd"<<endl; //header
    int rows=max(even.size(), odd.size());  //get the number of rows
    
    for (int i=0;i<rows;i++) {
        cout<<setw(n)<<"";              //indent
         if (i < even.size()) //even
         cout << setw(n) << even[i]; 
         else cout << setw(n) << "";   
         if (i < odd.size())  //odd
         cout << setw(n) << odd[i];  
         else cout << setw(n) << "";    
        cout<<endl;
    }
}

void prntAry(const int a[][COLMAX],int evnSize,int oddSize,int n) {
    cout<<"     Array      Even       Odd"<<endl; //header
    int rows=max(evnSize, oddSize);  //get the number of rows
    
    for (int i=0;i<rows;i++) {
        cout<<setw(n)<<"";              //indent
        if (i<evnSize)
        cout<<setw(n)<<a[i][0];
        else cout << setw(n) << "";     
        if (i<oddSize)
        cout<<setw(n)<<a[i][1];
        else cout << setw(n) << "";
        cout<<endl;
    }
}
