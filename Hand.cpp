#include "Hand.h"

// constructor that initiallizes the hand with a predefined array of card values
Hand::Hand(int *dealt_cards, int length)
{
  for(int i = 0; i < length; i++)
    add_card(dealt_cards[i]);
}

// prints cards to the console
void Hand::print() const
{
  for(int i = 0; i < cards.size(); i++)
  {
    if(cards[i] == 0) // ace
      cout << " A";
    else if(cards[i] < 9) // cards 2 through 9
      cout << ' ' << (cards[i] + 1); // add 1 to convert card code to card number
    else if(cards[i] == 9) // card 10
      cout << "10";
    else if(cards[i] == 10) // jack
      cout << " J";
    else if(cards[i] == 11) // queen
      cout << " Q";
    else if(cards[i] == 12) // king
      cout << " K";
    cout << ' ';
  }
  cout << endl;
}