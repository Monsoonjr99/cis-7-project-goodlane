#include "Deck.h"

// sets the card_amounts array to 4 for every card
void Deck::reset()
{
    for(int i = 0; i < CARDS; i++)
        card_amounts[i] = SUITS; // each card number appears 4 times in a deck of 52 cards; one per suit
}

// draws a random card from the deck; decreases the amount of that card by 1 and returns the card number
// selecting a card from a random position of an ordered deck simulates shuffling
int Deck::draw()
{
    // seed the random number generator
    static bool rand_seeded = false;
    if(!rand_seeded)
    {
        srand(time(0));
        rand_seeded = true;
    }

    int picked_card = 0; // card code of the card drawn
    int position; // number representing a randomly selected card position in the deck, assuming an order of aces, 2s, 3s, ... Ks
    int deck_sum = 0; // total number of cards remaining in the deck
    for(int i = 0; i < CARDS; i++)
        deck_sum += card_amounts[i];

    if(deck_sum == 0)
        return -1; // cannot draw a card from an empty deck

    position = rand() % deck_sum;   // pick the random card position

    // loop through the deck to find the picked card
    // if the position is beyond the range of a type of card, subtract that card's amount from position and advance to the next card code
    while(position >= card_amounts[picked_card])
    {
        position -= card_amounts[picked_card];
        picked_card++;
    }

    card_amounts[picked_card]--; // remove the card from the deck

    return picked_card;
}