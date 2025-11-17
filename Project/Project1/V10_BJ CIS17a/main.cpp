/* 
 * File:   main.cpp (V10)
 * Author: J Miguel Belarmino
 * Created on Nov 10, 2025
 * Purpose:  Blackjack(21) with struct Card in a header; pointer-to-struct deal
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>   //Format Library
#include <ctime>     //Time Library
#include <cstdlib>   //Random Library
#include <string>    //String Library
#include <fstream>   //File Library for reading from and writing to files
#include <cstring>   //C-string copy
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void start(string&, bool&, int&, int&);  //Input name and check for saved
void stats(int , int);                   //Win stats
void saveGam(const string&, int, int);   //Save game stats
void bldDeck(Card [], const char* [], const char* [], const int [], const int);//build deck of cards
void shuffle(Card [], int);              //shuffle deck/swapping
void srtDeck(Card [], int);              //sorting deck
void prtDeck(const Card [], int, int);   //show deck
bool dealPtr(Card *, int, int &, const Card* &);  //deal one card; return pointer to Card
void pushCard(int *&, int &, int);       //push card value into dynamic hand
int adjtAce(const int *, int, const int);//compute total with aces
void pTurnPtr(string, int *&, int &, int &, int &, Card *, int, const int); //pointer based player turn
void dTurnPtr(string, const int *, int, int *&, int &, int &, int &, Card *, int, const int); //pointer based dealer turn

//Execution begins here at main
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0))); //random number generator

    //Declare Variables
    int topCard=0;
    string name;                 //User's name & temporary file word
    bool found=false;            //indicate if existing user found
    int wins=0, rounds=0;        //Track total wins and rounds
    const int perLine=4;
    const int MAXVAL=21;         //Highest value allowed in Blackjack
    const int DECSIZE=52;        //Total cards in a standard deck
    const bool showDecks=false;  //Show deck output
    
    //Initialize Variables
    const char* face[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    const char* suit[]={"Spades","Diamonds","Clubs","Hearts"};
    const int values[] ={2,3,4,5,6,7,8,9,10,10,10,10,11};

    Card *deck=new Card[DECSIZE];   //dynamic array of Cards

    //Map/Process the Inputs -> Outputs
    bldDeck(deck, face, suit, values, DECSIZE); //build the deck
    if (showDecks) {            //optionally show sorted deck before shuffle
        srtDeck(deck, DECSIZE);                     //sort the deck
        cout<<"Sorted deck:"; 
        prtDeck(deck,DECSIZE,perLine);              //show deck
    }
    shuffle(deck, DECSIZE);                          //shuffle deck (in-place)
    if (showDecks) {            //optionally show shuffled deck
        cout<<"Shuffled Deck:"; 
        prtDeck(deck,DECSIZE,perLine);              //show the deck
    }

    start(name,found,wins,rounds);                   //check saved game by name 

    bool play=true;//Start main game loop
    do{
        //both starts at the total value of 0
        if(topCard>DECSIZE-10){      //reshuffle when few cards remain
            cout<<"Shuffle again"<<endl;
            bldDeck(deck, face, suit, values, DECSIZE);
            shuffle(deck,DECSIZE);
            topCard=0;
        }

        //dynamic buffers
        int *pHand=nullptr; 
        int pSz=0;   //player hand (values only)
        int *dHand=nullptr; 
        int dSz=0;   //dealer hand (values only)

        //User's two initial card
        cout << name << " first 2 cards are:"<<endl;    //Player first two cards using dealPtr using pointers
        for(int i=0;i<2;i++){
            const Card *c;
            dealPtr(deck, DECSIZE, topCard, c);
            cout << c->face << " of " << c->suit << " (" << c->value << ")" << endl;
            pushCard(pHand, pSz, c->value);
        }
        cout << "Total = " << adjtAce(pHand, pSz, MAXVAL) << endl << endl;
        
        //dealer's initial card
        const Card *dc;
        dealPtr(deck, DECSIZE, topCard, dc);
        cout << "Dealer's first card is a " << dc->face << " of " << dc->suit << endl;
        pushCard(dHand, dSz, dc->value);
        cout << endl;

        pTurnPtr(name, pHand, pSz, wins, topCard, deck, DECSIZE, MAXVAL); //User's turn

        if(adjtAce(pHand,pSz,MAXVAL)<MAXVAL){    //Dealer/computer's turn if player hasn't busted
            dTurnPtr(name, pHand, pSz, dHand, dSz, wins, topCard, deck, DECSIZE, MAXVAL);
        }

        rounds++;               //counts the rounds
        stats(wins,rounds);     //calculate of win rate

        delete [] pHand; //cleanup hands each round
        pHand=nullptr; 
        pSz=0;
        delete [] dHand; 
        dHand=nullptr; 
        dSz=0;
        
        cout<<endl;
        char again;
        cout<<"Do you wanna play again?(y/n): "; //ask to continue
        cin>>again;
        play=(again=='y'||again=='Y'); //convert answer to bool
    }while (play);
    //Display Inputs/Outputs
    saveGam(name, wins, rounds);

    //Clean up memory and files
    delete [] deck; //deck cleanup

    //Exit the Program
    return 0;
}

void start(string &name, bool &found, int &wins, int &rounds) {
    cout<<"Enter player's name: ";
    cin>>name;                             //Prompt the user to enter their name
    
    fstream in;                            //Input file streams
    in.open(name+"blackjack.dat",ios::in); //Attempt to load previous progress
    if(in.is_open()){
        //read data     
        in>>wins>>rounds;
        in.close();
        found=true;
    }
    
    if(found){ 
        cout<<"Resume rounds."<<endl<<endl;
    }else{
        cout<<"New game."<<endl<<endl;
    }
}

void stats(int wins, int rounds) {
    float winRate;                            //win probability in % out of 100%
    winRate=(rounds>0)?(100.0f*wins/rounds):0; //calculate of win rate
    cout<<fixed<<setprecision(1);
    cout<<"Win rate= "<<winRate<<"% ("<<wins<<"/"<<rounds<<")"<<endl;
}

void saveGam(const string &name, int wins, int rounds) {
    fstream out;                           //Output file streams/save
    out.open(name+"blackjack.dat",ios::out);  //Save game results to file  
    if(out.is_open()){  
        out<<wins<<" "<<rounds;
        out.close();
    }
}

void bldDeck(Card deck[], const char* face[], const char* suit[],
             const int values[], const int DECSIZE) {
    int indx=0;                                // Index for filling the deck
    for(int s=0;s<4;s++) {                      // Loop through 4 suits
        for(int f=0;f<13;f++) {
            // Copy into fixed-size char arrays
            strncpy(deck[indx].face, face[f], sizeof(deck[indx].face)-1);
            deck[indx].face[sizeof(deck[indx].face)-1] = '\0';
            strncpy(deck[indx].suit, suit[s], sizeof(deck[indx].suit)-1);
            deck[indx].suit[sizeof(deck[indx].suit)-1] = '\0';
            deck[indx].value = values[f];
            indx++;
        }
    }
}

void shuffle(Card deck[], const int size) {
    for(int i=0;i<size;i++) {
        int j=rand()%size;    //random from size
        Card temp=deck[i];    //swap cards
        deck[i]=deck[j];
        deck[j]=temp;
    }
}

void srtDeck(Card deck[], int size) {  //bubble sort but custom
    bool swap;
    int redlist=size-1;
    do{
        swap=false;
        for(int i=0;i<redlist;i++) {
            //push Aces value 11 to the end
            if (deck[i].value == 11 && deck[i+1].value != 11) {
                Card t=deck[i]; deck[i]=deck[i+1]; deck[i+1]=t;
                swap = true;
            }
            //otherwise, sort numerically
            else if (deck[i].value > deck[i+1].value) {
                Card t=deck[i]; deck[i]=deck[i+1]; deck[i+1]=t;
                swap = true;
            } 
        }
        redlist--;  
    }while(swap);
}

void prtDeck(const Card deck[], int size, int perLine) { //display
    cout<<endl;
    for(int i=0;i<size;i++) {
        cout << setw(10)<<deck[i].face<< " of " << setw(9) << deck[i].suit 
             << " (" << deck[i].value <<")  "; //print card and value
        if(i%perLine==(perLine-1))cout<<endl;
    }
}

bool dealPtr(Card *deck, int size, int &topCard, const Card* &cardPtr){   //deal one card; return pointer
    if(topCard>=size) return false;
    cardPtr=deck+topCard;   //point to current Card
    ++topCard;
    return true;
}

void pushCard(int *&hand, int &sz, int val){    //Push value   
    int *newBuf=new int[sz+1];
    const int *src = hand;  //copy existing by pointer traversal
    int *dst = newBuf;

    for(int i=0;i<sz;i++) {
        *dst++ = *src++;
    }
    *dst = val; //append last

    delete [] hand;
    hand=newBuf;
    ++sz;
}

int adjtAce(const int *hand, int sz, const int MAXVAL){ //Compute total
    const int *p=hand;    //First sum and count aces as11
    int total=0,aces=0;
    for(int i=0;i<sz;i++,++p){
        total+=*p;
        if(*p==11) ++aces;
    }
    
    while(total>MAXVAL && aces>0){  //Adjust
        total-=10; 
        --aces;
    }
    return total;
}

void pTurnPtr(string name, int *&pHand, int &pSz, int &wins,
              int &topCard, Card *deck, int size, const int MAXVAL){    //Player turn using pointer-deal & dynamic hand 
    char move;
    do{ //User's decision loop for hit or stand (repeat until stand/bust/21)
        cout<<name<<" Hit(h) or Stand(s)? : ";    //Hit=another card or Stand=stay
        cin>>move;
        cout<<endl;
        if(move=='h'||move=='H'){
            const Card *c;
            dealPtr(deck, size, topCard, c);
            cout<<name<<" hit a "<<c->face<<" of "<<c->suit<<" ("<<c->value<<")"<<endl;
            pushCard(pHand, pSz, c->value);
            int tot = adjtAce(pHand, pSz, MAXVAL);
            cout<<"a new total of = "<<tot<<endl;
            if(tot>MAXVAL){                   //if its over 21 game over
                cout<<name<<" Busted! :'{ (Over 21)"<<endl<<endl;
                move='s';                     //exit loop
            }
            if(tot==MAXVAL){ //player hits 21 
                cout<<name<<" Blackjack/WINNER "<<endl<<endl;
                wins++;                       //increment user's win count
                move='s';                     //exit loop
            }
        }
    }while(move=='h'||move=='H');
}

// Dealer turn using pointer-deal & dynamic hand    
void dTurnPtr(string name, const int *pHand, int pSz,
              int *&dHand, int &dSz, int &wins, int &topCard, Card *deck,
              int size, const int MAXVAL){
    cout<<"Dealer's turn:"<<endl;
    //Dealer's hidden second card
    const Card *c;
    dealPtr(deck, size, topCard, c);
    cout<<"Dealer reveals second card... "<< c->face <<" of "<< c->suit <<" ("<< c->value <<")"<<endl;
    pushCard(dHand, dSz, c->value);
    int dTot = adjtAce(dHand, dSz, MAXVAL);
    cout << "Dealer's first 2 cards are total of: " << dTot << endl;

    while(dTot < 17){                 //Dealer hits until 17 or more
        dealPtr(deck, size, topCard, c);
        cout << "Dealer draws: " << c->face << " of " << c->suit << " (" << c->value << ")"<<endl;
        pushCard(dHand, dSz, c->value);
        dTot = adjtAce(dHand, dSz, MAXVAL);
        cout << "Dealer's new total: " << dTot << endl << endl;
    }

    int pTot=adjtAce(pHand, pSz, MAXVAL);

    if (dTot>MAXVAL){             //Determine outcome
        cout<<"Dealer Busted! ;) (Over 21)"<<endl;
        cout<<name<<" is a WINNER! :)"<<endl<<endl;
        ++wins;
    }else if(dTot>pTot){          //if dealer has more than the user
        cout << "Dealer wins this round." << endl;
    }else if(dTot==pTot){         //if dealer and user total are equal
        cout<<endl<<"DRAW!"<<endl<<endl;
    }else{
        cout<<name<<" is a WINNER! :)"<<endl<<endl;
        ++wins;                   //increment user's win count
    }
}


