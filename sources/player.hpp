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

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
        private:
            /* The player's name. */
            string name;

            /* The player's hand. */
            vector<Card> hand;

            /* The player's taken cards. */
            vector<Card> taken;

            /*
             * The player's inGame status.
             * True if the player is in a game, false otherwise.
             * Insures that a player can't be in more than one game at a time.
             * @note This is not a part of the player's state. 
            */
            bool inGame;

        public:
            /* Constructors & Destructors zone */

            /*
             * Constructor with a string argument.
             * Initializes the name to the given string.
             * @param name The player's name.
             * @note The default name is "Default Player".
             * @note The default constructor is not allowed.
             * @note The player's hand and taken cards are initialized to empty decks.
            */
            Player(string name = "Default Player");

            /* Getters&Setters zone */

            /*
             * Returns the number of cards in the player's hand.
             * @return The number of cards in the player's hand.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            size_t stacksize() const { 
                return this->hand.size(); 
            }

            /*
             * Returns the number of cards taken by the player.
             * @return The number of cards taken by the player.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            size_t cardesTaken() const { 
                return this->taken.size(); 
            }

            /*
             * Returns the last card in the player's hand.
             * @return The last card in the player's hand.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            const Card& getCard() const { 
                return this->hand.back();
            }

            /*
             * Returns the last card in the player's taken cards.
             * @return Last card in the player's taken cards.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            const Card& getTaken() const { 
                return this->taken.back();
            }


            /* 
             * Returns the player's name.
             * @return The player's name.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            string getName() const { 
                return this->name; 
            }

            /*
             * Returns the player's inGame status.
             * @return The player's inGame status.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            bool isInGame() const { 
                return this->inGame; 
            }

            /*
             * Sets the player's inGame status to the given status.
             * @param status The status to set the player's inGame status to.
             * @note The function is inline.
            */
            void setInGame(bool status) { 
                this->inGame = status; 
            }


            /* Adders&Removers zone */

            /*
             * Adds a card to the player's hand.
             * @param card The card to add to the player's hand.
             * @throw invalid_argument If the card is already in the player's hand.
             * @throw logic_error If the player is already in a game or 
             *                      if the player has 26 cards.
            */
            void addCard(Card& card);

            /*
             * Adds a card to the player's taken cards.
             * @param card The card to add to the player's taken cards.
             * @throw invalid_argument If the card is already in the player's taken cards.
             * @throw logic_error If the player is already in a game.
            */
            void addTaken(Card& card);

            /*
             * Removes the last card in the player's hand cards.
             * @note The function is inline.
            */
            void removeCard() { 
                this->hand.pop_back();
            }

            /*
             * Removes the last card in the player's taken cards.
             * @note The function is inline.
            */
            void removeTaken() { 
                this->taken.pop_back();
            }


            /* Operators overriding zone */

            /* 
             * Compare two players by their names.
             * @param rhs The player to compare to.
             * @return True if the players have the same name, false otherwise.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
             */
            bool operator==(const Player &rhs) const {
                return this->name == rhs.name;
            }

            /* Other methods zone */

            /*
             * Searches for the given card in the player's hand.
             * @param card The card to search for.
             * @return True if the player has the given card in his hand, false otherwise.
             * @note The function is const and can be called on a const object.
            */
            bool hasCard(Card card) const;

            /*
             * Searches for the given card in the player's taken cards.
             * @param card The card to search for.
             * @return True if the player has the given card in his taken cards, false otherwise.
             * @note The function is const and can be called on a const object.
            */
            bool hasTaken(Card card) const;

            /*
             * Returns a string representation of the player.
             * @return A string representation of the player.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            string toString() const {
                return "Player " + this->name + " has " + to_string(this->stacksize()) + " cards in hand and " + to_string(this->cardesTaken()) + " cards taken.";
            }
    };
}