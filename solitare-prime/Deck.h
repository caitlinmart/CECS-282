#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck  
{
  private:
    Card deck[52];
    int cardCount;

  public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();

};

#endif