#include <iostream>
#include "Hand.h"
#include "Deck.h"

using namespace std;

float chance_of_winning_if_stand(const Hand *, const Hand *, const Deck *);

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

  cout << "Rough chance of winning if player stands: " << chance_of_winning_if_stand(&player_hand, &dealer_hand, &deck) << "\n\n";

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

    cout << "Rough chance of winning if player stands: " << chance_of_winning_if_stand(&player_hand, &dealer_hand, &deck) << "\n\n";

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

// rough estimation of the chance the player wins with their current hand
// ideally should take hole card and potential for multiple hits into account; not enough time
float chance_of_winning_if_stand(const Hand *player, const Hand *dealer, const Deck *deck)
{
  float chance_of_dealer_bust;
  float chance_dealer_scores_lower;
  int player_sum = player->sum();
  int dealer_sum = dealer->sum();

  // find chance of dealer bust
  if(dealer_sum >= 12)  // only possible to bust if sum is at least 12
    chance_of_dealer_bust = deck->chance_of_drawing_card_in_range(BUST - dealer_sum + 1, 10, true);
  else
    chance_of_dealer_bust = 0.0;

  // determine if a newly-drawn ace should count as 11 or 1 for the dealer
  bool dealer_ace_counts_one;
  if(dealer_sum < 11) // ace as 11 would bust if the sum is 11 or higher
    dealer_ace_counts_one = false;
  else
    dealer_ace_counts_one = true;
  
  // find chance of dealer scoring lower than player
  if(dealer_sum < player_sum - 1) // dealer is guaranteed to tie or win if their sum is one less than the player's
    chance_dealer_scores_lower = deck->chance_of_drawing_card_in_range(1, player_sum - dealer_sum - 1, dealer_ace_counts_one); // one less than the difference in sums to keep the dealer sum lower
  else
    chance_dealer_scores_lower = 0.0;

  return chance_of_dealer_bust + (chance_dealer_scores_lower * (1 - chance_of_dealer_bust));
}