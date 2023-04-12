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

#include "player.hpp"

namespace ariel {
    Player::Player(string name): name(name), takenCards(0), inGame(false) {};

    bool Player::hasCard(Card card) const {
        for (size_t i = 0; i < this->stacksize(); ++i)
        {
            Card t = this->hand.at(i);

            if (t.getSuit() == card.getSuit() && t.getValue() == card.getValue())
                return true;
        }

        return false;
    }

    void Player::addCard(Card& card) { 
        if (this->hasCard(card))
            throw invalid_argument("Player already has this card!");

        this->hand.push_back(card); 
    }
}