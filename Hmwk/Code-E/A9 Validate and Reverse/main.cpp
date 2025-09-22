/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Sept 21, 2025 7:25 PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

bool  inRange(const char a[],unsigned short &num) { //Output true,unsigned or false
    int len=strlen(a);  //length of the string
    int val=0;           //store value
    
    for(int i=0;i<len;i++){
        if (a[i]<'0'||a[i]>'9')  //if not a digit return false
        return false;
        
        val=val*10+(a[i]-'0');  //digits to number
        if (val>65535)          //unsigned short
        return false;
    }
    
    num = val;
    return true;
}

bool  reverse(unsigned short num,signed short &rev) { //Output true,short or false
    char digits[6]; // Max 6 digits
    int len = 0;
    
    while (num > 0) {  // get digits in reverse
        digits[len++] = (num % 10) + '0';  // Convert digit to char
        num /= 10;
    }
    while (len < 5) {  // add 0 to make 5 digits
        digits[len++] = '0';
    }
    digits[len] = '\0'; //end string
    
    int val = 0;   // Convert reversed string to integer
    for (int i = 0; i < len; i++) {
        val = val * 10 + (digits[i] - '0');
    }

    if (val >= -32768 && val <= 32767) {   // Check if within signed short range
        rev = val;
        return true;
    }

    return false; //too big or too small
}

short subtrct(signed short rev,int sub) {
    if (rev>=sub) {
        return rev-sub;   //subtract only if result is not negative
    }
    return rev;
}
