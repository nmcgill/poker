// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Card.cc
// Includes Card object constructor, and implementation of the equivalence
// operator and the standard in/out of a Card object.

#include "card.h"
#include <string>
#include <cassert>

using namespace std;

Card::Card(Suit suit, Rank rank) {
  suit_ = suit;
  rank_ = rank;
}

Suit Card::get_suit() const {
  return suit_;
}

Rank Card::get_rank() const {
  return rank_;
}

bool operator==(const Card &a, const Card &b) {
  return a.get_suit() == b.get_suit() && a.get_rank() == b.get_rank();
}

// Handles output of a Card object
ostream &operator<<(ostream &out, const Card &card) {
  string suits[SUIT_COUNT] = {"C", "D", "H", "S"};
  string ranks[RANK_COUNT] = {"2", "3", "4", "5", "6",
    "7", "8", "9", "10", "J", "Q", "K", "A"};
    
  out << ranks[card.get_rank()] << suits[card.get_suit()];
  
  return out;
}

// Handles input to a Card object
istream &operator>>(istream &in, Card &c) {
  string suits = "CDHS", ranks = "234567891JQKA";
  
  string str;
  in >> str;

  assert ( !in.fail() );
  
  // Read in the rank
  c.rank_ = (Rank)ranks.find( str.at(0) );
  assert ( c.rank_ != string::npos );
  
  // If it's a 10, make sure the 2nd character is a 0
  if ( c.rank_ == TEN ) {
    assert(str.at(1) == '0');
    str.at(1) = str.at(2);  // Ensure the Suit value is the 2nd character
  }
  
  // Read in the suit, make sure it's valid
  c.suit_ = (Suit)suits.find( str.at(1) );
  assert ( c.suit_ != string::npos );
  
  return in;
}
