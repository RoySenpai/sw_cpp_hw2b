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
#include <string>
using namespace std;

#include "card.hpp"

namespace ariel {
    Card::Card(Value value, Suit suit): value(value), suit(suit) {};

    string Card::toString() const {
        string svalue, ssuit;
        Suit suit = this->getSuit();
        Value value = this->getValue();

        switch (value)
        {
            case Ace:
                svalue = "Ace";
                break;
            case Jack:
                svalue = "Jack";
                break;
            case Queen:
                svalue = "Queen";
                break;
            case King:
                svalue = "King";
                break;
            default:
                svalue = to_string((int)value);
                break;
        }

        switch (suit)
        {
            case Clubs:
                ssuit = "Clubs";
                break;
            case Diamonds:
                ssuit = "Diamonds";
                break;
            case Hearts:
                ssuit = "Hearts";
                break;
            case Spades:
                ssuit = "Spades";
                break;
        }

        return (svalue + " of " + ssuit);
    }

    bool Card::operator<(const Card &rhs) const {
        if (this->value == Ace and rhs.value == Two)
            return true;

        else if (this->value > Two and rhs.value == Ace)
            return true;

        return (this->value < rhs.value);
    }
}