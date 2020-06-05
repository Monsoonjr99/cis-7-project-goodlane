// Test

#include <iostream>
#include "Hand.h"

using namespace std;

int main()
{
  Hand *hand = new Hand;

  hand->add_card(0);
  hand->add_card(12);
  hand->add_card(5);

  hand->print();

  cout << "The sum is: " << hand->sum() << endl;

  delete hand;
  system("pause");
  return 0;
}
