/* 
 * File:   Card.h
 * Author: J Miguel Belarmino
 * Purpose: Struct for Blackjack cards
 */

#ifndef CARD_H
#define CARD_H

struct Card {
    char face[6];   
    char suit[10];  
    int  value; 
};

#endif /* CARD_H */
