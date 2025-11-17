/* 
 * File:   Card.h
 * Author: J Miguel Belarmino
 * Created on Nov 10, 2025
 * Purpose:  Specification for the Card and Deck structures
 */

#ifndef CARD_H
#define CARD_H

struct Card {
    char face[6];   
    char suit[10];  
    int  value; 
};

struct Deck {
    int size;       //Size of the deck
    Card *cards;    //Pointer to dynamic array of cards
    int topCard;    //Index of current top card
};

struct Player {
    int chips;      //player's chips
    int bet;        //bet amount
    int wins;       //win count
    int rounds;     //round count
};

#endif /* CARD_H */

