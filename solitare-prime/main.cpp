// Caitlin Martinez
// CECS 282 - 03 
// Project 1 - Solitare Prime 
// 02/08/2020


#include "Deck.h"
#include <stack>
using namespace std;

Deck deck;

void playSP();
bool isPrime(int val);
void printReverse(stack<Card> cardStack);

int main() {
  
  int userChoice; 
  bool choice = true; 

  cout << "Welcome to Solitare Prime!"<<endl;
  cout << "1) New Deck"<<endl;
  cout << "2) Display Deck"<<endl;
  cout << "3) Shuffle Deck"<<endl;
  cout << "4) Play Solitare Prime"<<endl;
  cout << "5) Exit"<<endl; 
  cout << "\nEnter Choice"<<endl;


  while(choice == true)
  {
  cin >> userChoice;
  while( userChoice != '5')
  {
    switch(userChoice)
    {
      case 1 :
        deck.refreshDeck();
        cout << "There is a new deck!" << endl;
        break;
      case 2 :
        cout << "Current deck: " << endl;
        deck.showDeck();
        break;
      case 3 :
        deck.shuffle();
        cout << "The deck has been shuffled" << endl;
        break;
      case 4 :
        playSP();
        break;
      case 5 :
        cout << "Goodbye" << endl;
        choice = false;
        break; 
        exit(0);
      default :
        cout << "Invalid input" << endl;
        break;
    }
    break;
  } 
  }
}

void playSP()
{
  cout<<deck.cardsLeft()<<endl;
  int pile = 0;
  int sum = 0;
  stack<Card> currentHand;

  cout << "Playing Solitare Prime!!!\n\n" << endl;

  while(deck.cardsLeft() != 0 )
  {
    Card card = deck.deal();
    sum += card.getValue();

    if( isPrime(sum))
    { 
      currentHand.push(card);
      printReverse(currentHand);
      currentHand = stack<Card>();
      cout << " Prime: " << sum << endl;
      pile++;
      sum = 0;
    }
    else 
    {
      currentHand.push(card);
    }
  }
    if(sum != 0)
    {
      printReverse(currentHand);
      currentHand = stack<Card>();
      cout<< "Loser\n" <<endl;
    }
    else
    {
      cout << "\nWinner in " << pile << " piles\n";
    }
  }




bool isPrime(int val)
{
  bool primeNum = true; 

  if(val == 0 || val == 1)
  {
    primeNum = false;
  }
  else 
  {
    for( int i = 2; i <= val / 2; ++i)
    {
      if(val % i == 0)
      {
        primeNum = false;
        break;
      }
    }
  }

  if( primeNum )
  {
    return true; 
  }
  else
    return false;
}

void printReverse(stack<Card> cardStack)
{
  if (cardStack.empty())
  {
    return; 
  }

  Card x = cardStack.top(); 
  cardStack.pop();
  printReverse(cardStack);
  x.showCard();
  cout << " ";
  cardStack.push(x);
}
