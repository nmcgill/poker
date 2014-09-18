// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Player.cc

#include "player.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Hand *Player::get_hand_type() {
  return hand_type_;
}

// Returns players score
int Player::get_score() {
  return score_;
}

// Returns players unqiue id
int Player::get_id() {
  return id_;
}

// Prints all cards within a players hand
void Player::PrintHand() {
  for (int i = 0; i < HAND_SIZE; i++) {
    if (hand_[i] != NULL) {
      cout << " " << *hand_[i];
    }
  }
  
  cout << endl;
}

// Returns true if command is valid
bool ComputerPlayer::DoCommand(Dealer &dealer) {

  cout << "Player " << id_ << " plays ";
  PrintHand();

  return true;
}