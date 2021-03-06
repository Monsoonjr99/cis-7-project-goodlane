#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include <ctime>

using namespace std;

const int CARDS = 13; // how many different cards there are excluding suit
const int SUITS = 4; // how many of each card there are in a deck

// represents a deck of cards abstractly by using an array containing the amounts of each card number
// shuffling is simulated by drawing a card from a random position in an ordered deck
class Deck
{
    private:
        int card_amounts[CARDS];
    public:
        Deck() {reset();} // default constructor
        void reset(); // sets all card amounts to 4
        int size() const; // returns how many cards are left in the deck
        int draw(); // draws a random card from the deck; decreases the amount of that card by 1 and returns the card number
        float chance_of_drawing_card_in_range(int, int = -1, bool = false) const; // returns probability of drawing a card with a value in range
};

#endif