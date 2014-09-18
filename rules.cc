// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Rules.cc
// The main way poker hands are determined is through a rank counter.
// The rank counter counts how many cards of each rank are in a
// given player hand. This makes it easier to determine if there are
// pairs of a certain size, or if all cards are unique, etc.
// Regular Rules (poker) assumes HAND_SIZE will be 5

#include "rules.h"
#include "hand.h"
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

// Returns highest score 
int Rules::get_highscore() {
  return highscore_;
}

// Returns first player 
Player *RegularRules::FirstPlayer(Dealer &dealer) {
  return dealer.players_[0];
}

// Returns true of the input cards are the same suit
bool IsSameSuit(Card **hand) {
  for (int i = 0; i < HAND_SIZE - 1; i++) {
    if (hand[i]->get_suit() != hand[i+1]->get_suit()) {
      return false;
    }
  }

  return true;
}

// Returns a RoyalFlush object if the input cards
// form a Royal Flush Poker hand
Hand *IsRoyalFlush(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  bool is_royal_hand = (rank_counter[TEN] == 1 &&
    rank_counter[JACK] == 1 &&
    rank_counter[QUEEN] == 1 &&
    rank_counter[KING] == 1 &&
    rank_counter[ACE] == 1);

  if (is_royal_hand && IsSameSuit(hand)) {
    return new RoyalFlush();
  }

  return NULL;
}

// Returns a StraightFlush object if the input cards
// form a Straight Flush Poker hand
Hand *IsStraightFlush(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int num_sequential_cards = 0;
  bool is_sequential = false;
  int high_rank = 0;

  if (!IsSameSuit(hand)) {
    return NULL;
  }

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == 1) {  // Look for a sequence of HAND_SIZE 1's
      num_sequential_cards++;

      if (num_sequential_cards == HAND_SIZE) {
        is_sequential = true;
        high_rank = i;
        break;
      }
    }
    else {
      num_sequential_cards = 0;
    }
  }

  if (is_sequential && IsSameSuit(hand)) {
    return new StraightFlush(high_rank);
  }

  return NULL;
}

// Returns a FourKind object if the input cards
// form a Four of a Kind Poker hand
Hand *IsFourKind(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int num_same_cards = 4;
  int high_card = 0;

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == num_same_cards) {
      high_card = i;
      return new FourKind(high_card);
    }
  }

  return NULL;
}

// Returns a FullHouse object if the input cards
// form a Full House Poker hand
Hand *IsFullHouse(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  bool has_three_same_rank = false;
  bool has_two_same_rank = false;
  int high_three_rank = 0;

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == 3) {
      has_three_same_rank = true;
      high_three_rank = i;
      break;
    }
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == 2) {
      has_two_same_rank = true;
      break;
    }
  }

  if (has_three_same_rank && has_two_same_rank) {
    return new FullHouse(high_three_rank);
  }

  return NULL;
}

// Returns a Flush object if the input cards
// form a Flush Poker hand
Hand *IsFlush(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int rank_sorted[HAND_SIZE] = {0,0,0,0,0};
  int j = 0;

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] != 0) {
      rank_sorted[j] = i;
      j++;
    }
  }

  if (IsSameSuit(hand)) {
    return new Flush(rank_sorted[0], rank_sorted[1], rank_sorted[2],
                  rank_sorted[3], rank_sorted[4]);
  }

  return NULL;
}

// Returns a Straight object if the input cards
// form a Straight Poker hand
Hand *IsStraight(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int num_sequential_cards = 0;
  bool is_sequential = false;
  int high_rank = 0;

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == 1) {  // Look for a sequence of HAND_SIZE 1's
      num_sequential_cards++;

      if (num_sequential_cards == HAND_SIZE) {
        is_sequential = true;
        high_rank = i;
        break;
      }
    }
    else {
      num_sequential_cards = 0;
    }
  }

  if (is_sequential) {
    return new Straight(high_rank);
  }

  return NULL;
}

// Returns a ThreeKind object if the input cards
// form a Three of a Kind Poker hand
Hand *IsThreeKind(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int num_same_cards = 3;
  int high_rank = 0;

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == num_same_cards) {
      high_rank = i;
      return new ThreeKind(high_rank);
    }
  }

  return NULL;
}

// Returns a TwoPair object if the input cards
// form a Two Pair Poker hand
Hand *IsTwoPair(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int num_pairs = 0;
  int num_same_cards = 2;
  int first_pair_rank = 0;
  int second_pair_rank = 0;
  int side_rank = 0;

  int i = 0;

  for (i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == num_same_cards) {
      num_pairs++;
      first_pair_rank = i;
      break;  // Found the first pair
    }
  }

  for (int j = i+1; j < RANK_COUNT; j++) {
    if (rank_counter[j] == num_same_cards) {
      num_pairs++;
      second_pair_rank = j;
      break;  // Found the second pair
    }
  }

  for (i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == 1) {
      side_rank = i;
      break;  // Found side card
    }
  }


  if (num_pairs == 2) {
    if (first_pair_rank > second_pair_rank) {
      return new TwoPair(first_pair_rank, second_pair_rank, side_rank);
    }
    else {
      return new TwoPair(second_pair_rank, first_pair_rank, side_rank);
    }
  }

  return NULL;
}

// Returns a OnePair object if the input cards
// form a One Pair Poker hand
Hand *IsOnePair(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int sides_sorted[3] = {0,0,0};
  int num_same_cards = 2;
  bool has_pair = false;
  int pair_rank = 0;
  int j = 0;

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] == num_same_cards) {
      pair_rank = i;
      has_pair = true;
      break;
    }
  }

  if (has_pair) {
    for (int i = 0; i < RANK_COUNT; i++) {
      if (rank_counter[i] == 1) {
        sides_sorted[j] = i;
        j++;
        if (j > 2) {
          break;
        }
      }
    }

    return new OnePair(pair_rank, sides_sorted[0], sides_sorted[1],
                  sides_sorted[2]);
  }

  return NULL;
}

// Returns a HighCard object.
// This is the default option if no other poker hands are found.
Hand *IsHighCard(Card **hand) {
  int rank_counter[RANK_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int rank_sorted[HAND_SIZE] = {0,0,0,0,0};
  int j = 0;

  for (int i = 0; i < HAND_SIZE; i++) {
    rank_counter[hand[i]->get_rank()] += 1;
  }

  for (int i = 0; i < RANK_COUNT; i++) {
    if (rank_counter[i] != 0) {
      rank_sorted[j] = i;
      j++;
    }
  }

  return new HighCard(rank_sorted[0], rank_sorted[1], rank_sorted[2],
                      rank_sorted[3], rank_sorted[4]);
}

// Determine which Hand
Hand *RegularRules::DetermineHand(Card **hand) {
  Hand *new_hand = NULL;

  new_hand = IsRoyalFlush(hand);

  if (new_hand == NULL) {
    new_hand = IsStraightFlush(hand);    
  }

  if (new_hand == NULL) {
    new_hand = IsFourKind(hand);
  }

  if (new_hand == NULL) {
    new_hand = IsFullHouse(hand);
  }

  if (new_hand == NULL) {
    new_hand = IsFlush(hand);
  }

  if (new_hand == NULL) {
    new_hand = IsStraight(hand);
  }

  if (new_hand == NULL) {
    new_hand = IsThreeKind(hand);
  }

  if (new_hand == NULL) {
    new_hand = IsTwoPair(hand);
  }

  if (new_hand == NULL) {
    new_hand = IsOnePair(hand);
  }

  if (new_hand == NULL) {
    return IsHighCard(hand);
  }
  else {
    return new_hand;
  }
}

// Return true if regular poker win conditions are met.
WinResult RegularRules::CheckWin(Dealer& dealer) {
  Hand *hand_a = dealer.players_[0]->get_hand_type();
  Hand *hand_b = dealer.players_[1]->get_hand_type();

  return CheckWin(*hand_a, *hand_b);
}

// Return true if regular poker win conditions are met.
WinResult RegularRules::CheckWin(Hand &hand_a, Hand &hand_b) {
  if (hand_a.get_type() == hand_b.get_type()) {
      return CheckTie(hand_a,
                        hand_b,
                        hand_a.get_type());
  }
  else if (hand_a.get_type() > hand_b.get_type()) {
    return PLAYERONE;
  }
  else {
    return PLAYERTWO;
  }
}

// Return the result of a tie (two of the same poker hands).
// Return values are Player one wins, Player two wins, or Draw
WinResult RegularRules::CheckTie(Hand &hand_a, Hand &hand_b, int handtype) {
  bool hand_a_wins = false;
  bool hand_b_wins = false;
  Hand *base_a = &hand_a;
  Hand *base_b = &hand_b;

  switch (handtype) {
    case ROYALFLUSH: {
      RoyalFlush *casted_hand_a = dynamic_cast<RoyalFlush*>(base_a);
      RoyalFlush *casted_hand_b = dynamic_cast<RoyalFlush*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;      
    }
    case STRAIGHTFLUSH: {
      StraightFlush *casted_hand_a = dynamic_cast<StraightFlush*>(base_a);
      StraightFlush *casted_hand_b = dynamic_cast<StraightFlush*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;
    }
    case FOURKIND: {
      FourKind *casted_hand_a = dynamic_cast<FourKind*>(base_a);
      FourKind *casted_hand_b = dynamic_cast<FourKind*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;
    }
    case FULLHOUSE: {
      FullHouse *casted_hand_a = dynamic_cast<FullHouse*>(base_a);
      FullHouse *casted_hand_b = dynamic_cast<FullHouse*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;
    }
    case FLUSH: {
      Flush *casted_hand_a = dynamic_cast<Flush*>(base_a);
      Flush *casted_hand_b = dynamic_cast<Flush*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;
    }
    case STRAIGHT: {
      Straight *casted_hand_a = dynamic_cast<Straight*>(base_a);
      Straight *casted_hand_b = dynamic_cast<Straight*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;
    }
    case THREEKIND: {
      ThreeKind *casted_hand_a = dynamic_cast<ThreeKind*>(base_a);
      ThreeKind *casted_hand_b = dynamic_cast<ThreeKind*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;
    }
    case TWOPAIR: {
      TwoPair *casted_hand_a = dynamic_cast<TwoPair*>(base_a);
      TwoPair *casted_hand_b = dynamic_cast<TwoPair*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;
    }
    case ONEPAIR: {
      OnePair *casted_hand_a = dynamic_cast<OnePair*>(base_a);
      OnePair *casted_hand_b = dynamic_cast<OnePair*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
      break;
    }
    default: {
    case HIGHCARD:
      HighCard *casted_hand_a = dynamic_cast<HighCard*>(base_a);
      HighCard *casted_hand_b = dynamic_cast<HighCard*>(base_b);

      if (casted_hand_a != 0 && casted_hand_b != 0) {
        hand_a_wins = *casted_hand_a > *casted_hand_b;
        hand_b_wins = *casted_hand_b > *casted_hand_a;
      }
      assert(casted_hand_a != 0 && casted_hand_b != 0);
    }
  }

  if (hand_a_wins) {
    return PLAYERONE;
  }
  else if (hand_b_wins) {
    return PLAYERTWO;
  }
  else {
    return DRAW;
  }
}
