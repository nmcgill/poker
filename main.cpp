// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// main.cpp
// The DEBUG varliable should be defined if you wish to input cards yourself.
// The debug build will expect cards to be input from the program's arguements.
// If DEBUG is not defined, the Dealer class will Deal the cards automatically.
// If DEBUG is not defined, the program's argument (optional) is used as a seed
// for the random number function.

//#define DEBUG
#include "dealer.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
  Dealer *my_dealer = new Dealer();

#ifdef DEBUG
  cout << "Running debug build..." << endl;
  my_dealer->DebugDeal(argc, argv);
#else
  if (argc > 1) {
    srand48(atoi(argv[1]));
  }
  else {
    srand48(0);
  }

  my_dealer->Deal();
#endif

  delete my_dealer;
  
  return(0);
}