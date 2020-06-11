#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>

using namespace std;

const int BUST = 21;  // a hand in blackjack is a bust if its sum is greater than this number

// card code constants

const int ACE = 0;
const int JACK = 10;
const int QUEEN = 11;
const int KING = 12;

// represents a hand of cards with a vector containing integers 0 - 12 to encode the 13 cards
// suit does not matter in blackjack
// 0 = ace
// 1 - 9 = cards 2 - 10
// 10 = jack
// 11 = queen
// 12 = king
class Hand
{
  private:
    vector<int> cards;  // vector containing the hand of cards
    bool hole_card;     // if the first card of the hand should be face-down
  public:
    Hand() {hole_card = false;} // default constuctor
    Hand(int *, int); // constructor for initializing hand from array
    void add_card(int card) {cards.push_back(card);}
    void remove_card() {cards.pop_back();}
    void set_hole_card(bool b) {hole_card = b;}
    void print() const;
    int sum() const;
};

#endif