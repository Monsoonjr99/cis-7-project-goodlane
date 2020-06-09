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
    if(cards[i] == ACE)
      cout << " A";
    else if(cards[i] < 9) // cards 2 through 9
      cout << ' ' << (cards[i] + 1); // add 1 to convert card code to card number
    else if(cards[i] == 9) // card 10
      cout << "10";
    else if(cards[i] == JACK)
      cout << " J";
    else if(cards[i] == QUEEN)
      cout << " Q";
    else if(cards[i] == KING)
      cout << " K";
    cout << ' ';
  }
  cout << endl;
}

// sums the hand under blackjack rules
int Hand::sum() const
{
    int total = 0;
    for(int i = 0; i < cards.size(); i++)
    {
        if(cards[i] >= JACK) // face card
            total += 10;
        else if(cards[i] > ACE) // cards 2 through 10
            total += cards[i] + 1; // add one more than the card code to add the card value
        else if(cards[i] == ACE)
            total += 11; // initially attempt to add 11
    }

    // if the hand busts by counting aces as 11, recount the aces as 1 until the total is less than 21
    for(int i = 0; total > BUST && i < cards.size(); i++)
    {
        if(cards[i] == ACE)
            total -= 10; // recount each ace as 1 instead of 11 by subtracting 10
    }
    
    return total;
}