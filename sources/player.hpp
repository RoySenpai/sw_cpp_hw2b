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
            vector<Card>* hand;

            /* The player's taken cards. */
            vector<Card>* taken;

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

            /*
             * Copy constructor.
             * Initializes the name and inGame to the values of the other player.
             * @param other The player to copy.
             * @note The default copy constructor is not allowed.
             * @note The player's hand and taken cards are copied.
            */
            Player(const Player& other);

            /*
             * Destructor.
             * Deletes the player's hand and taken cards.
             * @note The default destructor is not allowed.
             * @note The player's name and inGame status are not deleted.
            */
            ~Player();

            /* Getters&Setters zone */

            /*
             * Returns the number of cards in the player's hand.
             * @return The number of cards in the player's hand.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            size_t stacksize() const { 
                return this->hand->size(); 
            }

            /*
             * Returns the number of cards taken by the player.
             * @return The number of cards taken by the player.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            size_t cardesTaken() const { 
                return this->taken->size(); 
            }

            /*
             * Returns the card in the player's hand at the given index.
             * @param index The index of the card in the player's hand.
             * @return The card in the player's hand at the given index.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            Card getCard(int index) const { 
                return this->hand->at(index); 
            }

            /*
             * Returns the card in the player's taken cards at the given index.
             * @param index The index of the card in the player's taken cards.
             * @return The card in the player's taken cards at the given index.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            Card getTaken(int index) const { 
                return this->taken->at(index); 
            }

            /*
             * Returns the player's index of the given card in his hand.
             * @param card The card to search for.
             * @return The player's index of the given card in his hand.
             * @throw out_of_range If the card is not in the player's hand.
             * @note The function is const and can be called on a const object.
            */
            int getCardIndex(Card card) const;

            /*
             * Returns the player's index of the given card in his taken cards.
             * @param card The card to search for.
             * @return The player's index of the given card in his taken cards.
             * @throw out_of_range If the card is not in the player's taken cards.
             * @note The function is const and can be called on a const object.
            */
            int getTakenIndex(Card card) const;

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
            void addCard(Card card);

            /*
             * Adds a card to the player's taken cards.
             * @param card The card to add to the player's taken cards.
             * @throw invalid_argument If the card is already in the player's taken cards.
             * @throw logic_error If the player is already in a game.
            */
            void addTaken(Card card);

            /*
             * Removes the card in the player's hand at the given index.
             * @param index The index of the card to remove.
             * @note The function is inline.
            */
            void removeCard(int index) { 
                this->hand->erase(this->hand->begin() + index); 
            }

            /* 
             * Removes the given card from the player's hand.
             * @param card The card to remove.
             * @throw invalid_argument If the card is not in the player's hand.
             * @throw logic_error If the player is not in a game.
            */
            void removeCard(Card card);

            /*
             * Removes the card in the player's taken cards at the given index.
             * @param index The index of the card to remove.
             * @note The function is inline.
            */
            void removeTaken(int index) { 
                this->taken->erase(this->taken->begin() + index);
            }

            /*
             * Removes the given card from the player's taken cards.
             * @param card The card to remove.
             * @throw invalid_argument If the card is not in the player's taken cards.
             * @throw logic_error If the player is not in a game.
            */
            void removeTaken(Card card);



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
             * Returns the player's inGame status.
             * @return The player's inGame status.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            bool isInGame() const { 
                return this->inGame; 
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
             * Returns a string representation of the player's hand.
             * @return A string representation of the player's hand.
             * @note The function is const and can be called on a const object.
            */
            string getHand() const;

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