/*
 *  Software Systems CPP Course Assignment 2
 *  Copyright (C) 2023  Roy Simanovich
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Initialization") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Test 2 - Playing 5 turns") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    for (int i=0;i<5;i++) {
        game.playTurn();
    }
    game.printLastTurn();
    CHECK(p1.stacksize() == 21);
    CHECK(p2.stacksize() == 21);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Test 3 - Game end (26 turns)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playAll();

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() == 26);
    CHECK(p2.cardesTaken() == 26);
}

TEST_CASE("Test 4 - Initialization logic (Same name)") {
    Player p1("Alice");

    CHECK_THROWS(Game {p1,p1});
}

TEST_CASE("Test 5 - Initialization logic (No name 1)") {
    Player p1("");
    Player p2("Alice");

    CHECK_THROWS(Game {p1,p2});
}

TEST_CASE("Test 6 - Initialization logic (No name 2)") {
    Player p1("Alice");
    Player p2("");

    CHECK_THROWS(Game {p1,p2});
}

TEST_CASE("Test 7 - Initialization logic (In game 1)") {
    Player p1("Alice");
    Player p2("");

    p1.setInGame(true);

    CHECK_THROWS(Game {p1,p2});
}

TEST_CASE("Test 8 - Initialization logic (In game 2)") {
    Player p1("Alice");
    Player p2("");

    p2.setInGame(true);

    CHECK_THROWS(Game {p1,p2});
}

TEST_CASE("Test 9 - Winning logic (Alice wins)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playAll();

    CHECK(p1.cardesTaken() == 26);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Test 10 - Winning logic (Bob wins)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playAll();

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 26);
}

TEST_CASE("Test 11 - Print last move (No turns)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK_THROWS(game.printLastTurn());
}

TEST_CASE("Test 12 - Print last move (1 turn)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playTurn();

    CHECK_NOTHROW(game.printLastTurn());
}

TEST_CASE("Test 13 - Print winner (Alice wins)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playAll();

    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Test 14 - Print winner (Bob wins)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playAll();

    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Test 15 - Print winner (No winner)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK_THROWS(game.printWiner());
}

TEST_CASE("Test 16 - Game logic (1 turn)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playTurn();

    CHECK((p1.stacksize() == 25 || p2.stacksize() == 25));
    CHECK((p2.cardesTaken() == 1 || p2.cardesTaken() == 1));
}

TEST_CASE("Test 17 - Play turn (not ingame)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    game.playAll();
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Test 18 - Play turn (not ingame 1)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    game.playAll();
    p2.setInGame(true);

    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Test 19 - Play turn (not ingame 2)") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    game.playAll();
    p1.setInGame(true);

    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Test 20 - No cards") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    game.playAll();
    p1.setInGame(true);
    p2.setInGame(true);

    CHECK_THROWS(game.playTurn());
}