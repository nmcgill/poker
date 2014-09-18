// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Command.h
// Contains the command class. The command class is used to translate and
// structure user input as a valid game command. Used by the Player class.

#ifndef _COMMAND_
#define _COMMAND_

#include "card.h"
#include <istream>

enum Type { PLAY, QUIT, RAGEQUIT, BAD_COMMAND };

// Sample usage:
//    Command myCommand;
//    cin >> myCommand;
//    if (myCommand.type == PLAY) {
//      cout << "Player 1 plays " << myCommand.card << "." << endl;
//    }
struct Command{
  Type type;
  Card card;
  
  Command() : type(BAD_COMMAND), card(SPADE, ACE) {}
};

std::istream &operator>>(std::istream &, Command &);

#endif