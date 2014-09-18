// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Dealer.h
// Contains the Dealer class. The dealer holds the game loop and acts
// as the players judge and jury.

// The amount of total game cards
#define CARD_COUNT 52
// The size of a player's hand
#define HAND_SIZE 5
// The amount of players
#define PLAYER_COUNT 2

#ifndef _DEALER_
#define _DEALER_

#include "card.h"
#include "player.h"
#include "rules.h"

// Holds the game loop. Sample Usage:
//  Dealer *my_dealer = new Dealer();
//  my_dealer->Deal();
//  delete my_dealer;
class Dealer {
  friend class RegularRules;
  friend class Rules;
public:
  Dealer();
  // Deals cards to each player.
  void Deal();
  // Deals cards to each player in the debug build.
  // Input: program arguments
  void DebugDeal(int argc, char** argv);
  // Randomly positions cards in the deck.
  void Shuffle();
  // Start the game loop.
  void StartRound();
  // Returns the positon of the input card in the deck.
  int CardPosition(Card card);
  // Returns the player who is currently active in the game loop.
  Player *get_current_player();
  // Returns the hand of a particular player.
  // Input: player id number
  Card **get_player_hand(int id);
  ~Dealer();
private:
  // Keeps track of all players in the game.
  // This must contain atleast 2 player objects.
  Player *players_[PLAYER_COUNT];
  // Keeps track of all cards in the game.
  Card *deck_[CARD_COUNT];
  // Holds the game rules.
  Rules *ruleset_;
  // A pointer to the player who is currently active in the game loop.
  Player *current_player_;
};

#endif