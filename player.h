// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Player.h
// Contains the Player class. Derived class: ComputerPlayer.
// TODO: In the future, a HumanPlayer class could be implemented.

#include "card.h"
#include "dealer.h"
#include "command.h"
#include "hand.h"

#ifndef _PLAYER_
#define _PLAYER_

class Dealer;

// The player object holds the score, and cards in the player's hand.
// A player object should be allocated and freed by the Dealer class.
// The command implementation must be defined in a derived class.
// Sample Usage:
//    Player* player = new ComputerPlayer(i+1);
//    player->PrintHand();
//    delete player;
class Player {
  friend class Dealer;
public:
  Player() { id_ = 0; score_ = 0; }
  Player(int id) { id_ = id; score_ = 0; }
  Player(int id, int score) { id_ = id; score_ = score; } 
  // Execute a command. Typically from user input
  virtual bool DoCommand(Dealer& dealer) = 0;
  // Output all cards in the player's hand to standard output
  void PrintHand();
  Hand *get_hand_type();
  int get_score();
  int get_id();
  virtual ~Player() {};
protected:
  // Tracks the cards in the players hand
  Card *hand_[HAND_SIZE];
  // Tracks what type of Poker Hand the player has
  Hand *hand_type_;
  // Tracks the unique player ID
  int id_;
  // Tracks the player score
  int score_;
};

#endif

#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

// A computer player's command function acts as a sort of AI and
// attempts to determine the best play possible.
class ComputerPlayer : public Player {
public:
  ComputerPlayer() : Player(0) {};
  ComputerPlayer(int i) : Player(i, 0)  {};
  ComputerPlayer(int i, int s) : Player(i, s)  {};
  bool DoCommand(Dealer&);
};

#endif