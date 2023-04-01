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
    ostream &operator<<(ostream &stream, Card const &v) {
        string svalue, ssuit;

        switch (v.getValue())
        {
            case 0:
                svalue = "Ace";
                break;
            case 10:
                svalue = "Jack";
                break;
            case 11:
                svalue = "Queen";
                break;
            case 12:
                svalue = "King";
                break;
            default:
                svalue = to_string(v.getValue());
                break;
        }

        switch (v.getSuit())
        {
            case 'C':
                ssuit = "Clubs";
                break;
            case 'D':
                ssuit = "Diamonds";
                break;
            case 'H':
                ssuit = "Hearts";
                break;
            case 'S':
                ssuit = "Spades";
                break;
            default:
                ssuit = "Unknown";
                break;
        }

        stream << svalue << "of " << ssuit;

        return stream;
    }
}