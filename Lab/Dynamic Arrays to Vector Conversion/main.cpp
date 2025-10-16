/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Oct 5th, 2025, 9:43 PM
 * Purpose:  Compare 1 and 2 Dimensional Dynamic Arrays
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntAry(vector<int> &,int);
void prntAry(vector<vector<int>> &);
vector<int> fillAry(int,int,int);
vector<vector<int>> fillAry(int,int);
void fillAry(vector<vector<int>> &,vector<int> &,int);
//void destroy(vector<vector<int>>,int);
//void fillAry(vector<vector<int>>,vector<int>,int,int,int);
void swap(int &,int &);
void smlLst(vector<int> &,int,int);
void mrkSort(vector<int> &,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    vector<int> array;
    vector<int> brray;
    vector<int> crray;
    vector<vector<int>> table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    array=fillAry(rowsize,highRng,lowRng);
    brray=fillAry(rowsize,highRng/10,lowRng/10);
    crray=fillAry(rowsize,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(array,rowsize);
    mrkSort(brray,rowsize);
    mrkSort(crray,rowsize);
    
    //Fill the 2-D array
    table=fillAry(rowsize,colsize);
    fillAry(table,array,0);
    fillAry(table,brray,1);
    fillAry(table,crray,2);
    
    //Print the values in the array
    prntAry(array,perLine);
    prntAry(brray,perLine);
    prntAry(crray,perLine);
    prntAry(table);
    
    //Cleanup
    /*delete []array;
    delete []brray;
    delete []crray;
    destroy(table,rowsize);*/

    //Exit
    return 0;
}

/*void destroy(int **a,int rows){
    for(int row=0;row<rows;row++){
        delete []a[row];
    }
    delete []a;
}*/

void fillAry(vector<vector<int>> &a,vector<int> &c,int wchCol){
    for(int row=0;row<a.size();row++){
        a[row][wchCol]=c[row];
    }
}

vector<int> fillAry(int n,int hr,int lr){
    n=n<2?2:n;
    vector<int> a(n);
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
    return a;
}

vector<vector<int>> fillAry(int rows,int cols){
    //Allocate Memory for 2-D Array
    vector<vector<int>> grid;
    for(int i=0;i<rows;i++){
        vector<int> curRow(cols, 0);
        grid.push_back(curRow);
    }
    return grid;
    /*//Fill it with 0's
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            a[row][col]=0;
        }
    }
    return a;*/
}

void prntAry(vector<vector<int>> &a){
     cout<<endl<<"The Array Values"<<endl;
    for(int row=0;row<a.size();row++){
        for(int col=0;col<a[row].size();col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

void prntAry(vector<int> &a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<a.size();indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(vector<int> &a,int n){
    for(int pos=0;pos<a.size()-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(vector<int> &a,int n,int pos){
    for(int i=pos+1;i<a.size();i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
