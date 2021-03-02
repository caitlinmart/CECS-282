#include "Deck.h"

  

  Deck::Deck()
  {
    char ranks[] = {'A','1','2','3','4','5','6','7','8','9','T','J','Q','K' };
    char suits[] = {'S','H','D','C'};
    int k = 0; 
    

    for (int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 13; j++)
      {
        deck[k++] = Card(ranks[j],suits[i]); 
      }
    }
    cardCount = 52;
  }

  void Deck::refreshDeck()
  {
    char ranks[] = {'A','1','2','3','4','5','6','7','8','9','T','J','Q','K' };
    char suits[] = {'S','H','D','C'};
    int k = 0; 

    for (int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 13; j++)
      {
        deck[k++] = Card(ranks[j],suits[i]); 
      }
    }
    cardCount = 52;
  }

  Card Deck::deal()
  {
    Card c = deck[cardCount - 1];
    cardCount--; 
    return c; 
  }

  void Deck::shuffle()
  {
    srand(0);
    for(int i = 0; i < cardCount; i++)
    {
      int randomizeDeck = i + (rand() % (52 - i));
      Card tempCard = deck[i];
      deck[i] = deck[randomizeDeck];
      deck[randomizeDeck] = tempCard;
    }

  }

  int Deck::cardsLeft()
  {
    return cardCount; 
  }

  void Deck::showDeck()
  {
    for( int i = 0; i < 52; i++)
    {
      if(i % 13 == 0 && i != 0)
      {
        cout << endl;
        deck[i].showCard();
        cout << " ";
      }
      else 
      {
        deck[i].showCard();
        cout << " ";
      }
    }
  }





