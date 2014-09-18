// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Dealer.cc
// The constructor creates card, rule, and player objects.

#include "dealer.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Dealer::Dealer() {
  ruleset_ = new RegularRules();

  for (int i = 0; i < CARD_COUNT; i++) {
    deck_[i] = new Card((Suit)((int)(i/(Rank)RANK_COUNT)), 
                      (Rank)(i%(Rank)RANK_COUNT));
  }

  for (int i = 0; i < PLAYER_COUNT; i++) {
    players_[i] = new ComputerPlayer(i+1);
    players_[i]->score_ = 0;
  }
}

Dealer::~Dealer() {
  for (int i = 0; i < PLAYER_COUNT; i++) {
    if (players_[i]->hand_type_ != 0) {
      delete players_[i]->hand_type_;
    }

    delete players_[i];
  }

  for (int i = 0; i < CARD_COUNT; i++) {
    delete deck_[i];
  }
  
  delete ruleset_;
}

// Deals cards to each player
void Dealer::Deal() {
  Shuffle();

  for (int i = 0; i < PLAYER_COUNT; i++) {
    for (int j = 0; j < HAND_SIZE; j++) {
      players_[i]->hand_[j] = deck_[(i*HAND_SIZE)+j];
    }
  }

  StartRound();
}

// Debug mode deals cards to each player from the program arguements
void Dealer::DebugDeal(int argc, char* argv[]) {
  Card card;

  if (argc != PLAYER_COUNT*HAND_SIZE + 1) {
    cout << "Debug Usage: " << PLAYER_COUNT*HAND_SIZE <<
    " cards with format <Rank><Suit>" << endl;
    exit(-1);
  }

  Shuffle();

  for (int i = 0; i < PLAYER_COUNT*HAND_SIZE; i++) {
    stringstream ss(argv[i+1]);
    ss >> card;
    players_[i/HAND_SIZE]->hand_[i%HAND_SIZE] = deck_[CardPosition(card)];
  }

  StartRound();
}

// Shuffles the deck
void Dealer::Shuffle() {
  int n = CARD_COUNT;
  int k;

  while ( n > 1 ) {
    k = (int) (lrand48() % n);
    --n;
    Card *c = deck_[n];
    deck_[n] = deck_[k];
    deck_[k] = c;
  }
}

// The game loop
void Dealer::StartRound() {
  int num_turns = 0;
  int player_pos;

  current_player_ = ruleset_->FirstPlayer(*this);
  cout << "A new round begins. It's player " <<
      current_player_->get_id() << "'s turn to play." << endl;
  
  while (num_turns < PLAYER_COUNT) {
    if ((current_player_->DoCommand(*this))) {
      num_turns++;
      player_pos = current_player_->get_id() - 1;
      current_player_ = players_[player_pos];
      current_player_->hand_type_ = dynamic_cast<RegularRules*>(ruleset_)->
                                                  DetermineHand(
                                                  get_player_hand(player_pos));
      current_player_->score_ = current_player_->hand_type_->get_type();
            
      current_player_ = players_[player_pos + 1];
    }
  }

  WinResult result = ruleset_->CheckWin(*this);

  if (result == PLAYERONE) {
    cout << "Player 1 wins!" << endl;
  }
  else if (result == PLAYERTWO) {
    cout << "Player 2 wins!" << endl;
  }
  else if (result == DRAW) {
    cout << "Draw Game!" << endl;
  }

  return;
}

// Returns the position of an input card c in the deck
int Dealer::CardPosition(Card c)
{
  for (int i = 0; i < CARD_COUNT; i++)
  {
    if (deck_[i] != NULL)
    {
      if (*deck_[i] == c)
        return i;
    }
  }
  
  return -1;
}

// Returns current player
Player *Dealer::get_current_player() {
  return current_player_;
}

// Returns the players hand
Card **Dealer::get_player_hand(int id) {
  return players_[id]->hand_;
}