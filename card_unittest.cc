// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17

#include "card.h"
#include "gtest/gtest.h"

// Tests the a cards suit value.
TEST(CardTest, Suit) {
  Card card(HEART, ACE);
  EXPECT_EQ(HEART, card.get_suit());

  card = Card(SPADE, TWO);
  EXPECT_EQ(SPADE, card.get_suit());
}

// Tests the a cards rank value.
TEST(CardTest, Rank) {
  Card card(HEART, ACE);
  EXPECT_EQ(ACE, card.get_rank());

  card = Card(SPADE, TWO);
  EXPECT_EQ(TWO, card.get_rank());
}

// Tests if cards are equal
TEST(CardTest, Equal) {
  Card card_a(HEART, ACE);
  Card card_b(HEART, ACE);
  Card card_c(HEART, TWO);
  Card card_d(SPADE, TWO);


  ASSERT_TRUE(card_a == card_b);
  ASSERT_FALSE(card_b == card_c);
  ASSERT_FALSE(card_c == card_d);
}