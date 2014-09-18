// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Rules.h
// Contains the Rule class. Derived class: RegularRules.
// Rules should always be contained in the Dealer class. 
// The dealer class handles allocation and deallocation.

#include "card.h"
#include "player.h"
#include "dealer.h"
#include "hand.h"

#ifndef _RULES_
#define _RULES_

enum WinResult { PLAYERONE, PLAYERTWO, DRAW };

class Dealer;

// Rules outlines the win conditions of a particular game
// Sample Usage:
//    Dealer *d = new Dealer();
//    ...
//    if (d->CheckWin(*d)) {
//        cout << "Game over" << endl;
//    }
class Rules {
public:
  Rules() { highscore_ = 0; }
  // Determines the first player in a round.
  virtual Player *FirstPlayer(Dealer& dealer) = 0;
  // Determines the win conditions. Returns true if the conditions are met.
  virtual WinResult CheckWin(Dealer& dealer) = 0;
  int get_highscore();
  virtual ~Rules() {};
protected:
  // Track the highest score seen so far in the game
  int highscore_;
};

#endif

#ifndef _REGULARRULES_
#define _REGULARRULES_

// Regular Poker Rules based on a 52 card deck, 5 card stud
class RegularRules : public Rules {
public:
  Player *FirstPlayer(Dealer&);
  WinResult CheckWin(Dealer&);
  WinResult CheckWin(Hand&, Hand&);
  // Returns the Poker Hand given a players hand
  Hand *DetermineHand(Card**);
  // Determine which two hands wins given a tie
  WinResult CheckTie(Hand&, Hand&, int);
};

#endif