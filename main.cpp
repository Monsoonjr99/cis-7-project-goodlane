// Test

#include <iostream>
#include "Hand.h"
#include "Deck.h"

using namespace std;

int main()
{
  Deck deck;
  Hand dealer_hand;
  Hand player_hand;

  for(int i = 0; i < 3; i++)
    dealer_hand.add_card(deck.draw());

  for(int i = 0; i < 3; i++)
    player_hand.add_card(deck.draw());

  cout << "Dealer hand: ";
  dealer_hand.print();
  cout << "Player hand: ";
  player_hand.print();

  cout << endl;
  cout << "The sum of the dealer hand is: " << dealer_hand.sum();
  if(dealer_hand.sum() > BUST)
    cout << " [BUST]";
  cout << endl;
  cout << "The sum of the player hand is: " << player_hand.sum();
  if(player_hand.sum() > BUST)
    cout << " [BUST]";
  cout << endl;

  system("pause");
  return 0;
}
