/* 
 * File:   main.cpp
 * Author: J Miguel Belarmino
 * Created on Nov 12, 2025
 * Purpose:  Blackjack Card Game with Pointers, Arrays of Structures, and Leaderboard
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
void start(char [], bool&, Player&);     //Input name and check for saved game with money
void stats(Player&);                     //Win stats and money display (uses string)
void placeBet(char [], Player&);         //Place bet for current round
void saveGam(const char [], const Player&);  //Save game stats including money
int fndRec(const char [], int);          //Find record index by name in leaderboard
void wrtRec(int, const char [], int, int, int, int);  //Write record at position using seekp
void upLdr(const char [], const Player&, int, int);  //Update or add player to leaderboard
void shwLdr(int);                        //Display leaderboard from binary file
void bldDeck(Card [], const char* [], const char* [], const int [], const int);//build deck of cards
void shuffle(Card [], int);              //shuffle deck/swapping
void srtDeck(Card [], int);              //sorting deck
void prtDeck(const Card [], int, int);   //show deck
bool dealPtr(Card *, int, int &, const Card* &);  //deal one card; return pointer to Card
void pushCard(int *&, int &, int);       //push card value into dynamic hand
int adjtAce(const int *, int, const int);//compute total with aces
void pTurnPtr(const char [], int *&, int &, Player&, int &, Card *, int, const int); //pointer based player turn
void dTurnPtr(const char [], const int *, int, int *&, int &, Player&, int &, Card *, int, const int); //pointer based dealer turn

//Execution begins here at main
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0))); //random number generator

    //Declare Variables
    int topCard=0;
    char name[20];                 //User's name as C-string (Chapter 10)
    bool found=false;            //indicate if existing user found
    Player player;               //Player info
    player.chips=1000;         //Start with 1000 chips
    player.bet=0;              //No bet yet
    player.wins=0;             //Wins counter
    player.rounds=0;           //Rounds counter
    const int perLine=4;
    const int MAXVAL=21;         //Highest value allowed in Blackjack
    const int DECSIZE=52;        //Total cards in a standard deck
    const bool showDecks=false;  //Show deck output
    const int NAMESZ=20;       //name size for leaderboard
    const int RECSZ=NAMESZ+sizeof(int)+sizeof(int);  //record size: name + chips + wins
    
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

    start(name, found, player);                      //check saved game by name with money
    shwLdr(NAMESZ);                                  //show leaderboard at start

    bool play=true;//Start main game loop
    do{
        //both starts at the total value of 0
        if(topCard>DECSIZE-10){      //reshuffle when few cards remain
            cout<<"Shuffle again"<<endl;
            bldDeck(deck, face, suit, values, DECSIZE);
            shuffle(deck,DECSIZE);
            topCard=0;
        }

        placeBet(name, player);            //place bet for round
        
        //dynamic buffers
        int *pHand=nullptr; 
        int pSz=0;   //player hand, values only
        int *dHand=nullptr; 
        int dSz=0;   //dealer hand, values only

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

        pTurnPtr(name, pHand, pSz, player, topCard, deck, DECSIZE, MAXVAL); //User's turn

        if(adjtAce(pHand,pSz,MAXVAL)<MAXVAL){    //dealer plays if player didn't bust
            dTurnPtr(name, pHand, pSz, dHand, dSz, player, topCard, deck, DECSIZE, MAXVAL);
        }

        player.rounds++;        //count round
        player.bet = 0;         //reset bet
        stats(player);          //show stats and chips

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
    }while (play && player.chips > 0);  //Continue if chips available
    //Display Inputs/Outputs
    if(player.chips <= 0) {
        cout << name << " is out of chips! Game Over." << endl;
    }
    saveGam(name, player);
    upLdr(name, player, NAMESZ, RECSZ);              //update leaderboard

    //Clean up memory and files
    delete [] deck; //deck cleanup

    //Exit the Program
    return 0;
}

void start(char name[], bool &found, Player &player) {
    cout<<"Enter player's name: ";
    cin>>name;                             //Prompt the user to enter their name (C-string input)
    
    char filename[50];                     //filename buffer
    strcpy(filename, name);                //copy name to filename
    strcat(filename, "blackjack.dat");     //add .dat extension
    
    fstream in;                            //file input
    in.open(filename, ios::binary | ios::in);  //open binary file for reading
    if(in.is_open()){
        in.read((char*)&player.chips, sizeof(player.chips));
        in.read((char*)&player.wins, sizeof(player.wins));
        in.read((char*)&player.rounds, sizeof(player.rounds));
        in.close();
        found=true;
    }
    
    if(found){ 
        cout<<"Resume game. Chips: "<<player.chips<<endl<<endl;
    }else{
        player.chips = 1000;               //new player starts with 1000
        cout<<"New game. Starting chips: "<<player.chips<<endl<<endl;
    }
}

void stats(Player &player) {
    float winRate;                            //win probability in % out of 100%
    winRate=(player.rounds>0)?(100.0f*player.wins/player.rounds):0; //calculate of win rate
    cout<<fixed<<setprecision(1);
    cout<<"Win rate= "<<winRate<<"% ("<<player.wins<<"/"<<player.rounds<<")"<<endl;
    
    string status = "Chips: ";               //use string object
    status += to_string(player.chips);       //add chips to string
    cout << status << endl;
}

void placeBet(char name[], Player &player) {
    int bet;
    cout << name << " has " << player.chips << " chips." << endl;
    cout << "Place your bet (1-" << player.chips << "): ";
    cin >> bet;
    
    while(bet < 1 || bet > player.chips) {  //check if bet is valid
        cout << "Invalid bet. Enter bet (1-" << player.chips << "): ";
        cin >> bet;
    }
    
    player.bet = bet;
    player.chips -= bet;  //take bet from chips
    cout << "Bet placed: " << player.bet << " chips" << endl << endl;
}

void saveGam(const char name[], const Player &player) {
    char filename[50];                     //filename buffer
    strcpy(filename, name);                //copy name to filename
    strcat(filename, "blackjack.dat");     //add .dat extension
    
    fstream out;                           //file output
    out.open(filename, ios::binary | ios::out);  //open binary file for writing
    if(out.is_open()){  
        out.write((char*)&player.chips, sizeof(player.chips));
        out.write((char*)&player.wins, sizeof(player.wins));
        out.write((char*)&player.rounds, sizeof(player.rounds));
        out.close();
    }
}

int fndRec(const char name[], int nameSz) {
    fstream in;                            //file input
    in.open("leaderboard.dat", ios::binary | ios::in);  //open leaderboard binary file
    if(!in.is_open()) {
        return -1;                         //file doesn't exist
    }
    
    char recName[20];
    int chips;
    int wins;
    int index=0;
    
    in.read((char*)recName, nameSz);
    in.read((char*)&chips, sizeof(chips));
    in.read((char*)&wins, sizeof(wins));
    
    while(!in.eof()) {
        if(strcmp(recName, name) == 0) {   //found matching name
            in.close();
            return index;
        }
        index++;
        in.read((char*)recName, nameSz);
        in.read((char*)&chips, sizeof(chips));
        in.read((char*)&wins, sizeof(wins));
    }
    
    in.close();
    return -1;                             //not found
}

void wrtRec(int index, const char name[], int chips, int wins, int nameSz, int recSz) {
    fstream out;                           //file output
    out.open("leaderboard.dat", ios::binary | ios::out | ios::in);  //open for random access
    if(out.is_open()) {
        int pos = index * recSz;           //calculate position
        out.seekp(pos, ios::beg);          //seek to position using seekp
        out.write(name, nameSz);           //write name
        out.write((char*)&chips, sizeof(chips));  //write chips
        out.write((char*)&wins, sizeof(wins));    //write wins
        out.close();
    }
}

void upLdr(const char name[], const Player &player, int nameSz, int recSz) {
    char recName[20];
    strcpy(recName, name);                 //copy name
    
    int index = fndRec(name, nameSz);      //find existing record
    if(index >= 0) {
        wrtRec(index, recName, player.chips, player.wins, nameSz, recSz);  //update using seekp
    } else {
        fstream out;                       //file output
        out.open("leaderboard.dat", ios::binary | ios::out | ios::app);  //append mode
        if(out.is_open()) {
            out.write(recName, nameSz);    //write name
            out.write((char*)&player.chips, sizeof(player.chips));  //write chips
            out.write((char*)&player.wins, sizeof(player.wins));    //write wins
            out.close();
        }
    }
}

void shwLdr(int nameSz) {
    fstream in;                            //file input
    in.open("leaderboard.dat", ios::binary | ios::in);  //open leaderboard binary file
    if(!in.is_open()) {
        cout << "No leaderboard yet." << endl << endl;
        return;
    }
    
    cout << "=== LEADERBOARD ===" << endl;
    cout << setw(20) << left << "Name" << setw(10) << right << "Chips" 
         << setw(10) << right << "Wins" << endl;
    cout << string(40, '-') << endl;
    
    char recName[20];
    int chips;
    int wins;
    int count = 0;
    
    in.read((char*)recName, nameSz);
    in.read((char*)&chips, sizeof(chips));
    in.read((char*)&wins, sizeof(wins));
    
    while(!in.eof()) {
        cout << setw(20) << left << recName 
             << setw(10) << right << chips
             << setw(10) << right << wins << endl;
        count++;
        in.read((char*)recName, nameSz);
        in.read((char*)&chips, sizeof(chips));
        in.read((char*)&wins, sizeof(wins));
    }
    
    if(count == 0) {
        cout << "No records yet." << endl;
    }
    cout << endl;
    in.close();
}

void bldDeck(Card deck[], const char* face[], const char* suit[],
             const int values[], const int DECSIZE) {
    Card *pDeck = deck;                        //Internal pointer to array of structures
    for(int s=0;s<4;s++) {                      // Loop through 4 suits
        for(int f=0;f<13;f++) {
            // Copy into fixed-size char arrays using internal pointer
            strncpy(pDeck->face, face[f], sizeof(pDeck->face)-1);
            pDeck->face[sizeof(pDeck->face)-1] = '\0';
            strncpy(pDeck->suit, suit[s], sizeof(pDeck->suit)-1);
            pDeck->suit[sizeof(pDeck->suit)-1] = '\0';
            pDeck->value = values[f];
            pDeck++;                            //Move pointer to next structure
        }
    }
}

void shuffle(Card deck[], const int size) {
    Card *pDeck = deck;                        //Internal pointer to array of structures
    for(int i=0;i<size;i++,pDeck++) {
        int j=rand()%size;                     //random from size
        Card *pSwap = deck + j;                //Internal pointer to random card
        Card temp = *pDeck;                    //swap cards using pointers
        *pDeck = *pSwap;
        *pSwap = temp;
    }
}

void srtDeck(Card deck[], int size) {  //bubble sort but custom
    bool swap;
    int redlist=size-1;
    do{
        swap=false;
        Card *pDeck = deck;                    //Internal pointer to array of structures
        for(int i=0;i<redlist;i++,pDeck++) {
            Card *pNext = pDeck + 1;           //Internal pointer to next structure
            //push Aces value 11 to the end
            if (pDeck->value == 11 && pNext->value != 11) {
                Card t=*pDeck; *pDeck=*pNext; *pNext=t;  //swap using pointers
                swap = true;
            }
            //otherwise, sort numerically
            else if (pDeck->value > pNext->value) {
                Card t=*pDeck; *pDeck=*pNext; *pNext=t;  //swap using pointers
                swap = true;
            } 
        }
        redlist--;  
    }while(swap);
}

void prtDeck(const Card deck[], int size, int perLine) { //display
    const Card *pDeck = deck;                  //Internal pointer to array of structures
    cout<<endl;
    for(int i=0;i<size;i++,pDeck++) {
        cout << setw(10)<<pDeck->face<< " of " << setw(9) << pDeck->suit 
             << " (" << pDeck->value <<")  ";  //print card using pointer
        if(i%perLine==(perLine-1))cout<<endl;
    }
}

bool dealPtr(Card *deck, int size, int &topCard, const Card* &cardPtr){   //deal one card return pointer
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

void pTurnPtr(const char name[], int *&pHand, int &pSz, Player &player,
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
                player.wins++;                //count win
                player.chips += player.bet * 2;  //win bet back plus winnings
                move='s';                     //exit loop
            }
        }
    }while(move=='h'||move=='H');
}

// Dealer turn using pointer-deal & dynamic hand    
void dTurnPtr(const char name[], const int *pHand, int pSz,
              int *&dHand, int &dSz, Player &player, int &topCard, Card *deck,
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

    if (dTot>MAXVAL){             //dealer busts
        cout<<"Dealer Busted! ;) (Over 21)"<<endl;
        cout<<name<<" is a WINNER! :)"<<endl<<endl;
        player.wins++;            //count win
        player.chips += player.bet * 2;  //win bet back plus winnings
    }else if(dTot>pTot){          //dealer has more
        cout << "Dealer wins this round." << endl;
    }else if(dTot==pTot){         //tie
        cout<<endl<<"DRAW!"<<endl<<endl;
        player.chips += player.bet;  //return bet
    }else{
        cout<<name<<" is a WINNER! :)"<<endl<<endl;
        player.wins++;            //count win
        player.chips += player.bet * 2;  //win bet back plus winnings
    }
}

