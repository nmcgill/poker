// Created by: Nevan McGill (github.com/nmcgill) on 2014-09-17
// Card.h
// Contains the Card class. This is used to hold the Suit and Rank of a
// particular card. Cards are typically stored in the Dealer object.
// A card object should be allocated and freed by the Dealer class

#ifndef _CARD_
#define _CARD_

#include <ostream>
#include <istream>

enum Suit { CLUB, DIAMOND, HEART, SPADE, SUIT_COUNT };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN,
        KING, ACE, RANK_COUNT };

// Holds rank and suit. Handles standard in/out of the class. Sample usage:
//    Card* card_one = new Card(TWO, ACE);
//    Card* card_two = new Card(TWO, ACE);
//    if (card_one == card_two) {
//      cout << card_one << " and " << card_two << are equal. << endl;
//    }
class Card {
  friend std::istream &operator>>(std::istream &, Card &);
  friend class Dealer;
public:
  Card(Suit, Rank);
  Card() { suit_ = CLUB; rank_ = TWO; }
  Suit get_suit() const;
  Rank get_rank() const;
private:
  // Keeps trak of the cards suit.
  // Valid values are CLUB, DIAMOND, HEART, SPADE or 0 - 3
  Suit suit_;
  // Keep track of the card rank.
  // Valid values are TWO-TEN, JACK, QUEEN, KING, ACE or 0 - 13
  Rank rank_;
};

bool operator==(const Card &, const Card &);

// Note: output/input Card is formated <rank><suit>
std::ostream &operator<<(std::ostream &, const Card &);
std::istream &operator>>(std::istream &, Card &);

#endif
