// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Hand.h
// Contains classes for each type of Poker hand.
// The main purpose of the Hand object is to hold unique information to
// determine a tie given two hands. It also holds the logic of comparing
// two hands to determine the outcome of a tie.
// Since the cards suit isn't used in a tie, only the rank value is stored.
// Includes: Royal Flush, Straight Flush, Four of a Kind, Full House, Flush,
// Straight, Three of a Kind, Two Pair, One Pair, and High Card.

#ifndef _HAND_
#define _HAND_

enum Hands { HIGHCARD, ONEPAIR, TWOPAIR, THREEKIND, STRAIGHT, FLUSH, FULLHOUSE,
        FOURKIND, STRAIGHTFLUSH, ROYALFLUSH };

// Holds unique properties and handles comparative logic of a Hand.
// Sample Usage:
//    hand_a_wins = (StraightFlush)hand_a > (StraightFlush)hand_b;
//    hand_b_wins = (StraightFlush)hand_b > (StraightFlush)hand_a;
//    if (hand_a_wins) {
//        cout << "Hand a wins" << endl;
//    }
class Hand {
  friend class Dealer;
public:
  virtual int get_type();
  virtual ~Hand() {};
protected:
  // Keeps track of what particular hand this is
  Hands type_;
};

class RoyalFlush : public Hand {
public:
  bool operator> (RoyalFlush &rhs);
  RoyalFlush() { type_ = ROYALFLUSH; }
};

class StraightFlush : public Hand {
public:
  bool operator> (StraightFlush &rhs);
  StraightFlush(int high_rank) { high_rank_ = high_rank;
                                    type_ = STRAIGHTFLUSH; }
private:
  // Track the high ranking card value
  int high_rank_;
};

class FourKind : public Hand {
public:
  bool operator> (FourKind &rhs);
  FourKind(int high_rank) { high_rank_ = high_rank; type_ = FOURKIND; }
private:
  // Track the high ranking card value
  int high_rank_;
};

class FullHouse : public Hand {
public:
  bool operator> (FullHouse &rhs); 
  FullHouse(int high_three) { high_three_ = high_three; type_ = FULLHOUSE; }
private:
  int high_three_;
};

class Flush : public Hand {
public:
  bool operator> (Flush &rhs);
  Flush(int first_high_rank,
        int second_high_rank,
        int third_high_rank,
        int fourth_high_rank,
        int fifth_high_rank)
  { first_high_rank_ = first_high_rank;
    second_high_rank_ = second_high_rank;
    third_high_rank_ = third_high_rank;
    fourth_high_rank_ = fourth_high_rank;
    fifth_high_rank_ = fifth_high_rank;
    type_ = FLUSH; }
private:
  // Track the high ranking card value
  int first_high_rank_;
  // Track the 2nd high ranking card value
  int second_high_rank_;
  // Track the 3rd high ranking card value
  int third_high_rank_;
  // Track the 4th high ranking card value
  int fourth_high_rank_;
  // Track the 5th high ranking card value
  int fifth_high_rank_; 
};

class Straight : public Hand {
public:
  bool operator> (Straight &rhs);
  Straight(int high_rank) { high_rank_ = high_rank; type_ = STRAIGHT; }
private:
  // Track the high ranking card value
  int high_rank_;   
};

class ThreeKind : public Hand {
public:
  bool operator> (ThreeKind &rhs);
  ThreeKind(int high_three) { high_three_ = high_three; type_ = THREEKIND; }
private:
  // Track the high ranking 3 paired cards value
  int high_three_;
};

class TwoPair : public Hand {
public:
  bool operator> (TwoPair &rhs); 
  TwoPair(int high_pair, int low_pair, int side_rank)
  { high_pair_ = high_pair;
    low_pair_ = low_pair;
    side_rank_ = side_rank;
    type_ = TWOPAIR; }
private:
  // Track the high paired cards value
  int high_pair_;
  // Track the low paired cards value
  int low_pair_;
  // Track the ranking of the side card value
  int side_rank_; 
};

class OnePair : public Hand {
public:
  bool operator> (OnePair &rhs);
  OnePair(int pair,
          int third_high_rank,
          int fourth_high_rank,
          int fifth_high_rank)
  { pair_ = pair;
    third_high_rank_ = third_high_rank;
    fourth_high_rank_ = fourth_high_rank;
    fifth_high_rank_ = fifth_high_rank;
    type_ = ONEPAIR; }
private:
  // Track the 2 paired cards value
  int pair_;
  // Track the 3rd high ranking value
  int third_high_rank_;
  // Track the 4th high ranking value
  int fourth_high_rank_;
  // Track the 5th high ranking value
  int fifth_high_rank_; 
};

class HighCard : public Hand {
public:
  bool operator> (HighCard &rhs);
  HighCard(int first_high_rank,
        int second_high_rank,
        int third_high_rank,
        int fourth_high_rank,
        int fifth_high_rank)
  { first_high_rank_ = first_high_rank;
    second_high_rank_ = second_high_rank;
    third_high_rank_ = third_high_rank;
    fourth_high_rank_ = fourth_high_rank;
    fifth_high_rank_ = fifth_high_rank;
    type_ = HIGHCARD; }
private:
  // Track the high ranking card value
  int first_high_rank_;
  // Track the 2nd high ranking card value
  int second_high_rank_;
  // Track the 3rd high ranking card value
  int third_high_rank_;
  // Track the 4th high ranking card value
  int fourth_high_rank_;
  // Track the 5th high ranking card value
  int fifth_high_rank_; 
};

#endif
