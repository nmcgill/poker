// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// More extensive Tie breaker tests are found within hand_unittest

#include "rules.h"
#include "gtest/gtest.h"

void CleanTest(Card **hand) {
  for (int i = 0; i < HAND_SIZE; i++) {
    delete hand[i];
  }
}

void CleanTest(Card **hand, Hand *result) {
  for (int i = 0; i < HAND_SIZE; i++) {
    delete hand[i];
  }

  delete result;
}

// Tests the high score getter
TEST(RulesTest, HighScore) {
  RegularRules rules = RegularRules();

  ASSERT_EQ(0, rules.get_highscore());
}

// Tests Royal Card logic
TEST(RulesTest, IsRoyalFlush) {
  RegularRules rules = RegularRules();
  RoyalFlush* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four of a Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<RoyalFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests Straight Flush logic
TEST(RulesTest, IsStraightFlush) {
  RegularRules rules = RegularRules();
  StraightFlush* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four of a Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<StraightFlush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests Four of a Kind logic
TEST(RulesTest, IsFourKind) {
  RegularRules rules = RegularRules();
  FourKind* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not Four of a Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FourKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests Full House logic
TEST(RulesTest, IsFullHouse) {
  RegularRules rules = RegularRules();
  FullHouse* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four of a Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<FullHouse*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests Flush logic
TEST(RulesTest, IsFlush) {
  RegularRules rules = RegularRules();
  Flush* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four of a Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not Flush returned";
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Flush*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests Straight logic
TEST(RulesTest, IsStraight) {
  RegularRules rules = RegularRules();
  Straight* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";;
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<Straight*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests Three of a Kind logic
TEST(RulesTest, IsThreeKind) {
  RegularRules rules = RegularRules();
  ThreeKind* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";;
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<ThreeKind*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests Two Pair logic
TEST(RulesTest, IsTwoPair) {
  RegularRules rules = RegularRules();
  TwoPair* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";;
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<TwoPair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests One Pair logic
TEST(RulesTest, IsOnePair) {
  RegularRules rules = RegularRules();
  OnePair* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";;
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<OnePair*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "High Card returned";
  CleanTest(cards, result);
}

// Tests HighCard logic
TEST(RulesTest, IsHighCard) {
  RegularRules rules = RegularRules();
  HighCard* casted_card;
  Card *cards[HAND_SIZE];
  Hand *result;

  // Royal flush
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(SPADE, KING);
  cards[2] = new Card(SPADE, QUEEN);
  cards[3] = new Card(SPADE, JACK);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Royal Flush returned";
  CleanTest(cards, result);

  // Straight flush
  cards[0] = new Card(SPADE, FIVE);
  cards[1] = new Card(SPADE, SIX);
  cards[2] = new Card(SPADE, SEVEN);
  cards[3] = new Card(SPADE, EIGHT);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight Flush returned";
  CleanTest(cards, result);

  // Four of a Kind
  cards[0] = new Card(SPADE, ACE);
  cards[1] = new Card(HEART, ACE);
  cards[2] = new Card(DIAMOND, ACE);
  cards[3] = new Card(CLUB, ACE);
  cards[4] = new Card(SPADE, NINE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Four Kind returned";
  CleanTest(cards, result);

  // Full House
  cards[0] = new Card(SPADE, KING);
  cards[1] = new Card(HEART, KING);
  cards[2] = new Card(DIAMOND, KING);
  cards[3] = new Card(CLUB, TEN);
  cards[4] = new Card(SPADE, TEN);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Full House returned";
  CleanTest(cards, result);

  // Flush
  cards[0] = new Card(SPADE, QUEEN);
  cards[1] = new Card(SPADE, EIGHT);
  cards[2] = new Card(SPADE, SIX);
  cards[3] = new Card(SPADE, FOUR);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Flush returned";;
  CleanTest(cards, result);

  // Straight
  cards[0] = new Card(DIAMOND, TWO);
  cards[1] = new Card(SPADE, THREE);
  cards[2] = new Card(CLUB, FOUR);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Straight returned";
  CleanTest(cards, result);

  // Three of a Kind
  cards[0] = new Card(DIAMOND, JACK);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, JACK);
  cards[3] = new Card(DIAMOND, FIVE);
  cards[4] = new Card(SPADE, SIX);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Three of a Kind returned";
  CleanTest(cards, result);

  // Two Pair
  cards[0] = new Card(DIAMOND, TEN);
  cards[1] = new Card(SPADE, TEN);
  cards[2] = new Card(CLUB, SIX);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, KING);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "Two Pair returned";
  CleanTest(cards, result);

  // One Pair
  cards[0] = new Card(DIAMOND, ACE);
  cards[1] = new Card(SPADE, ACE);
  cards[2] = new Card(CLUB, EIGHT);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, TWO);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_FALSE( casted_card != 0 ) << "One Pair returned";
  CleanTest(cards, result);

  // HIGH CARD
  cards[0] = new Card(DIAMOND, KING);
  cards[1] = new Card(SPADE, JACK);
  cards[2] = new Card(CLUB, TEN);
  cards[3] = new Card(DIAMOND, SIX);
  cards[4] = new Card(SPADE, THREE);

  result = rules.DetermineHand(cards);

  casted_card = dynamic_cast<HighCard*>(result);
  ASSERT_TRUE( casted_card != 0 ) << "Not High Card returned";
  CleanTest(cards, result);
}

// Test what a Royal Flush beats
TEST(RulesTest, CheckWinRoyalFlush) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Royal flush
  cards_a[0] = new Card(SPADE, ACE);
  cards_a[1] = new Card(SPADE, KING);
  cards_a[2] = new Card(SPADE, QUEEN);
  cards_a[3] = new Card(SPADE, JACK);
  cards_a[4] = new Card(SPADE, TEN);

  hand_a = rules.DetermineHand(cards_a);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats StraightFlush";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats FourKind";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats FullHouse";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats Flush";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats Straight";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats TwoPair";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats HighCard";
  CleanTest(cards_b, hand_b);

  CleanTest(cards_a, hand_a);
}

// Test what a Straight Flush beats
TEST(RulesTest, CheckWinStraightFlush) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Straight flush
  cards_a[0] = new Card(SPADE, FIVE);
  cards_a[1] = new Card(SPADE, SIX);
  cards_a[2] = new Card(SPADE, SEVEN);
  cards_a[3] = new Card(SPADE, EIGHT);
  cards_a[4] = new Card(SPADE, NINE);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats StraightFlush";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "StraightFlush beats FourKind";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "StraightFlush beats FullHouse";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "StraightFlush beats Flush";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "StraightFlush beats Straight";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "StraightFlush beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "StraightFlush beats TwoPair";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "StraightFlush beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "StraightFlush beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

// Test what a Four of a Kind beats
TEST(RulesTest, CheckWinFourKind) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Four of a Kind
  cards_a[0] = new Card(SPADE, ACE);
  cards_a[1] = new Card(HEART, ACE);
  cards_a[2] = new Card(DIAMOND, ACE);
  cards_a[3] = new Card(CLUB, ACE);
  cards_a[4] = new Card(SPADE, NINE);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats FourKind";
  CleanTest(cards_b, hand_b);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats FourKind";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats FullHouse";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats Flush";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats Straight";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats TwoPair";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

// Test what a Full House beats
TEST(RulesTest, CheckWinFullHouse) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Full House
  cards_a[0] = new Card(SPADE, KING);
  cards_a[1] = new Card(HEART, KING);
  cards_a[2] = new Card(DIAMOND, KING);
  cards_a[3] = new Card(CLUB, TEN);
  cards_a[4] = new Card(SPADE, TEN);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats FullHouse";
  CleanTest(cards_b, hand_b);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats FullHouse";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats FullHouse";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats Flush";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats Straight";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats TwoPair";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

// Test what a Flush beats
TEST(RulesTest, CheckWinFlush) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Flush
  cards_a[0] = new Card(SPADE, QUEEN);
  cards_a[1] = new Card(SPADE, EIGHT);
  cards_a[2] = new Card(SPADE, SIX);
  cards_a[3] = new Card(SPADE, FOUR);
  cards_a[4] = new Card(SPADE, THREE);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats Flush";
  CleanTest(cards_b, hand_b);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats Flush";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats Flush";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats Flush";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats Straight";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats TwoPair";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

// Test what a Straight beats
TEST(RulesTest, CheckWinStraight) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;
  
  // Straight
  cards_a[0] = new Card(DIAMOND, TWO);
  cards_a[1] = new Card(SPADE, THREE);
  cards_a[2] = new Card(CLUB, FOUR);
  cards_a[3] = new Card(DIAMOND, FIVE);
  cards_a[4] = new Card(SPADE, SIX);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats Straight";
  CleanTest(cards_b, hand_b);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats Straight";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats Straight";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats Straight";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats Straight";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats TwoPair";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

// Test what a Three of a Kind beats
TEST(RulesTest, CheckWinThreeKind) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Three of a Kind
  cards_a[0] = new Card(DIAMOND, JACK);
  cards_a[1] = new Card(SPADE, JACK);
  cards_a[2] = new Card(CLUB, JACK);
  cards_a[3] = new Card(DIAMOND, FIVE);
  cards_a[4] = new Card(SPADE, SIX);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats ThreeKind";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "ThreeKind beats TwoPair";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "ThreeKind beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "ThreeKind beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

// Test what a TwoPair beats
TEST(RulesTest, CheckWinTwoPair) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;
  
  // Two Pair
  cards_a[0] = new Card(DIAMOND, TEN);
  cards_a[1] = new Card(SPADE, TEN);
  cards_a[2] = new Card(CLUB, SIX);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, KING);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats TwoPair";
  CleanTest(cards_b, hand_b);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats TwoPair";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats TwoPair";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats TwoPair";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats TwoPair";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats TwoPair";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "ThreeKind beats TwoPair";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "TwoPair beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "TwoPair beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

// Test what a OnePair beats
TEST(RulesTest, CheckWinOnePair) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;
  
  // One Pair
  cards_a[0] = new Card(DIAMOND, ACE);
  cards_a[1] = new Card(SPADE, ACE);
  cards_a[2] = new Card(CLUB, EIGHT);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, TWO);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats OnePair";
  CleanTest(cards_b, hand_b);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats OnePair";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats OnePair";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats OnePair";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats OnePair";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats OnePair";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "ThreeKind beats OnePair";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "TwoPair beats OnePair";
  CleanTest(cards_b, hand_b);

  // HIGH CARD
  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(0, rules.CheckWin(*hand_a, *hand_b) ) 
      << "OnePair beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

// Test what a HighCard beats
TEST(RulesTest, CheckWinHighCard) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;
  
  // HIGH CARD
  cards_a[0] = new Card(DIAMOND, KING);
  cards_a[1] = new Card(SPADE, JACK);
  cards_a[2] = new Card(CLUB, TEN);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, THREE);

  hand_a = rules.DetermineHand(cards_a);

  // Royal flush
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "RoyalFlush beats HighCard";
  CleanTest(cards_b, hand_b);

  // Straight flush
  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats HighCard";
  CleanTest(cards_b, hand_b);

  // Four of a Kind
  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FourKind beats HighCard";
  CleanTest(cards_b, hand_b);

  // Full House
  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "FullHouse beats HighCard";
  CleanTest(cards_b, hand_b);

  // Flush
  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Flush beats HighCard";
  CleanTest(cards_b, hand_b);

  // Straight
  cards_b[0] = new Card(DIAMOND, TWO);
  cards_b[1] = new Card(SPADE, THREE);
  cards_b[2] = new Card(CLUB, FOUR);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "Straight beats HighCard";
  CleanTest(cards_b, hand_b);

  // Three of a Kind
  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "ThreeKind beats HighCard";
  CleanTest(cards_b, hand_b);

  // Two Pair
  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "TwoPair beats HighCard";
  CleanTest(cards_b, hand_b);

  // One Pair
  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_b = rules.DetermineHand(cards_b);
  ASSERT_EQ(1, rules.CheckWin(*hand_a, *hand_b) ) 
      << "OnePair beats HighCard";
  CleanTest(cards_b, hand_b);
  
  CleanTest(cards_a, hand_a);
}

TEST(RulesTest, CheckTieRoyalFlush) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Royal flush 
  cards_a[0] = new Card(SPADE, ACE);
  cards_a[1] = new Card(SPADE, KING);
  cards_a[2] = new Card(SPADE, QUEEN);
  cards_a[3] = new Card(SPADE, JACK);
  cards_a[4] = new Card(SPADE, TEN);

  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(SPADE, QUEEN);
  cards_b[3] = new Card(SPADE, JACK);
  cards_b[4] = new Card(SPADE, TEN);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests StraightFlush Tie
TEST(RulesTest, CheckTieStraightFlush) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Straight flush 
  cards_a[0] = new Card(SPADE, FIVE);
  cards_a[1] = new Card(SPADE, SIX);
  cards_a[2] = new Card(SPADE, SEVEN);
  cards_a[3] = new Card(SPADE, EIGHT);
  cards_a[4] = new Card(SPADE, NINE);

  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests StraightFlush Tie
TEST(RulesTest, CheckTieStraightFlushLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Straight flush 
  cards_a[0] = new Card(SPADE, SIX);
  cards_a[1] = new Card(SPADE, SEVEN);
  cards_a[2] = new Card(SPADE, EIGHT);
  cards_a[3] = new Card(SPADE, NINE);
  cards_a[4] = new Card(SPADE, TEN);

  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(SPADE, SIX);
  cards_b[2] = new Card(SPADE, SEVEN);
  cards_b[3] = new Card(SPADE, EIGHT);
  cards_b[4] = new Card(SPADE, NINE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests FourKind Tie
TEST(RulesTest, CheckTieFourKind) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // FourKind 
  cards_a[0] = new Card(SPADE, ACE);
  cards_a[1] = new Card(HEART, ACE);
  cards_a[2] = new Card(DIAMOND, ACE);
  cards_a[3] = new Card(CLUB, ACE);
  cards_a[4] = new Card(SPADE, NINE);

  cards_b[0] = new Card(SPADE, ACE);
  cards_b[1] = new Card(HEART, ACE);
  cards_b[2] = new Card(DIAMOND, ACE);
  cards_b[3] = new Card(CLUB, ACE);
  cards_b[4] = new Card(SPADE, NINE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests FourKind Tie
TEST(RulesTest, CheckTieFourKindLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // FourKind 
  cards_a[0] = new Card(SPADE, ACE);
  cards_a[1] = new Card(HEART, ACE);
  cards_a[2] = new Card(DIAMOND, ACE);
  cards_a[3] = new Card(CLUB, ACE);
  cards_a[4] = new Card(SPADE, NINE);

  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, KING);
  cards_b[4] = new Card(SPADE, NINE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests FullHouse Tie
TEST(RulesTest, CheckTieFullHouse) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // FullHouse 
  cards_a[0] = new Card(SPADE, KING);
  cards_a[1] = new Card(HEART, KING);
  cards_a[2] = new Card(DIAMOND, KING);
  cards_a[3] = new Card(CLUB, TEN);
  cards_a[4] = new Card(SPADE, TEN);

  cards_b[0] = new Card(SPADE, KING);
  cards_b[1] = new Card(HEART, KING);
  cards_b[2] = new Card(DIAMOND, KING);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests FullHouse Tie
TEST(RulesTest, CheckTieFullHouseLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // FullHouse 
  cards_a[0] = new Card(SPADE, KING);
  cards_a[1] = new Card(HEART, KING);
  cards_a[2] = new Card(DIAMOND, KING);
  cards_a[3] = new Card(CLUB, TEN);
  cards_a[4] = new Card(SPADE, TEN);

  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(HEART, QUEEN);
  cards_b[2] = new Card(DIAMOND, QUEEN);
  cards_b[3] = new Card(CLUB, TEN);
  cards_b[4] = new Card(SPADE, TEN);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests Flush Tie
TEST(RulesTest, CheckTieFlush) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Flush 
  cards_a[0] = new Card(SPADE, QUEEN);
  cards_a[1] = new Card(SPADE, EIGHT);
  cards_a[2] = new Card(SPADE, SIX);
  cards_a[3] = new Card(SPADE, FOUR);
  cards_a[4] = new Card(SPADE, THREE);

  cards_b[0] = new Card(SPADE, QUEEN);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests Flush Tie
TEST(RulesTest, CheckTieFlushLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Flush 
  cards_a[0] = new Card(SPADE, QUEEN);
  cards_a[1] = new Card(SPADE, EIGHT);
  cards_a[2] = new Card(SPADE, SIX);
  cards_a[3] = new Card(SPADE, FOUR);
  cards_a[4] = new Card(SPADE, THREE);

  cards_b[0] = new Card(SPADE, JACK);
  cards_b[1] = new Card(SPADE, EIGHT);
  cards_b[2] = new Card(SPADE, SIX);
  cards_b[3] = new Card(SPADE, FOUR);
  cards_b[4] = new Card(SPADE, THREE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests Straight Tie
TEST(RulesTest, CheckTieStraight) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Straight 
  cards_a[0] = new Card(SPADE, FIVE);
  cards_a[1] = new Card(CLUB, SIX);
  cards_a[2] = new Card(HEART, SEVEN);
  cards_a[3] = new Card(HEART, EIGHT);
  cards_a[4] = new Card(DIAMOND, NINE);

  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(CLUB, SIX);
  cards_b[2] = new Card(CLUB, SEVEN);
  cards_b[3] = new Card(DIAMOND, EIGHT);
  cards_b[4] = new Card(HEART, NINE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests Straight Tie
TEST(RulesTest, CheckTieStraightLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // Straight 
  cards_a[0] = new Card(SPADE, SIX);
  cards_a[1] = new Card(CLUB, SEVEN);
  cards_a[2] = new Card(HEART, EIGHT);
  cards_a[3] = new Card(HEART, NINE);
  cards_a[4] = new Card(DIAMOND, TEN);

  cards_b[0] = new Card(SPADE, FIVE);
  cards_b[1] = new Card(CLUB, SIX);
  cards_b[2] = new Card(CLUB, SEVEN);
  cards_b[3] = new Card(DIAMOND, EIGHT);
  cards_b[4] = new Card(HEART, NINE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests ThreeKind Tie
TEST(RulesTest, CheckTieThreeKind) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // ThreeKind 
  cards_a[0] = new Card(DIAMOND, JACK);
  cards_a[1] = new Card(SPADE, JACK);
  cards_a[2] = new Card(CLUB, JACK);
  cards_a[3] = new Card(DIAMOND, FIVE);
  cards_a[4] = new Card(SPADE, SIX);

  cards_b[0] = new Card(DIAMOND, JACK);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, JACK);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests ThreeKind Tie
TEST(RulesTest, CheckTieThreeKindLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // ThreeKind 
  cards_a[0] = new Card(DIAMOND, JACK);
  cards_a[1] = new Card(SPADE, JACK);
  cards_a[2] = new Card(CLUB, JACK);
  cards_a[3] = new Card(DIAMOND, FIVE);
  cards_a[4] = new Card(SPADE, SIX);

  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, FIVE);
  cards_b[4] = new Card(SPADE, SIX);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests TwoPair Tie
TEST(RulesTest, CheckTieTwoPair) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // TwoPair 
  cards_a[0] = new Card(DIAMOND, TEN);
  cards_a[1] = new Card(SPADE, TEN);
  cards_a[2] = new Card(CLUB, SIX);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, KING);

  cards_b[0] = new Card(DIAMOND, TEN);
  cards_b[1] = new Card(SPADE, TEN);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests TwoPair Tie
TEST(RulesTest, CheckTieTwoPairLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // TwoPair 
  cards_a[0] = new Card(DIAMOND, TEN);
  cards_a[1] = new Card(SPADE, TEN);
  cards_a[2] = new Card(CLUB, SIX);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, KING);

  cards_b[0] = new Card(DIAMOND, NINE);
  cards_b[1] = new Card(SPADE, NINE);
  cards_b[2] = new Card(CLUB, SIX);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, KING);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests OnePair Tie
TEST(RulesTest, CheckTieOnePair) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // OnePair 
  cards_a[0] = new Card(DIAMOND, ACE);
  cards_a[1] = new Card(SPADE, ACE);
  cards_a[2] = new Card(CLUB, EIGHT);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, TWO);

  cards_b[0] = new Card(DIAMOND, ACE);
  cards_b[1] = new Card(SPADE, ACE);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests OnePair Tie
TEST(RulesTest, CheckTieOnePairLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // OnePair 
  cards_a[0] = new Card(DIAMOND, ACE);
  cards_a[1] = new Card(SPADE, ACE);
  cards_a[2] = new Card(CLUB, EIGHT);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, TWO);

  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, KING);
  cards_b[2] = new Card(CLUB, EIGHT);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, TWO);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests HighCard Tie
TEST(RulesTest, CheckTieHighCard) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // HighCard 
  cards_a[0] = new Card(DIAMOND, KING);
  cards_a[1] = new Card(SPADE, JACK);
  cards_a[2] = new Card(CLUB, TEN);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, THREE);

  cards_b[0] = new Card(DIAMOND, KING);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(2, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(2, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}

// Tests HighCard Tie
TEST(RulesTest, CheckTieHighCardLesser) {
  RegularRules rules = RegularRules();
  Card *cards_a[HAND_SIZE];
  Card *cards_b[HAND_SIZE];
  Hand *hand_a;
  Hand *hand_b;

  // HighCard 
  cards_a[0] = new Card(DIAMOND, KING);
  cards_a[1] = new Card(SPADE, JACK);
  cards_a[2] = new Card(CLUB, TEN);
  cards_a[3] = new Card(DIAMOND, SIX);
  cards_a[4] = new Card(SPADE, THREE);

  cards_b[0] = new Card(DIAMOND, QUEEN);
  cards_b[1] = new Card(SPADE, JACK);
  cards_b[2] = new Card(CLUB, TEN);
  cards_b[3] = new Card(DIAMOND, SIX);
  cards_b[4] = new Card(SPADE, THREE);

  hand_a = rules.DetermineHand(cards_a);
  hand_b = rules.DetermineHand(cards_b);

  ASSERT_EQ(0, rules.CheckTie(*hand_a, *hand_b, hand_a->get_type()));
  ASSERT_EQ(1, rules.CheckTie(*hand_b, *hand_a, hand_b->get_type()));

  CleanTest(cards_a, hand_a);
  CleanTest(cards_b, hand_b);
}