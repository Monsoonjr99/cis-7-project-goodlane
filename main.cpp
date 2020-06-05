// Test

#include <iostream>
#include "Hand.h"

using namespace std;

int main()
{
  Hand dealer_hand;
  Hand player_hand;

  dealer_hand.add_card(0);
  dealer_hand.add_card(12);
  dealer_hand.add_card(5);

  player_hand.add_card(8);
  player_hand.add_card(6);
  player_hand.add_card(1);

  cout << "Dealer hand: ";
  dealer_hand.print();
  cout << "Player hand: ";
  player_hand.print();

  cout << endl;
  cout << "The sum of the dealer hand is: " << dealer_hand.sum() << endl;
  cout << "The sum of the player hand is: " << player_hand.sum() << endl;

  system("pause");
  return 0;
}
