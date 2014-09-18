// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17

#include "hand.h"
#include "gtest/gtest.h"

// Tests RoyalFlush equality
TEST(RoyalFlushTest, GreaterThan) {

  RoyalFlush hand_a = RoyalFlush();
  RoyalFlush hand_b = RoyalFlush();

  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests RoyalFlush hand type
TEST(RoyalFlushTest, HandType) {

  RoyalFlush hand = RoyalFlush();

  ASSERT_EQ(ROYALFLUSH, hand.get_type());
}

// Tests StraightFlush equality
TEST(StraightFlushTest, GreaterThan) {

  StraightFlush hand_a = StraightFlush(5);
  StraightFlush hand_b = StraightFlush(4);

  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests FourKind hand type
TEST(StraightFlushTest, HandType) {

  StraightFlush hand = StraightFlush(5);

  ASSERT_EQ(STRAIGHTFLUSH, hand.get_type());
}

// Tests FourKind equality
TEST(FourKindTest, GreaterThan) {

  FourKind hand_a = FourKind(5);
  FourKind hand_b = FourKind(4);

  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests FourKind hand type
TEST(FourKindTest, HandType) {

  FourKind hand = FourKind(5);

  ASSERT_EQ(FOURKIND, hand.get_type());
}

// Tests FullHouse equality
TEST(FullHouseTest, GreaterThan) {

  FullHouse hand_a = FullHouse(5);
  FullHouse hand_b = FullHouse(4);

  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests FullHouse hand type
TEST(FullHouseTest, HandType) {

  FullHouse hand = FullHouse(5);

  ASSERT_EQ(FULLHOUSE, hand.get_type());
}

// Tests Flush equality
TEST(FlushTest, GreaterThan) {

  Flush hand_a = Flush(2,4,6,8,10);

  // first highest rank
  Flush hand_b = Flush(2,4,6,8,11);

  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // second highest rank
  hand_b = Flush(2,4,6,9,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // third highest rank
  hand_b = Flush(2,4,7,8,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // fourth highest rank
  hand_b = Flush(2,5,6,8,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // fifth highest rank
  hand_b = Flush(3,4,6,8,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // tie
  hand_b = Flush(2,4,6,8,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests Flush hand type
TEST(FlushTest, HandType) {

  Flush hand = Flush(1,2,3,4,5);

  ASSERT_EQ(FLUSH, hand.get_type());
}

// Tests Straight equality
TEST(StraightTest, GreaterThan) {

  Straight hand_a = Straight(5);
  Straight hand_b = Straight(4);

  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests Straight hand type
TEST(StraightTest, HandType) {

  Straight hand = Straight(5);

  ASSERT_EQ(STRAIGHT, hand.get_type());
}

// Tests ThreeKind equality
TEST(ThreeKindTest, GreaterThan) {

  ThreeKind hand_a = ThreeKind(5);
  ThreeKind hand_b = ThreeKind(4);

  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests ThreeKind hand type
TEST(ThreeKindTest, HandType) {

  ThreeKind hand = ThreeKind(5);

  ASSERT_EQ(THREEKIND, hand.get_type());
}

// Tests TwoPair equality
TEST(TwoPairTest, GreaterThan) {

  TwoPair hand_a = TwoPair(4,2,6);
  TwoPair hand_b = TwoPair(3,2,6);

  // highest pair
  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // lowest pair
  hand_b = TwoPair(4,1,6);
  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // // side card
  hand_b = TwoPair(4,2,5);
  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests TwoPair hand type
TEST(TwoPairTest, HandType) {

  TwoPair hand = TwoPair(4,2,6);

  ASSERT_EQ(TWOPAIR, hand.get_type());
}

// Tests OnePair equality
TEST(OnePairTest, GreaterThan) {

  OnePair hand_a = OnePair(4,2,6,8);
  OnePair hand_b = OnePair(3,2,6,8);

  // highest pair
  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // 3rd highest
  hand_b = OnePair(4,1,6,8);
  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // 4th highest card
  hand_b = OnePair(4,2,5,8);
  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // 5th highest card
  hand_b = OnePair(4,2,6,7);
  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests OnePair hand type
TEST(OnePairTest, HandType) {

  OnePair hand = OnePair(4,2,6,8);

  ASSERT_EQ(ONEPAIR, hand.get_type());
}

// Tests HighCard equality
TEST(HighCardTest, GreaterThan) {

  HighCard hand_a = HighCard(5);
  HighCard hand_b = HighCard(4);

  ASSERT_EQ(true, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}

// Tests HighCard equality
TEST(HighCardTest, GreaterThan) {

  HighCard hand_a = Flush(2,4,6,8,10);

  // first highest rank
  HighCard hand_b = Flush(2,4,6,8,11);

  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // second highest rank
  hand_b = Flush(2,4,6,9,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // third highest rank
  hand_b = Flush(2,4,7,8,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // fourth highest rank
  hand_b = Flush(2,5,6,8,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // fifth highest rank
  hand_b = Flush(3,4,6,8,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(true, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);

  // tie
  hand_b = Flush(2,4,6,8,10);
  ASSERT_EQ(false, hand_a > hand_b);
  ASSERT_EQ(false, hand_b > hand_a);
  ASSERT_EQ(false, hand_b > hand_b);
}