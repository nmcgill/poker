// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17

#include "player.h"
#include "gtest/gtest.h"

// Tests the players score getter
TEST(PlayerTest, HandType) {
  ComputerPlayer player = ComputerPlayer();

  EXPECT_EQ(0, player.get_score());

  player = ComputerPlayer(0, 2);

  EXPECT_EQ(2, player.get_score());
}

// Tests the player ID getter
TEST(PlayerTest, ID) {
  ComputerPlayer player = ComputerPlayer();

  EXPECT_EQ(0, player.get_id());

  player = ComputerPlayer(1);

  EXPECT_EQ(1, player.get_id());
}