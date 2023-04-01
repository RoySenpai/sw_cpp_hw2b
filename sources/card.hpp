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

using namespace std;

namespace ariel
{
    class Card
    {
        private:
            int value;
            char suit;

        public:
            // Constructor: Create a card with a value and a suit
            Card(int value, char suit)
            {
                this->value = value;
                this->suit = suit;
            };

            // Get the value of the card
            int getValue() const { return value; }

            // Get the suit of the card
            char getSuit() const { return suit; }

            // Compare two cards
            bool operator==(const Card &rhs) const { return value == rhs.value; }

            // Compare two cards (for sorting)
            bool operator<(const Card &rhs) const { return (value == 1 and rhs.value == 2) or (value > 2 and rhs.value < 3) or (value < rhs.value); }
    };
}
