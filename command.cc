// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Command.cc
// Translates user input in to a valid game command. A typical command holds
// an action and a card. Example: play 4H
// Actions:
// play - play a card
// quit - quit the game
// ragequit - replaces a human with a computer player

#include "command.h"
#include <cassert>
#include <sstream>

using namespace std;

istream &operator>>(istream &in, Command &c) {
  c.type = BAD_COMMAND;

  string str;
  getline(in, str);
  stringstream ss(str);
  
  string cmd;
  ss >> cmd;
  
  if (cmd == "play") {
    c.type = PLAY;
  } else if (cmd == "quit") {
    c.type = QUIT;
  } else if (cmd == "ragequit") {
    c.type = RAGEQUIT;
  }
  
  assert(!in.fail() && !ss.fail() && c.type != BAD_COMMAND);
  
  return in;
}
