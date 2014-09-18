Poker
=======
Version 1.0 by Nevan McGill

Currently supports 2 player games. Comparing two 5-card poker hands and determining the outcome. Rules are written based on [http://en.wikipedia.org/wiki/List_of_poker_hands](http://en.wikipedia.org/wiki/List_of_poker_hands)

Requirements
=======
The follow instructions were performed on a Linux Platform. These are the base requirements to build and use Poker:

* GNU-compatible Make

* POSIX-standard shell

* A C++98-standard-compliant compiler

Instructions
=======
${POKER_DIR} is the main Poker directory
##### Poker (Normal Build)

1) To build the main poker source run: ${POKER_DIR}/make

2) To run poker type: ${POKER_DIR}/poker

*__Note__*: The dealer will automatically deal the cards.

    Usage: poker < seed > where seed seeds the random number function

##### Poker (Debug Build)
The debug build is used to manually input each player's hand.

1) First edit and insert "#define DEBUG" inside of main.cpp

2) To build the main poker source run: ${POKER_DIR}/make

3) To run poker type: ${POKER_DIR}/poker

*__Note__*: You will need to manually input each player's hand.

    Usage: poker card1 card2 card3 card4 card5 card6 card7 card8 card9 card10
    Card syntax: <suit><rank>
    Valid Suits: C, D, H, S
    Valid Ranks: 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A

Unit Tests (uses Google Test Framework)
=======

##### Building the Unit Tests

1) Navigate to the ${POKER_DIR}/gtest/make/ directory

2) Type: make

3) This will build: card\_unittest, dealer\_unittest, hand\_unittest, player\_unittest, and rules\_unittest

##### Run the Unit Tests

1) To run a particular unit test type: ./hand\_unittest (for example)

*__Note__*: There are currently .txt files inside ${POKER_DIR} which have the most recent outputs of each unit test.

##### Continuous Build

Google Test works well with Hudson and can also be used to analyze code coverage of the unit tests.

License
=======

    Copyright 2014 Nevan McGill

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or 
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.