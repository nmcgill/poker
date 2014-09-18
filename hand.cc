// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Hand.cc
// Different overrides of the greater than operator depending on the hand
// objects being compared

#include "hand.h"

using namespace std;

int Hand::get_type() {
  return type_;
}

bool RoyalFlush::operator> (RoyalFlush &rhs) {
  return false;
}

bool StraightFlush::operator> (StraightFlush &rhs) {
  return this->high_rank_ > rhs.high_rank_;
}

bool FourKind::operator> (FourKind &rhs) {
  return this->high_rank_ > rhs.high_rank_;
}

bool FullHouse::operator> (FullHouse &rhs) {
  return this->high_three_ > rhs.high_three_;
}

bool Flush::operator> (Flush &rhs) {
  if (this->first_high_rank_ > rhs.first_high_rank_) {
    return true;
  }
  else if (this->second_high_rank_ > rhs.second_high_rank_) {
    return true;
  }
  else if (this->third_high_rank_ > rhs.third_high_rank_) {
    return true;
  }
  else if (this->fourth_high_rank_ > rhs.fourth_high_rank_) {
    return true;
  }
  else if (this->fifth_high_rank_ > rhs.fifth_high_rank_) {
    return true;
  }
  else {
    return false;
  }
}

bool Straight::operator> (Straight &rhs) {
  return this->high_rank_ >
      rhs.high_rank_;
}

bool ThreeKind::operator> (ThreeKind &rhs) {
  return this->high_three_ >
      rhs.high_three_;
}

bool TwoPair::operator> (TwoPair &rhs) {
  if (this->high_pair_ > rhs.high_pair_) {
    return true;
  }
  else if (this->low_pair_ > rhs.low_pair_) {
    return true;
  }
  else if (this->side_rank_ > rhs.side_rank_) {
    return true;
  }
  else {
    return false;
  }
}

bool OnePair::operator> (OnePair &rhs) {
  if (this->pair_ > rhs.pair_) {
    return true;
  }
  else if (this->third_high_rank_ > rhs.third_high_rank_) {
    return true;
  }
  else if (this->fourth_high_rank_ > rhs.fourth_high_rank_) {
    return true;
  }
  else if (this->fifth_high_rank_ > rhs.fifth_high_rank_) {
    return true;
  }
  else {
    return false;
  }
}

bool HighCard::operator> (HighCard &rhs) {
  if (this->first_high_rank_ > rhs.first_high_rank_) {
    return true;
  }
  else if (this->second_high_rank_ > rhs.second_high_rank_) {
    return true;
  }
  else if (this->third_high_rank_ > rhs.third_high_rank_) {
    return true;
  }
  else if (this->fourth_high_rank_ > rhs.fourth_high_rank_) {
    return true;
  }
  else if (this->fifth_high_rank_ > rhs.fifth_high_rank_) {
    return true;
  }
  else {
    return false;
  }
}