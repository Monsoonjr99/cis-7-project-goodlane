#include <iostream>
#include "Hand.h"
#include "Deck.h"

using namespace std;

int main()
{
  // declare deck and hand objects
  Deck deck;
  Hand dealer_hand;
  Hand player_hand;

  cout << "This program simulates the casino card game Blackjack." << endl;
  cout << "The cards are represented here with their symbol if face up, or _ if face-down." << endl;
  cout << endl;

  // draw two cards for each hand and set the dealer's hand to have a face-down card
  for(int i = 0; i < 2; i++)
    dealer_hand.add_card(deck.draw());
  dealer_hand.set_hole_card(true);

  for(int i = 0; i < 2; i++)
    player_hand.add_card(deck.draw());

  // display hands
  cout << "Dealer hand: ";
  dealer_hand.print();
  cout << "Player hand: ";
  player_hand.print();

  // display sums
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
