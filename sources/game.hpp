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

#pragma once

#include <vector>
#include "card.hpp"
#include "player.hpp"

namespace ariel
{
    class Game
    {
        private:
            /* Reference to the first player. */
            Player& p1;

            /* Reference to the second player. */
            Player& p2;

            /* The winner of the game. */
            Player *winner;    

            /* The cards in the game. */
            vector<Card> cards;

            /* Temploary stack of cards of player 1 */
            vector<Card> p1Cards;

            /* Temploary stack of cards of player 2 */
            vector<Card> p2Cards;

            /* The last turn stats. */
            string lastTurnStats;

            /* The log of all the turns played. */
            string log;   

            /*
             * The current turn stats.
             * 0 means no turn has been played yet.
             * 1 means the first turn has been played. 2 means the second turn has been played and so on.
             * @note Max number of turns is 26.
            */
            unsigned int turn;

            /* The number of draws in the game. */
            unsigned int draws;

            /* The number of wins for player 1 */
            unsigned int p1Wins;

            /* The number of wins for player 2 */
            unsigned int p2Wins;

        public:
            /* Constuctors&Destructors zone */
            
            /* 
             * @brief A constructor for the Game class.
             * @param plr1 - The first player.
             * @param plr2 - The second player.
             * @throws invalid_argument if Player 1 and Player 2 are the same player
             *       or if Player 1 or Player 2 are already in a game.
            */
            Game(Player& plr1, Player& plr2);


            /* Other methods zone */

            /*
             * @brief Plays a single turn.
             * @throws logic_error if the game is over.
            */
            void playTurn();

            /* 
             * @brief Prints the last turn stats.
             * @throws logic_error if the game is over.
             * @note The stats are printed to the standard output.
             * @note The stats are printed in the following format:
             * @note <turn number>
             * @note <player 1 name> <player 1 card> <player 1 cards won>
             * @note <player 2 name> <player 2 card> <player 2 cards won>
             * @note <winner name> <winner cards won>
             * @note <draws in this turn>
            */
            void printLastTurn() const {
                cout << lastTurnStats << endl;
            }

            /*
             * @brief Plays the game until the end.
             * @throws logic_error if the game is over.
            */
            void playAll();

            /*
             * @brief Prints the name of the winning player.
             * @note The name is printed to the standard output.
            */
            void printWiner() const;

            /*
             * @brief Prints the log of all the turns played.
             * @note The log is printed to the standard output.
             * @note The log is printed in the same format as game.printLastTurn().
            */
            void printLog() const {
                cout << log << endl;
            }

            /*
             * @brief Prints the statistics of the game.
             * @note The statistics are printed to the standard output.
             * @note The statistics are printed in the following format:
             * @note Player <player 1 name> status:
             * @note Cards won: <player 1 cards won> <player 1 draws>
             * @note Cards left: <player 1 cards left>
             * @note Win rate: <player 1 win rate>%
             * @note Player <player 2 name> status:
             * @note Cards won: <player 2 cards won> <player 2 draws>
             * @note Cards left: <player 2 cards left>
             * @note Win rate: <player 2 win rate>%
             * @note Draws: <draws>
             * @note Draw rate: <draw rate>%
            */
            void printStats();
    };
}