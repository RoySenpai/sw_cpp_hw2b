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

/* Enumerations */

/*  The value of the card (A, 2-10, J, Q or K). */
enum Value
{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

/* The suit of the card (Clubs, Diamonds, Hearts or Spades). */
enum Suit
{
    Clubs = 1,
    Diamonds,
    Hearts,
    Spades
};

using namespace std;

namespace ariel
{
    class Card
    {
        private:
            /* The value of the card (A, 2-10, J, Q or K). */
            Value value;

            /* The suit of the card (Clubs, Diamonds, Hearts or Spades). */
            Suit suit;

        public:
            /* Constructors&Destructors zone */

            /*
             * Constructor with two arguments.
             * Initializes the value and the suit of the card.
             * @param value The value of the card (A, 2-10, J, Q or K).
             * @param suit The suit of the card (Clubs, Diamonds, Hearts or Spades).
             * @note If no arguments are given, the default value is Ace of Clubs.
            */
            Card(Value value = Ace, Suit suit = Clubs);

            /* Getters zone */

            /* 
             * Get the value of the card.
             * @return The value of the card (A, 2-10, J, Q or K).
            */
            Value getValue() const {
                return value;
            }

            /* 
             * Get the suit of the card.
             * @return The suit of the card (Clubs, Diamonds, Hearts or Spades).
            */
            Suit getSuit() const {
                return suit;
            }


            /* Operators overriding zone */

            /*
             * Compare two cards (for equality).
             * @param rhs The other card to compare.
             * @return True if the cards are equal, false otherwise.
            */
            bool operator==(const Card &rhs) const {
                return value == rhs.value;
            }

            /* 
             * Compare two cards (for sorting).
             * @param rhs The other card to compare.
             * @return True if this card is smaller than the other, false otherwise.
            */
            bool operator<(const Card &rhs) const {
                return (value == Ace and rhs.value == Two) or (value > Two and rhs.value < Three) or (value < rhs.value);
            }

            /* Other methods zone */

            /*
             * A string representation of the card.
             * @return A string representation of the card.
             * @note The string representation is in the format: "VALUE of SUIT".
            */
            string toString() const;
    };
}
