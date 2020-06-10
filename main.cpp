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

  const int DEALER_HIT_LIMIT = 16;

  char hit_choice;

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
  cout << endl;
  cout << "Player hand: ";
  player_hand.print();

  // display player sum
  cout << "The sum of the player hand is: " << player_hand.sum();
  if(player_hand.sum() == BUST) // Blackjack
  {
    cout << " [BLACKJACK]\n\n";
    dealer_hand.set_hole_card(false); // reveal hole card
    cout << "Dealer hand: ";
    dealer_hand.print();
    cout << "The sum of the dealer hand is: " << dealer_hand.sum();
    if(dealer_hand.sum() == BUST)
    {
      cout << " [BLACKJACK]\n\n";
      cout << "Game result: TIE" << endl;
    }
    else
    {
      cout << "\n\n";
      cout << "Game result: YOU WIN" << endl;
    }
    return 0;
  }
  cout << "\n\n";

  // ask user hit or stay
  cout << "Hit or stay (H/S): ";
  cin >> hit_choice;
  cout << endl;

  while(hit_choice == 'H' || hit_choice == 'h'){
    // if hit, player draws card
    player_hand.add_card(deck.draw());

    // display player hand
    cout << "Player hand: ";
    player_hand.print();

    // display player sum
    cout << "The sum of the player hand is: " << player_hand.sum();
    if(player_hand.sum() > BUST)
    {
      cout << " [BUST]\n\n";
      break;  // don't ask player again if bust
    }
    cout << "\n\n";

    // ask player hit or stay again
    cout << "Hit or stay (H/S): ";
    cin >> hit_choice;
    cout << endl;
  }

  cout << "Dealer's turn...\n\n";

  dealer_hand.set_hole_card(false); // reveal hole card
  // dealer hits as long as their total is 16 or below
  while(dealer_hand.sum() <= DEALER_HIT_LIMIT)
    dealer_hand.add_card(deck.draw());
  
  // display dealer hand and sum
  cout << "Dealer hand: ";
  dealer_hand.print();
  cout << "The sum of the dealer hand is: " << dealer_hand.sum();
  if(dealer_hand.sum() > BUST)
    cout << " [BUST]";
  cout << "\n\n";

  // determine game result
  if(player_hand.sum() > BUST)
    cout << "Game result: YOU LOSE";
  else if(dealer_hand.sum() > BUST)
    cout << "Game result: YOU WIN";
  else if(player_hand.sum() > dealer_hand.sum())
    cout << "Game result: YOU WIN";
  else if(player_hand.sum() == dealer_hand.sum())
    cout << "Game result: TIE";
  else
    cout << "Game result: YOU LOSE";
  cout << endl;

  system("pause");
  return 0;
}
