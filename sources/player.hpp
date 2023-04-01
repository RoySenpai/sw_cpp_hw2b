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
using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;
            vector<Card> hand;
            vector<Card> taken;
            int sSize;
            int cTaken;
            bool inGame;

        public:
            int stacksize() const { return this->sSize; }

            int cardesTaken() const { return this->cTaken; }

            void setStackSize(int size) { this->sSize = size; }

            void setCardsTaken(int cards) { this->cTaken = cards; }

            void addCard(Card card) { this->hand.push_back(card); }

            void addTaken(Card card) { this->taken.push_back(card); }

            Card getCard(int index) { return this->hand[index]; }

            Card getTaken(int index) { return this->taken[index]; }

            void removeCard(int index) { this->hand.erase(this->hand.begin() + index); }

            void removeTaken(int index) { this->taken.erase(this->taken.begin() + index); }

            bool isInGame() const { return this->inGame; }

            void setInGame(bool status) { this->inGame = status; }

            string getName() { return this->name; }

            Player(string name);
    };
}