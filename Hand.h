#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>

using namespace std;

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
  public:
    Hand() {} // default constuctor
    Hand(int *, int); // constructor for initializing hand from array
    void add_card(int card) {cards.push_back(card);}
    void remove_card() {cards.pop_back();}
    void print() const;
    int sum() const;
};

#endif