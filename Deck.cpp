#include "Deck.h"

// sets the card_amounts array to 4 for every card
void Deck::reset()
{
    for(int i = 0; i < CARDS; i++)
        card_amounts[i] = SUITS; // each card number appears 4 times in a deck of 52 cards; one per suit
}

// number of cards remaining in the deck
int Deck::size() const
{
    int total = 0;
    for(int i = 0; i < CARDS; i++)
        total += card_amounts[i];
    return total;
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

    if(size() == 0)
        return -1; // cannot draw a card from an empty deck

    position = rand() % size();   // pick the random card position

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

// returns the probability of drawing a card with a value in a specific range
// if min is greater than max, returns probability of a value outside the range between max and min
// counts aces as 11 unless ace_one is true
float Deck::chance_of_drawing_card_in_range(int min, int max, bool ace_one) const
{
    int cards_in_range = 0; // number of cards with value in the range
    if(max == -1) // use default argument of max so a single argument can be used to find one value
        max = min;
    // loop through the card codes, determine their values, and add to total if in range
    for(int i = 0; i < CARDS; i++)
    {
        int val; // card value
        if(i >= 9) // 10, J, Q, K
            val = 10;
        else if(i > 0) // 2 - 9
            val = i + 1;
        else if(ace_one) // count aces as 1
            val = 1;
        else // count aces as 11
            val = 11;
        
        // if the value falls in range, add the amount of this card to the total of cards in range
        if((max >= min && val >= min && val <= max) || (min > max && (val <= max || val >= min)))
            cards_in_range += card_amounts[i];
    }

    // floating-point division of cards in range over total cards in the deck
    return cards_in_range / static_cast<float>(size());
}