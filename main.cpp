// Test

#include <iostream>
#include "Hand.h"

using namespace std;

int main()
{
  Hand *hand = new Hand;

  hand->add_card(0);
  hand->add_card(9);
  hand->add_card(12);
  hand->add_card(5);
  hand->add_card(10);

  hand->print();

  delete hand;
  system("pause");
  return 0;
}
