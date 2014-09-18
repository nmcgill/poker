// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17

#include "dealer.h"
#include "rules.h"
#include "card.h"
#include "player.h"

#include "gtest/gtest.h"

class DealerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    dealer = new Dealer();
  }

  virtual void TearDown() {
    delete dealer;
  }

  Dealer *dealer;
};

// Tests the Deal function.
TEST_F(DealerTest, Deal) {
  Card **hand_a = dealer->get_player_hand(0);
  Card **hand_b = dealer->get_player_hand(1);
   
  for (int i = 0; i < HAND_SIZE; i++) {
    ASSERT_TRUE(hand_a[i] == NULL);
  }

  for (int i = 0; i < HAND_SIZE; i++) {
    ASSERT_TRUE(hand_b[i] == NULL);
  }

  dealer->Deal();

  for (int i = 0; i < HAND_SIZE; i++) {
    ASSERT_TRUE(hand_a[i] != NULL);
  }

  for (int i = 0; i < HAND_SIZE; i++) {
    ASSERT_TRUE(hand_b[i] != NULL);
  }
}

// Tests Shuffle
// Shuffle is called by Deal
// Cannot happen 100% of the time, so make this an expected value
TEST_F(DealerTest, Shuffle) {
   dealer->Deal();
   Card *card_a = (dealer->get_player_hand(0))[0];

   dealer->Deal();
   Card *card_b = (dealer->get_player_hand(0))[0];

   EXPECT_TRUE(card_a != card_b);
}

// Tests the card position
TEST_F(DealerTest, CardPosition) {
   dealer->Deal();
   Card *card_a = (dealer->get_player_hand(0))[0];

   Card card = Card(card_a->get_suit(), card_a->get_rank());

   ASSERT_TRUE(dealer->CardPosition(card) == dealer->CardPosition(*card_a));
}